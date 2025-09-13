#include "stdafx.h"
#include "../../common/billing.h"
#include "config.h"
#include "desc_client.h"
#include "desc_manager.h"
#include "char.h"
#include "char_manager.h"
#include "p2p.h"
#include "guild.h"
#include "guild_manager.h"
#include "party.h"
#include "messenger_manager.h"
#include "empire_text_convert.h"
#include "unique_item.h"
#include "xmas_event.h"
#include "affect.h"
#include "dev_log.h"
#include "locale_service.h"
#include "questmanager.h"
#include "skill.h"

/* - CLIENT_LOCALE_STRING ------------------------------ */
#include "buffer_manager.h"
/* ----------------------------------------------------- */

////////////////////////////////////////////////////////////////////////////////
// Input Processor
CInputP2P::CInputP2P()
{
    BindPacketInfo(&m_packetInfoGG);
}

void CInputP2P::Login(LPDESC d, const char* c_pData)
{
    P2P_MANAGER::instance().Login(d, (TPacketGGLogin*) c_pData);
}

void CInputP2P::Logout(LPDESC d, const char* c_pData)
{
    auto * p = (TPacketGGLogout*) c_pData;
    P2P_MANAGER::instance().Logout(p->szName);
}

int CInputP2P::Relay(LPDESC d, const char* c_pData, size_t uiBytes)
{
    auto * p = (TPacketGGRelay*) c_pData;

    if (uiBytes < sizeof(TPacketGGRelay) + p->lSize)
    {
        return -1;
    }

    if (p->lSize < 0)
    {
        sys_err("invalid packet length %d", p->lSize);
        d->SetPhase(PHASE_CLOSE);
        return -1;
    }

    sys_log(0, "InputP2P::Relay : %s size %d", p->szName, p->lSize);

    LPCHARACTER pkChr = CHARACTER_MANAGER::instance().FindPC(p->szName);

    const auto* c_pbData = (const BYTE*)(c_pData + sizeof(TPacketGGRelay));

    if (!pkChr)
    {
        return p->lSize;
    }

    if (*c_pbData == HEADER_GC_WHISPER)
    {
        if (pkChr->IsBlockMode(BLOCK_WHISPER))
        {
            // 귓속말 거부 상태에서 귓속말 거부.
            return p->lSize;
        }

        char buf[1024];
        memcpy(buf, c_pbData, MIN(p->lSize, sizeof(buf)));

        auto* p2 = (TPacketGCWhisper*) buf;
        // bType 상위 4비트: Empire 번호
        // bType 하위 4비트: EWhisperType
        BYTE bToEmpire = (p2->bType >> 4);
        p2->bType = p2->bType & 0x0F;
        if (p2->bType == 0x0F)
        {
            // 시스템 메세지 귓속말은 bType의 상위비트까지 모두 사용함.
            p2->bType = WHISPER_TYPE_SYSTEM;
        }
        else
        {
            if (!pkChr->IsEquipUniqueGroup(UNIQUE_GROUP_RING_OF_LANGUAGE))
                if (bToEmpire >= 1 && bToEmpire <= 3 && pkChr->GetEmpire() != bToEmpire)
                {
                    ConvertEmpireText(bToEmpire,
                                      buf + sizeof(TPacketGCWhisper),
                                      p2->wSize - sizeof(TPacketGCWhisper),
                                      10 + 2 * pkChr->GetSkillPower(SKILL_LANGUAGE1 + bToEmpire - 1));
                }
        }

        pkChr->GetDesc()->Packet(buf, p->lSize);
    }
    else
    {
        pkChr->GetDesc()->Packet(c_pbData, p->lSize);
    }

    return (p->lSize);
}

int CInputP2P::Notice(LPDESC d, const char* c_pData, size_t uiBytes)
{
    auto * p = (TPacketGGNotice*) c_pData;

    if (uiBytes < sizeof(TPacketGGNotice) + p->lSize)
    {
        return -1;
    }

    if (p->lSize < 0)
    {
        sys_err("invalid packet length %d", p->lSize);
        d->SetPhase(PHASE_CLOSE);
        return -1;
    }

    char szBuf[256 + 1];
    strlcpy(szBuf, c_pData + sizeof(TPacketGGNotice), MIN(p->lSize + 1, sizeof(szBuf)));
    SendNotice(szBuf);
    return (p->lSize);
}

