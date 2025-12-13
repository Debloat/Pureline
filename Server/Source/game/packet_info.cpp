#include "stdafx.h"
#include "../../common/stl.h"
#include "constants.h"
#include "packet_info.h"

CPacketInfo::CPacketInfo()
    : m_pCurrentPacket(nullptr), m_dwStartTime(0)
{
}

CPacketInfo::~CPacketInfo()
{
    auto it = m_pPacketMap.begin();
    for (; it != m_pPacketMap.end(); ++it)
    {
        M2_DELETE(it->second);
    }
}

void CPacketInfo::Set(int header, int iSize, const char* c_pszName)
{
    if (m_pPacketMap.contains(header))
    {
        return;
    }

    auto * element = M2_NEW TPacketElement;

    element->iSize = iSize;
    element->stName.assign(c_pszName);
    element->iCalled = 0;
    element->dwLoad = 0;

    m_pPacketMap.insert(std::map<int, TPacketElement*>::value_type(header, element));
}

bool CPacketInfo::Get(int header, int* size, const char** c_ppszName)
{
    std::map<int, TPacketElement*>::iterator it = m_pPacketMap.find(header);

    if (it == m_pPacketMap.end())
    {
        return false;
    }

    *size = it->second->iSize;
    *c_ppszName = it->second->stName.c_str();

    m_pCurrentPacket = it->second;
    return true;
}

TPacketElement* CPacketInfo::GetElement(int header)
{
    std::map<int, TPacketElement*>::iterator it = m_pPacketMap.find(header);

    if (it == m_pPacketMap.end())
    {
        return NULL;
    }

    return it->second;
}

void CPacketInfo::Start()
{
    assert(m_pCurrentPacket != NULL);
    m_dwStartTime = get_dword_time();
}

void CPacketInfo::End()
{
    ++m_pCurrentPacket->iCalled;
    m_pCurrentPacket->dwLoad += get_dword_time() - m_dwStartTime;
}

void CPacketInfo::Log(const char* c_pszFileName)
{
    FILE * fp;

    fp = fopen(c_pszFileName, "w");

    if (!fp)
    {
        return;
    }

    auto it = m_pPacketMap.begin();

    fprintf(fp, "Name             Called     Load       Ratio\n");

    while (it != m_pPacketMap.end())
    {
        TPacketElement * p = it->second;
        ++it;

        fprintf(fp, "%-16s %-10d %-10u %.2f\n",
                p->stName.c_str(),
                p->iCalled,
                p->dwLoad,
                p->iCalled != 0 ? (float) p->dwLoad / p->iCalled : 0.0f);
    }

    fclose(fp);
}
///---------------------------------------------------------