int CInputP2P::Guild(LPDESC d, const char* c_pData, size_t uiBytes)
{
    TPacketGGGuild * p = (TPacketGGGuild*) c_pData;
    uiBytes -= sizeof(TPacketGGGuild);
    c_pData += sizeof(TPacketGGGuild);

    CGuild * g = CGuildManager::instance().FindGuild(p->dwGuild);

    switch (p->bSubHeader)
    {
        case GUILD_SUBHEADER_GG_CHAT:
        {
            if (uiBytes < sizeof(TPacketGGGuildChat))
            {
                return -1;
            }

            auto * p = (TPacketGGGuildChat*) c_pData;

            if (g)
            {
                g->P2PChat(p->szText);
            }

            return sizeof(TPacketGGGuildChat);
        }

        case GUILD_SUBHEADER_GG_SET_MEMBER_COUNT_BONUS:
        {
            if (uiBytes < sizeof(int))
            {
                return -1;
            }

            int iBonus = * ((int*) c_pData);
            if (CGuild* pGuild = CGuildManager::instance().FindGuild(p->dwGuild))
            {
                pGuild->SetMemberCountBonus(iBonus);
            }
            return sizeof(int);
        }
        default:
            sys_err("UNKNOWN GUILD SUB PACKET");
            break;
    }
    return 0;
}


struct FuncShout
{
    const char* m_str;
    BYTE m_bEmpire;

    /* - CLIENT_LOCALE_STRING ------------------------------
    m_bCanFormat
    */
    bool m_bCanFormat;
    FuncShout(const char* str, BYTE bEmpire, bool bCanFormat) : m_str(str), m_bEmpire(bEmpire), m_bCanFormat(bCanFormat)
        /* ----------------------------------------------------- */
    {
    }

    void operator()(LPDESC d)
    {
        if (!d->GetCharacter() || (d->GetCharacter()->GetGMLevel() == GM_PLAYER && d->GetEmpire() != m_bEmpire))
        {
            return;
        }

        /* - CLIENT_LOCALE_STRING ------------------------------ */
        struct packet_chat pack_chat;
        pack_chat.header = HEADER_GC_CHAT;
        pack_chat.size = sizeof(struct packet_chat) + strlen(m_str);
        pack_chat.type = CHAT_TYPE_SHOUT;
        pack_chat.id = 0;
        pack_chat.bEmpire = m_bEmpire;
        pack_chat.bCanFormat = m_bCanFormat;

        TEMP_BUFFER buf;
        buf.write(&pack_chat, sizeof(struct packet_chat));
        buf.write(m_str, strlen(m_str));

        d->Packet(buf.read_peek(), buf.size());

        if (test_server)
        {
            sys_log(0, "SEND_COMMAND %s %s", d->GetCharacter()->GetName(), m_str);
        }
        /* ----------------------------------------------------- */
    }
};

/* - CLIENT_LOCALE_STRING ------------------------------
bCanFormat
*/
void SendShout(const char* szText, BYTE bEmpire, bool bCanFormat)
/* ----------------------------------------------------- */
{
    const DESC_MANAGER::DESC_SET & c_ref_set = DESC_MANAGER::instance().GetClientSet();

    /* - CLIENT_LOCALE_STRING ------------------------------
    bCanFormat
    */
    std::ranges::for_each(c_ref_set, FuncShout(szText, bEmpire, bCanFormat));
    /* ----------------------------------------------------- */
}

void CInputP2P::Shout(const char* c_pData)
{
    auto * p = (TPacketGGShout*) c_pData;

    /* - CLIENT_LOCALE_STRING ------------------------------
    bCanFormat
    */
    SendShout(p->szText, p->bEmpire, p->bCanFormat);
    /* ----------------------------------------------------- */
}

void CInputP2P::Disconnect(const char* c_pData)
{
    auto * p = (TPacketGGDisconnect*) c_pData;

    LPDESC d = DESC_MANAGER::instance().FindByLoginName(p->szLogin);

    if (!d)
    {
        return;
    }

    if (!d->GetCharacter())
    {
        d->SetPhase(PHASE_CLOSE);
    }
    else
    {
        d->DisconnectOfSameLogin();
    }
}

void CInputP2P::Setup(LPDESC d, const char* c_pData)
{
    auto * p = (TPacketGGSetup*) c_pData;
    sys_log(0, "P2P: Setup %s:%d", d->GetHostName(), p->wPort);
    d->SetP2P(d->GetHostName(), p->wPort, p->bChannel);
}