CPacketInfoCG::CPacketInfoCG()
{
    Set(HEADER_CG_TEXT, sizeof(TPacketCGText), "Text");
    Set(HEADER_CG_HANDSHAKE, sizeof(TPacketCGHandshake), "Handshake");
    Set(HEADER_CG_TIME_SYNC, sizeof(TPacketCGHandshake), "TimeSync");
    Set(HEADER_CG_MARK_LOGIN, sizeof(TPacketCGMarkLogin), "MarkLogin");
    Set(HEADER_CG_MARK_IDXLIST, sizeof(TPacketCGMarkIDXList), "MarkIdxList");
    Set(HEADER_CG_MARK_CRCLIST, sizeof(TPacketCGMarkCRCList), "MarkCrcList");
    Set(HEADER_CG_MARK_UPLOAD, sizeof(TPacketCGMarkUpload), "MarkUpload");
    #ifdef _IMPROVED_PACKET_ENCRYPTION_
    Set(HEADER_CG_KEY_AGREEMENT, sizeof(TPacketKeyAgreement), "KeyAgreement");
    #endif

    Set(HEADER_CG_GUILD_SYMBOL_UPLOAD, sizeof(TPacketCGGuildSymbolUpload), "SymbolUpload");
    Set(HEADER_CG_SYMBOL_CRC, sizeof(TPacketCGSymbolCRC), "SymbolCRC");
    Set(HEADER_CG_LOGIN, sizeof(TPacketCGLogin), "Login");
    Set(HEADER_CG_LOGIN2, sizeof(TPacketCGLogin2), "Login2");
    Set(HEADER_CG_LOGIN3, sizeof(TPacketCGLogin3), "Login3");
    Set(HEADER_CG_ATTACK, sizeof(TPacketCGAttack), "Attack");
    Set(HEADER_CG_CHAT, sizeof(TPacketCGChat), "Chat");
    Set(HEADER_CG_WHISPER, sizeof(TPacketCGWhisper), "Whisper");

    Set(HEADER_CG_CHARACTER_SELECT, sizeof(TPacketCGPlayerSelect), "Select");
    Set(HEADER_CG_CHARACTER_CREATE, sizeof(TPacketCGPlayerCreate), "Create");
    Set(HEADER_CG_CHARACTER_DELETE, sizeof(TPacketCGPlayerDelete), "Delete");
    Set(HEADER_CG_ENTERGAME, sizeof(TPacketCGEnterGame), "EnterGame");

    Set(HEADER_CG_ITEM_USE, sizeof(TPacketCGItemUse), "ItemUse");
    Set(HEADER_CG_ITEM_DROP, sizeof(TPacketCGItemDrop), "ItemDrop");
    Set(HEADER_CG_ITEM_DROP2, sizeof(TPacketCGItemDrop2), "ItemDrop2");
    Set(HEADER_CG_ITEM_MOVE, sizeof(TPacketCGItemMove), "ItemMove");
    Set(HEADER_CG_ITEM_PICKUP, sizeof(TPacketCGItemPickup), "ItemPickup");

    Set(HEADER_CG_QUICKSLOT_ADD, sizeof(TPacketCGQuickslotAdd), "QuickslotAdd");
    Set(HEADER_CG_QUICKSLOT_DEL, sizeof(TPacketCGQuickslotDel), "QuickslotDel");
    Set(HEADER_CG_QUICKSLOT_SWAP, sizeof(TPacketCGQuickslotSwap), "QuickslotSwap");

    Set(HEADER_CG_SHOP, sizeof(TPacketCGShop), "Shop");

    Set(HEADER_CG_ON_CLICK, sizeof(TPacketCGOnClick), "OnClick");
    Set(HEADER_CG_EXCHANGE, sizeof(TPacketCGExchange), "Exchange");
    Set(HEADER_CG_CHARACTER_POSITION, sizeof(TPacketCGPosition), "Position");
    Set(HEADER_CG_SCRIPT_ANSWER, sizeof(TPacketCGScriptAnswer), "ScriptAnswer");
    Set(HEADER_CG_SCRIPT_BUTTON, sizeof(TPacketCGScriptButton), "ScriptButton");
    Set(HEADER_CG_QUEST_INPUT_STRING, sizeof(TPacketCGQuestInputString), "QuestInputString");
    Set(HEADER_CG_QUEST_CONFIRM, sizeof(TPacketCGQuestConfirm), "QuestConfirm");

    Set(HEADER_CG_MOVE, sizeof(TPacketCGMove), "Move");
    Set(HEADER_CG_SYNC_POSITION, sizeof(TPacketCGSyncPosition), "SyncPosition");

    Set(HEADER_CG_FLY_TARGETING, sizeof(TPacketCGFlyTargeting), "FlyTarget");
    Set(HEADER_CG_ADD_FLY_TARGETING, sizeof(TPacketCGFlyTargeting), "AddFlyTarget");
    Set(HEADER_CG_SHOOT, sizeof(TPacketCGShoot), "Shoot");

    Set(HEADER_CG_USE_SKILL, sizeof(TPacketCGUseSkill), "UseSkill");

    Set(HEADER_CG_ITEM_USE_TO_ITEM, sizeof(TPacketCGItemUseToItem), "UseItemToItem");
    Set(HEADER_CG_TARGET, sizeof(TPacketCGTarget), "Target");
    Set(HEADER_CG_WARP, sizeof(TPacketCGWarp), "Warp");
    Set(HEADER_CG_MESSENGER, sizeof(TPacketCGMessenger), "Messenger");

    Set(HEADER_CG_PARTY_REMOVE, sizeof(TPacketCGPartyRemove), "PartyRemove");
    Set(HEADER_CG_PARTY_INVITE, sizeof(TPacketCGPartyInvite), "PartyInvite");
    Set(HEADER_CG_PARTY_INVITE_ANSWER, sizeof(TPacketCGPartyInviteAnswer), "PartyInviteAnswer");
    Set(HEADER_CG_PARTY_SET_STATE, sizeof(TPacketCGPartySetState), "PartySetState");
    Set(HEADER_CG_PARTY_USE_SKILL, sizeof(TPacketCGPartyUseSkill), "PartyUseSkill");
    Set(HEADER_CG_PARTY_PARAMETER, sizeof(TPacketCGPartyParameter), "PartyParam");

    Set(HEADER_CG_EMPIRE, sizeof(TPacketCGEmpire), "Empire");
    Set(HEADER_CG_SAFEBOX_CHECKOUT, sizeof(TPacketCGSafeboxCheckout), "SafeboxCheckout");
    Set(HEADER_CG_SAFEBOX_CHECKIN, sizeof(TPacketCGSafeboxCheckin), "SafeboxCheckin");

    Set(HEADER_CG_SAFEBOX_ITEM_MOVE, sizeof(TPacketCGItemMove), "SafeboxItemMove");

    Set(HEADER_CG_GUILD, sizeof(TPacketCGGuild), "Guild");
    Set(HEADER_CG_ANSWER_MAKE_GUILD, sizeof(TPacketCGAnswerMakeGuild), "AnswerMakeGuild");

    Set(HEADER_CG_FISHING, sizeof(TPacketCGFishing), "Fishing");
    Set(HEADER_CG_ITEM_GIVE, sizeof(TPacketCGGiveItem), "ItemGive");
    Set(HEADER_CG_HACK, sizeof(TPacketCGHack), "Hack");
    Set(HEADER_CG_MYSHOP, sizeof(TPacketCGMyShop), "MyShop");

    Set(HEADER_CG_REFINE, sizeof(TPacketCGRefine), "Refine");
    Set(HEADER_CG_CHANGE_NAME, sizeof(TPacketCGChangeName), "ChangeName");

    Set(HEADER_CG_CLIENT_VERSION, sizeof(TPacketCGClientVersion), "Version");
    Set(HEADER_CG_CLIENT_VERSION2, sizeof(TPacketCGClientVersion2), "Version");
    Set(HEADER_CG_PONG, sizeof(BYTE), "Pong");
    Set(HEADER_CG_MALL_CHECKOUT, sizeof(TPacketCGSafeboxCheckout), "MallCheckout");

    Set(HEADER_CG_SCRIPT_SELECT_ITEM, sizeof(TPacketCGScriptSelectItem), "ScriptSelectItem");

    Set(HEADER_CG_DRAGON_SOUL_REFINE, sizeof(TPacketCGDragonSoulRefine), "DragonSoulRefine");
    Set(HEADER_CG_STATE_CHECKER, sizeof(BYTE), "ServerStateCheck");
}