void CInputP2P::MessengerAdd(const char* c_pData)
{
    auto * p = (TPacketGGMessenger*) c_pData;
    sys_log(0, "P2P: Messenger Add %s %s", p->szAccount, p->szCompanion);
    MessengerManager::instance().__AddToList(p->szAccount, p->szCompanion);
}

void CInputP2P::MessengerRemove(const char* c_pData)
{
    auto * p = (TPacketGGMessenger*) c_pData;
    sys_log(0, "P2P: Messenger Remove %s %s", p->szAccount, p->szCompanion);
    MessengerManager::instance().__RemoveFromList(p->szAccount, p->szCompanion);
}

void CInputP2P::FindPosition(LPDESC d, const char* c_pData)
{
    auto* p = (TPacketGGFindPosition*) c_pData;
    LPCHARACTER ch = CHARACTER_MANAGER::instance().FindByPID(p->dwTargetPID);
    if (ch && ch->GetMapIndex() < 10000)
    {
        TPacketGGWarpCharacter pw;
        pw.header = HEADER_GG_WARP_CHARACTER;
        pw.pid = p->dwFromPID;
        pw.x = ch->GetX();
        pw.y = ch->GetY();
        d->Packet(&pw, sizeof(pw));
    }
}

void CInputP2P::WarpCharacter(const char* c_pData)
{
    auto* p = (TPacketGGWarpCharacter*) c_pData;
    LPCHARACTER ch = CHARACTER_MANAGER::instance().FindByPID(p->pid);
    if (ch)
    {
        ch->WarpSet(p->x, p->y);
    }
}

void CInputP2P::GuildWarZoneMapIndex(const char* c_pData)
{
    auto * p = (TPacketGGGuildWarMapIndex*) c_pData;
    CGuildManager & gm = CGuildManager::instance();

    sys_log(0, "P2P: GuildWarZoneMapIndex g1(%u) vs g2(%u), mapIndex(%d)", p->dwGuildID1, p->dwGuildID2, p->lMapIndex);

    CGuild * g1 = gm.FindGuild(p->dwGuildID1);
    CGuild * g2 = gm.FindGuild(p->dwGuildID2);

    if (g1 && g2)
    {
        g1->SetGuildWarMapIndex(p->dwGuildID2, p->lMapIndex);
        g2->SetGuildWarMapIndex(p->dwGuildID1, p->lMapIndex);
    }
}

void CInputP2P::Transfer(const char* c_pData)
{
    auto * p = (TPacketGGTransfer*) c_pData;

    LPCHARACTER ch = CHARACTER_MANAGER::instance().FindPC(p->szName);

    if (ch)
    {
        ch->WarpSet(p->lX, p->lY);
    }
}

void CInputP2P::XmasWarpSanta(const char* c_pData)
{
    auto * p = (TPacketGGXmasWarpSanta*) c_pData;

    if (p->bChannel == g_bChannel && map_allow_find(p->lMapIndex))
    {
        int iNextSpawnDelay = 60;

        if (LC_IsYMIR())
        {
            iNextSpawnDelay = 20 * 60;
        }
        else
        {
            iNextSpawnDelay = 50 * 60;
        }

        xmas::SpawnSanta(p->lMapIndex, iNextSpawnDelay);  // 50분있다가 새로운 산타가 나타남 (한국은 20분)

        TPacketGGXmasWarpSantaReply pack_reply;
        pack_reply.bHeader = HEADER_GG_XMAS_WARP_SANTA_REPLY;
        pack_reply.bChannel = g_bChannel;
        P2P_MANAGER::instance().Send(&pack_reply, sizeof(pack_reply));
    }
}

void CInputP2P::XmasWarpSantaReply(const char* c_pData)
{
    auto* p = (TPacketGGXmasWarpSantaReply*) c_pData;

    if (p->bChannel == g_bChannel)
    {
        CharacterVectorInteractor i;

        if (CHARACTER_MANAGER::instance().GetCharactersByRaceNum(xmas::MOB_SANTA_VNUM, i))
        {
            auto it = i.begin();

            while (it != i.end())
            {
                M2_DESTROY_CHARACTER(*it++);
            }
        }
    }
}

void CInputP2P::LoginPing(LPDESC d, const char* c_pData)
{
    auto * p = (TPacketGGLoginPing*) c_pData;

    SendBillingExpire(p->szLogin, BILLING_DAY, 0, nullptr);

    if (!g_pkAuthMasterDesc) // If I am master, I have to broadcast
    {
        P2P_MANAGER::instance().Send(p, sizeof(TPacketGGLoginPing), d);
    }
}

// BLOCK_CHAT
void CInputP2P::BlockChat(const char* c_pData)
{
    auto * p = (TPacketGGBlockChat*) c_pData;

    LPCHARACTER ch = CHARACTER_MANAGER::instance().FindPC(p->szName);

    if (ch)
    {
        sys_log(0, "BLOCK CHAT apply name %s dur %d", p->szName, p->lBlockDuration);
        ch->AddAffect(AFFECT_BLOCK_CHAT, POINT_NONE, 0, AFF_NONE, p->lBlockDuration, 0, true);
    }
    else
    {
        sys_log(0, "BLOCK CHAT fail name %s dur %d", p->szName, p->lBlockDuration);
    }
}
// END_OF_BLOCK_CHAT
//

void CInputP2P::IamAwake(LPDESC d, const char* c_pData)
{
    std::string hostNames;
    P2P_MANAGER::instance().GetP2PHostNames(hostNames);
    sys_log(0, "P2P Awakeness check from %s. My P2P connection number is %d. and details...\n%s", d->GetHostName(), P2P_MANAGER::instance().GetDescCount(), hostNames.c_str());
}

int CInputP2P::Analyze(LPDESC d, BYTE bHeader, const char* c_pData)
{
    if (test_server)
    {
        sys_log(0, "CInputP2P::Anlayze[Header %d]", bHeader);
    }

    int iExtraLen = 0;

    switch (bHeader)
    {
        case HEADER_GG_SETUP:
            Setup(d, c_pData);
            break;

        case HEADER_GG_LOGIN:
            Login(d, c_pData);
            break;

        case HEADER_GG_LOGOUT:
            Logout(d, c_pData);
            break;

        case HEADER_GG_RELAY:
            if ((iExtraLen = Relay(d, c_pData, m_iBufferLeft)) < 0)
            {
                return -1;
            }
            break;

        case HEADER_GG_NOTICE:
            if ((iExtraLen = Notice(d, c_pData, m_iBufferLeft)) < 0)
            {
                return -1;
            }
            break;

        case HEADER_GG_SHUTDOWN:
            sys_err("Accept shutdown p2p command from %s.", d->GetHostName());
            Shutdown(10);
            break;

        case HEADER_GG_GUILD:
            if ((iExtraLen = Guild(d, c_pData, m_iBufferLeft)) < 0)
            {
                return -1;
            }
            break;

        case HEADER_GG_SHOUT:
            Shout(c_pData);
            break;

        case HEADER_GG_DISCONNECT:
            Disconnect(c_pData);
            break;

        case HEADER_GG_MESSENGER_ADD:
            MessengerAdd(c_pData);
            break;

        case HEADER_GG_MESSENGER_REMOVE:
            MessengerRemove(c_pData);
            break;

        case HEADER_GG_FIND_POSITION:
            FindPosition(d, c_pData);
            break;

        case HEADER_GG_WARP_CHARACTER:
            WarpCharacter(c_pData);
            break;

        case HEADER_GG_GUILD_WAR_ZONE_MAP_INDEX:
            GuildWarZoneMapIndex(c_pData);
            break;

        case HEADER_GG_TRANSFER:
            Transfer(c_pData);
            break;

        case HEADER_GG_XMAS_WARP_SANTA:
            XmasWarpSanta(c_pData);
            break;

        case HEADER_GG_XMAS_WARP_SANTA_REPLY:
            XmasWarpSantaReply(c_pData);
            break;

        case HEADER_GG_RELOAD_CRC_LIST:
            LoadValidCRCList();
            break;

        case HEADER_GG_CHECK_CLIENT_VERSION:
            CheckClientVersion();
            break;

        case HEADER_GG_LOGIN_PING:
            LoginPing(d, c_pData);
            break;

        case HEADER_GG_BLOCK_CHAT:
            BlockChat(c_pData);
            break;

        case HEADER_GG_CHECK_AWAKENESS:
            IamAwake(d, c_pData);
            break;
    }

    return iExtraLen;
}