CPacketInfoCG::~CPacketInfoCG()
{
    Log("packet_info.txt");
}

////////////////////////////////////////////////////////////////////////////////
CPacketInfoGG::CPacketInfoGG()
{
    Set(HEADER_GG_SETUP,       sizeof(TPacketGGSetup),        "Setup");
    Set(HEADER_GG_LOGIN,       sizeof(TPacketGGLogin),        "Login");
    Set(HEADER_GG_LOGOUT,      sizeof(TPacketGGLogout),   "Logout");
    Set(HEADER_GG_RELAY,       sizeof(TPacketGGRelay),        "Relay");
    Set(HEADER_GG_NOTICE,      sizeof(TPacketGGNotice),   "Notice");
    Set(HEADER_GG_SHUTDOWN,        sizeof(TPacketGGShutdown), "Shutdown");
    Set(HEADER_GG_GUILD,       sizeof(TPacketGGGuild),        "Guild");
    Set(HEADER_GG_SHOUT,       sizeof(TPacketGGShout),        "Shout");
    Set(HEADER_GG_DISCONNECT,          sizeof(TPacketGGDisconnect),   "Disconnect");
    Set(HEADER_GG_MESSENGER_ADD,   sizeof(TPacketGGMessenger),    "MessengerAdd");
    Set(HEADER_GG_MESSENGER_REMOVE,    sizeof(TPacketGGMessenger),    "MessengerRemove");
    Set(HEADER_GG_FIND_POSITION,   sizeof(TPacketGGFindPosition), "FindPosition");
    Set(HEADER_GG_WARP_CHARACTER,  sizeof(TPacketGGWarpCharacter),    "WarpCharacter");
    Set(HEADER_GG_GUILD_WAR_ZONE_MAP_INDEX, sizeof(TPacketGGGuildWarMapIndex), "GuildWarMapIndex");
    Set(HEADER_GG_TRANSFER,        sizeof(TPacketGGTransfer), "Transfer");
    Set(HEADER_GG_XMAS_WARP_SANTA, sizeof(TPacketGGXmasWarpSanta),    "XmasWarpSanta");
    Set(HEADER_GG_XMAS_WARP_SANTA_REPLY, sizeof(TPacketGGXmasWarpSantaReply), "XmasWarpSantaReply");
    Set(HEADER_GG_RELOAD_CRC_LIST, sizeof(BYTE),          "ReloadCRCList");
    Set(HEADER_GG_CHECK_CLIENT_VERSION, sizeof(BYTE),         "CheckClientVersion");
    Set(HEADER_GG_LOGIN_PING,      sizeof(TPacketGGLoginPing),    "LoginPing");

    // BLOCK_CHAT
    Set(HEADER_GG_BLOCK_CHAT,      sizeof(TPacketGGBlockChat),    "BlockChat");
    // END_OF_BLOCK_CHAT

    Set(HEADER_GG_CHECK_AWAKENESS,     sizeof(TPacketGGCheckAwakeness),   "CheckAwakeness");
}

CPacketInfoGG::~CPacketInfoGG()
{
    Log("p2p_packet_info.txt");
}

