#ifndef __INC_PACKET_H__
#define __INC_PACKET_H__

enum
{
    HEADER_CG_HANDSHAKE                         = 0xff,
    HEADER_CG_PONG                              = 0xfe,
    HEADER_CG_TIME_SYNC                         = 0xfc,
    HEADER_CG_KEY_AGREEMENT                     = 0xfb, // _IMPROVED_PACKET_ENCRYPTION_

    HEADER_CG_LOGIN                             = 1,
    HEADER_CG_ATTACK                            = 2,
    HEADER_CG_CHAT                              = 3,
    HEADER_CG_CHARACTER_CREATE                  = 4,
    HEADER_CG_CHARACTER_DELETE                  = 5,
    HEADER_CG_CHARACTER_SELECT                  = 6,
    HEADER_CG_MOVE                              = 7,
    HEADER_CG_SYNC_POSITION                     = 8,
    HEADER_CG_ENTERGAME                         = 10,

    HEADER_CG_ITEM_USE                          = 11,
    HEADER_CG_ITEM_DROP                         = 12,
    HEADER_CG_ITEM_MOVE                         = 13,
    HEADER_CG_ITEM_PICKUP                       = 15,

    HEADER_CG_QUICKSLOT_ADD                     = 16,
    HEADER_CG_QUICKSLOT_DEL                     = 17,
    HEADER_CG_QUICKSLOT_SWAP                    = 18,
    HEADER_CG_WHISPER                           = 19,
    HEADER_CG_ITEM_DROP2                        = 20,

    HEADER_CG_ON_CLICK                          = 26,
    HEADER_CG_EXCHANGE                          = 27,
    HEADER_CG_CHARACTER_POSITION                = 28,
    HEADER_CG_SCRIPT_ANSWER                     = 29,
    HEADER_CG_QUEST_INPUT_STRING                = 30,
    HEADER_CG_QUEST_CONFIRM                     = 31,

    HEADER_CG_SHOP                              = 50,
    HEADER_CG_FLY_TARGETING                     = 51,
    HEADER_CG_USE_SKILL                         = 52,
    HEADER_CG_ADD_FLY_TARGETING                 = 53,
    HEADER_CG_SHOOT                             = 54,
    HEADER_CG_MYSHOP                            = 55,

    HEADER_CG_ITEM_USE_TO_ITEM                  = 60,
    HEADER_CG_TARGET                            = 61,

    HEADER_CG_TEXT                              = 64,   // @ 로 시작되면 텍스트를 파싱한다.
    HEADER_CG_WARP                              = 65,
    HEADER_CG_SCRIPT_BUTTON                     = 66,
    HEADER_CG_MESSENGER                         = 67,

    HEADER_CG_MALL_CHECKOUT                     = 69,
    HEADER_CG_SAFEBOX_CHECKIN                   = 70,   // 아이템을 창고에 넣넎는다.
    HEADER_CG_SAFEBOX_CHECKOUT                  = 71,   // 아이템을 창고로 부터 빼온다.

    HEADER_CG_PARTY_INVITE                      = 72,
    HEADER_CG_PARTY_INVITE_ANSWER               = 73,
    HEADER_CG_PARTY_REMOVE                      = 74,
    HEADER_CG_PARTY_SET_STATE                   = 75,
    HEADER_CG_PARTY_USE_SKILL                   = 76,
    HEADER_CG_SAFEBOX_ITEM_MOVE                 = 77,
    HEADER_CG_PARTY_PARAMETER                   = 78,

    HEADER_CG_GUILD                             = 80,
    HEADER_CG_ANSWER_MAKE_GUILD                 = 81,

    HEADER_CG_FISHING                           = 82,

    HEADER_CG_ITEM_GIVE                         = 83,

    HEADER_CG_EMPIRE                            = 90,

    HEADER_CG_REFINE                            = 96,

    HEADER_CG_MARK_LOGIN                        = 100,
    HEADER_CG_MARK_CRCLIST                      = 101,
    HEADER_CG_MARK_UPLOAD                       = 102,
    HEADER_CG_MARK_IDXLIST                      = 104,

    HEADER_CG_HACK                              = 105,
    HEADER_CG_CHANGE_NAME                       = 106,
    HEADER_CG_LOGIN2                            = 109,
    HEADER_CG_DUNGEON                           = 110,
    HEADER_CG_LOGIN3                            = 111,

    HEADER_CG_GUILD_SYMBOL_UPLOAD               = 112,
    HEADER_CG_SYMBOL_CRC                        = 113,

    // SCRIPT_SELECT_ITEM
    HEADER_CG_SCRIPT_SELECT_ITEM                = 114,
    // END_OF_SCRIPT_SELECT_ITEM

    //NOTE : 이런 개XXX 정말 이거 Packet설계한 사람은 누구냐. 이렇게 코딩하고 밥이 넘어가나.
    //enum을 별도로 구별을 하던가. 아님 namepsace로 구별을 하던가..
    //정말 packet generator까지는 바라지도 않는다. 이런 씨XX
    //이러다가 숫자 겹치면 누가 책임지는데???
    HEADER_CG_DRAGON_SOUL_REFINE                = 205,
    HEADER_CG_STATE_CHECKER                     = 206,

    HEADER_CG_CLIENT_VERSION                    = 0xfd,
    HEADER_CG_CLIENT_VERSION2                   = 0xf1,

    /********************************************************/
    HEADER_GC_KEY_AGREEMENT_COMPLETED           = 0xfa, // _IMPROVED_PACKET_ENCRYPTION_
    HEADER_GC_KEY_AGREEMENT                     = 0xfb, // _IMPROVED_PACKET_ENCRYPTION_
    HEADER_GC_TIME_SYNC                         = 0xfc,
    HEADER_GC_PHASE                             = 0xfd,
    HEADER_GC_BINDUDP                           = 0xfe,
    HEADER_GC_HANDSHAKE                         = 0xff,

    HEADER_GC_CHARACTER_ADD                     = 1,
    HEADER_GC_CHARACTER_DEL                     = 2,
    HEADER_GC_MOVE                              = 3,
    HEADER_GC_CHAT                              = 4,
    HEADER_GC_SYNC_POSITION                     = 5,

    HEADER_GC_LOGIN_SUCCESS                     = 6,
    HEADER_GC_LOGIN_SUCCESS_NEWSLOT             = 32,
    HEADER_GC_LOGIN_FAILURE                     = 7,

    HEADER_GC_CHARACTER_CREATE_SUCCESS          = 8,
    HEADER_GC_CHARACTER_CREATE_FAILURE          = 9,
    HEADER_GC_CHARACTER_DELETE_SUCCESS          = 10,
    HEADER_GC_CHARACTER_DELETE_WRONG_SOCIAL_ID  = 11,

    HEADER_GC_ATTACK                            = 12,
    HEADER_GC_STUN                              = 13,
    HEADER_GC_DEAD                              = 14,

    HEADER_GC_MAIN_CHARACTER_OLD                = 15,
    HEADER_GC_CHARACTER_POINTS                  = 16,
    HEADER_GC_CHARACTER_POINT_CHANGE            = 17,
    HEADER_GC_CHANGE_SPEED                      = 18,
    HEADER_GC_CHARACTER_UPDATE                  = 19,
    HEADER_GC_CHARACTER_UPDATE_NEW              = 24,

    HEADER_GC_ITEM_DEL                          = 20,
    HEADER_GC_ITEM_SET                          = 21,
    HEADER_GC_ITEM_USE                          = 22,
    HEADER_GC_ITEM_DROP                         = 23,
    HEADER_GC_ITEM_UPDATE                       = 25,

    HEADER_GC_ITEM_GROUND_ADD                   = 26,
    HEADER_GC_ITEM_GROUND_DEL                   = 27,

    HEADER_GC_QUICKSLOT_ADD                     = 28,
    HEADER_GC_QUICKSLOT_DEL                     = 29,
    HEADER_GC_QUICKSLOT_SWAP                    = 30,

    HEADER_GC_ITEM_OWNERSHIP                    = 31,

    HEADER_GC_WHISPER                           = 34,

    HEADER_GC_MOTION                            = 36,
    HEADER_GC_PARTS                             = 37,

    HEADER_GC_SHOP                              = 38,
    HEADER_GC_SHOP_SIGN                         = 39,

    HEADER_GC_DUEL_START                        = 40,
    HEADER_GC_PVP                               = 41,
    HEADER_GC_EXCHANGE                          = 42,
    HEADER_GC_CHARACTER_POSITION                = 43,

    HEADER_GC_PING                              = 44,
    HEADER_GC_SCRIPT                            = 45,
    HEADER_GC_QUEST_CONFIRM                     = 46,

    HEADER_GC_MOUNT                             = 61,
    HEADER_GC_OWNERSHIP                         = 62,
    HEADER_GC_TARGET                            = 63,

    HEADER_GC_WARP                              = 65,

    HEADER_GC_ADD_FLY_TARGETING                 = 69,
    HEADER_GC_CREATE_FLY                        = 70,
    HEADER_GC_FLY_TARGETING                     = 71,
    HEADER_GC_SKILL_LEVEL_OLD                   = 72,
    HEADER_GC_SKILL_LEVEL                       = 76,

    HEADER_GC_MESSENGER                         = 74,
    HEADER_GC_GUILD                             = 75,

    HEADER_GC_PARTY_INVITE                      = 77,
    HEADER_GC_PARTY_ADD                         = 78,
    HEADER_GC_PARTY_UPDATE                      = 79,
    HEADER_GC_PARTY_REMOVE                      = 80,
    HEADER_GC_QUEST_INFO                        = 81,
    HEADER_GC_REQUEST_MAKE_GUILD                = 82,
    HEADER_GC_PARTY_PARAMETER                   = 83,

    HEADER_GC_SAFEBOX_SET                       = 85,
    HEADER_GC_SAFEBOX_DEL                       = 86,
    HEADER_GC_SAFEBOX_WRONG_PASSWORD            = 87,
    HEADER_GC_SAFEBOX_SIZE                      = 88,

    HEADER_GC_FISHING                           = 89,

    HEADER_GC_EMPIRE                            = 90,

    HEADER_GC_PARTY_LINK                        = 91,
    HEADER_GC_PARTY_UNLINK                      = 92,

    HEADER_GC_REFINE_INFORMATION_OLD            = 95,

    HEADER_GC_VIEW_EQUIP                        = 99,

    HEADER_GC_MARK_BLOCK                        = 100,
    HEADER_GC_MARK_IDXLIST                      = 102,

    HEADER_GC_TIME                              = 106,
    HEADER_GC_CHANGE_NAME                       = 107,

    HEADER_GC_DUNGEON                           = 110,

    HEADER_GC_WALK_MODE                         = 111,
    HEADER_GC_SKILL_GROUP                       = 112,
    HEADER_GC_MAIN_CHARACTER                    = 113,

    //  HEADER_GC_USE_POTION                    = 114,
    HEADER_GC_SEPCIAL_EFFECT                    = 114,

    HEADER_GC_LOGIN_KEY                         = 118,
    HEADER_GC_REFINE_INFORMATION                = 119,
    HEADER_GC_CHANNEL                           = 121,

    // 122 HEADER_GC_MALL_OPEN
    HEADER_GC_TARGET_UPDATE                     = 123,
    HEADER_GC_TARGET_DELETE                     = 124,
    HEADER_GC_TARGET_CREATE                     = 125,

    HEADER_GC_AFFECT_ADD                        = 126,
    HEADER_GC_AFFECT_REMOVE                     = 127,

    HEADER_GC_MALL_OPEN                         = 122,
    HEADER_GC_MALL_SET                          = 128,
    HEADER_GC_MALL_DEL                          = 129,

    HEADER_GC_LAND_LIST                         = 130,
    HEADER_GC_LOVER_INFO                        = 131,
    HEADER_GC_LOVE_POINT_UPDATE                 = 132,

    HEADER_GC_SYMBOL_DATA                       = 133,

    // MINING
    HEADER_GC_DIG_MOTION                        = 134,
    // END_OF_MINING

    HEADER_GC_DAMAGE_INFO                       = 135,
    HEADER_GC_CHAR_ADDITIONAL_INFO              = 136,

    // SUPPORT_BGM
    HEADER_GC_MAIN_CHARACTER3_BGM               = 137,
    HEADER_GC_MAIN_CHARACTER4_BGM_VOL           = 138,
    // END_OF_SUPPORT_BGM

    HEADER_GC_AUTH_SUCCESS                      = 150,

    //HYBRID CRYPT
    HEADER_GC_HYBRIDCRYPT_KEYS                  = 152,
    HEADER_GC_HYBRIDCRYPT_SDB                   = 153, // SDB means Supplmentary Data Blocks
    //HYBRID CRYPT

    HEADER_GC_SPECIFIC_EFFECT                   = 208,

    HEADER_GC_DRAGON_SOUL_REFINE                = 209,
    HEADER_GC_RESPOND_CHANNELSTATUS             = 210,


    /////////////////////////////////////////////////////////////////////////////

    HEADER_GG_LOGIN                             = 1,
    HEADER_GG_LOGOUT                            = 2,
    HEADER_GG_RELAY                             = 3,
    HEADER_GG_NOTICE                            = 4,
    HEADER_GG_SHUTDOWN                          = 5,
    HEADER_GG_GUILD                             = 6,
    HEADER_GG_DISCONNECT                        = 7,    // 누군가의 접속을 강제로 끊을 때
    HEADER_GG_SHOUT                             = 8,
    HEADER_GG_SETUP                             = 9,
    HEADER_GG_MESSENGER_ADD                     = 10,
    HEADER_GG_MESSENGER_REMOVE                  = 11,
    HEADER_GG_FIND_POSITION                     = 12,
    HEADER_GG_WARP_CHARACTER                    = 13,
    HEADER_GG_GUILD_WAR_ZONE_MAP_INDEX          = 15,
    HEADER_GG_TRANSFER                          = 16,
    HEADER_GG_XMAS_WARP_SANTA                   = 17,
    HEADER_GG_XMAS_WARP_SANTA_REPLY             = 18,
    HEADER_GG_RELOAD_CRC_LIST                   = 19,
    HEADER_GG_LOGIN_PING                        = 20,
    HEADER_GG_CHECK_CLIENT_VERSION              = 21,
    HEADER_GG_BLOCK_CHAT                        = 22,

    HEADER_GG_CHECK_AWAKENESS                   = 29,
};

#pragma pack(1)
using TPacketGGSetup = struct SPacketGGSetup
{
    BYTE    bHeader;
    WORD    wPort;
    BYTE    bChannel;
};

using TPacketGGLogin = struct SPacketGGLogin
{
    BYTE    bHeader;
    char    szName[CHARACTER_NAME_MAX_LEN + 1];
    DWORD   dwPID;
    BYTE    bEmpire;
    long    lMapIndex;
    BYTE    bChannel;
};

using TPacketGGLogout = struct SPacketGGLogout
{
    BYTE    bHeader;
    char    szName[CHARACTER_NAME_MAX_LEN + 1];
};

using TPacketGGRelay = struct SPacketGGRelay
{
    BYTE    bHeader;
    char    szName[CHARACTER_NAME_MAX_LEN + 1];
    long    lSize;
};

using TPacketGGNotice = struct SPacketGGNotice
{
    BYTE    bHeader;
    long    lSize;
};

using TPacketGGShutdown = struct SPacketGGShutdown
{
    BYTE    bHeader;
};

using TPacketGGGuild = struct SPacketGGGuild
{
    BYTE    bHeader;
    BYTE    bSubHeader;
    DWORD   dwGuild;
};

enum
{
    GUILD_SUBHEADER_GG_CHAT,
    GUILD_SUBHEADER_GG_SET_MEMBER_COUNT_BONUS,
};

using TPacketGGGuildChat = struct SPacketGGGuildChat
{
    BYTE    bHeader;
    BYTE    bSubHeader;
    DWORD   dwGuild;
    char    szText[CHAT_MAX_LEN + 1];
};

using TPacketGGParty = struct SPacketGGParty
{
    BYTE    header;
    BYTE    subheader;
    DWORD   pid;
    DWORD   leaderpid;
};

enum
{
    PARTY_SUBHEADER_GG_CREATE,
    PARTY_SUBHEADER_GG_DESTROY,
    PARTY_SUBHEADER_GG_JOIN,
    PARTY_SUBHEADER_GG_QUIT,
};

using TPacketGGDisconnect = struct SPacketGGDisconnect
{
    BYTE    bHeader;
    char    szLogin[LOGIN_MAX_LEN + 1];
};

using TPacketGGShout = struct SPacketGGShout
{
    BYTE    bHeader;
    BYTE    bEmpire;
    char    szText[CHAT_MAX_LEN + 1];

    /* - CLIENT_LOCALE_STRING ------------------------------ */
    bool    bCanFormat;
    /* ----------------------------------------------------- */
};

using TPacketGGXmasWarpSanta = struct SPacketGGXmasWarpSanta
{
    BYTE    bHeader;
    BYTE    bChannel;
    long    lMapIndex;
};

using TPacketGGXmasWarpSantaReply = struct SPacketGGXmasWarpSantaReply
{
    BYTE    bHeader;
    BYTE    bChannel;
};

using TPacketGGMessenger = struct SPacketGGMessenger
{
    BYTE        bHeader;
    char        szAccount[CHARACTER_NAME_MAX_LEN + 1];
    char        szCompanion[CHARACTER_NAME_MAX_LEN + 1];
};

using TPacketGGFindPosition = struct SPacketGGFindPosition
{
    BYTE header;
    DWORD dwFromPID; // 저 위치로 워프하려는 사람
    DWORD dwTargetPID; // 찾는 사람
};

using TPacketGGWarpCharacter = struct SPacketGGWarpCharacter
{
    BYTE header;
    DWORD pid;
    long x;
    long y;
};

//  HEADER_GG_GUILD_WAR_ZONE_MAP_INDEX      = 15,

using TPacketGGGuildWarMapIndex = struct SPacketGGGuildWarMapIndex
{
    BYTE bHeader;
    DWORD dwGuildID1;
    DWORD dwGuildID2;
    long lMapIndex;
};

using TPacketGGTransfer = struct SPacketGGTransfer
{
    BYTE    bHeader;
    char    szName[CHARACTER_NAME_MAX_LEN + 1];
    long    lX;
    long lY;
};

using TPacketGGLoginPing = struct SPacketGGLoginPing
{
    BYTE    bHeader;
    char    szLogin[LOGIN_MAX_LEN + 1];
};

using TPacketGGBlockChat = struct SPacketGGBlockChat
{
    BYTE    bHeader;
    char    szName[CHARACTER_NAME_MAX_LEN + 1];
    long    lBlockDuration;
};

/* 클라이언트 측에서 보내는 패킷 */

using TPacketCGText = struct command_text
{
    BYTE    bHeader;
};

/* 로그인 (1) */
using TPacketCGHandshake = struct command_handshake
{
    BYTE    bHeader;
    DWORD   dwHandshake;
    DWORD   dwTime;
    long    lDelta;
};

using TPacketCGLogin = struct command_login
{
    BYTE    header;
    char    login[LOGIN_MAX_LEN + 1];
    char    passwd[PASSWD_MAX_LEN + 1];
};

using TPacketCGLogin2 = struct command_login2
{
    BYTE    header;
    char    login[LOGIN_MAX_LEN + 1];
    DWORD   dwLoginKey;
    DWORD   adwClientKey[4];
};

using TPacketCGLogin3 = struct command_login3
{
    BYTE    header;
    char    login[LOGIN_MAX_LEN + 1];
    char    passwd[PASSWD_MAX_LEN + 1];
    DWORD   adwClientKey[4];
};

using TPacketGCLoginKey = struct packet_login_key
{
    BYTE    bHeader;
    DWORD   dwLoginKey;
};

using TPacketCGPlayerSelect = struct command_player_select
{
    BYTE    header;
    BYTE    index;
};

using TPacketCGPlayerDelete = struct command_player_delete
{
    BYTE    header;
    BYTE    index;
    char    private_code[8];
};

using TPacketCGPlayerCreate = struct command_player_create
{
    BYTE        header;
    BYTE        index;
    char        name[CHARACTER_NAME_MAX_LEN + 1];
    WORD        job;
    BYTE    shape;
    BYTE    Con;
    BYTE    Int;
    BYTE    Str;
    BYTE    Dex;
};

using TPacketGCPlayerCreateSuccess = struct command_player_create_success
{
    BYTE        header;
    BYTE        bAccountCharacterIndex;
    TSimplePlayer   player;
};

// 공격
using TPacketCGAttack = struct command_attack
{
    BYTE    bHeader;
    BYTE    bType;
    DWORD   dwVID;
    BYTE    bCRCMagicCubeProcPiece;
    BYTE    bCRCMagicCubeFilePiece;
};

enum EMoveFuncType
{
    FUNC_WAIT,
    FUNC_MOVE,
    FUNC_ATTACK,
    FUNC_COMBO,
    FUNC_MOB_SKILL,
    _FUNC_SKILL,
    FUNC_MAX_NUM,
    FUNC_SKILL = 0x80,
};

// 이동
using TPacketCGMove = struct command_move
{
    BYTE    bHeader;
    BYTE    bFunc;
    BYTE    bArg;
    BYTE    bRot;
    long    lX;
    long    lY;
    DWORD   dwTime;
};

using TPacketCGSyncPositionElement = struct command_sync_position_element
{
    DWORD   dwVID;
    long    lX;
    long    lY;
};

// 위치 동기화
using TPacketCGSyncPosition = struct command_sync_position  // 가변 패킷
{
    BYTE    bHeader;
    WORD    wSize;
};

/* 채팅 (3) */
using TPacketCGChat = struct command_chat   // 가변 패킷
{
    BYTE    header;
    WORD    size;
    BYTE    type;
};

/* 귓속말 */
using TPacketCGWhisper = struct command_whisper
{
    BYTE    bHeader;
    WORD    wSize;
    char    szNameTo[CHARACTER_NAME_MAX_LEN + 1];
};

using TPacketCGEnterGame = struct command_entergame
{
    BYTE    header;
};

using TPacketCGItemUse = struct command_item_use
{
    BYTE    header;
    TItemPos    Cell;
};

using TPacketCGItemUseToItem = struct command_item_use_to_item
{
    BYTE    header;
    TItemPos    Cell;
    TItemPos    TargetCell;
};

using TPacketCGItemDrop = struct command_item_drop
{
    BYTE    header;
    TItemPos    Cell;
    DWORD   gold;
};

using TPacketCGItemDrop2 = struct command_item_drop2
{
    BYTE    header;
    TItemPos    Cell;
    DWORD   gold;
    BYTE    count;
};

using TPacketCGItemMove = struct command_item_move
{
    BYTE    header;
    TItemPos    Cell;
    TItemPos    CellTo;
    BYTE    count;
};

using TPacketCGItemPickup = struct command_item_pickup
{
    BYTE    header;
    DWORD   vid;
};

using TPacketCGQuickslotAdd = struct command_quickslot_add
{
    BYTE    header;
    BYTE    pos;
    TQuickslot  slot;
};

using TPacketCGQuickslotDel = struct command_quickslot_del
{
    BYTE    header;
    BYTE    pos;
};

using TPacketCGQuickslotSwap = struct command_quickslot_swap
{
    BYTE    header;
    BYTE    pos;
    BYTE    change_pos;
};

enum
{
    SHOP_SUBHEADER_CG_END,
    SHOP_SUBHEADER_CG_BUY,
    SHOP_SUBHEADER_CG_SELL,
    SHOP_SUBHEADER_CG_SELL2
};

using TPacketCGShopBuy = struct command_shop_buy
{
    BYTE    count;
};

using TPacketCGShopSell = struct command_shop_sell
{
    BYTE    pos;
    BYTE    count;
};

using TPacketCGShop = struct command_shop
{
    BYTE    header;
    BYTE    subheader;
};

using TPacketCGOnClick = struct command_on_click
{
    BYTE    header;
    DWORD   vid;
};

enum
{
    EXCHANGE_SUBHEADER_CG_START,    /* arg1 == vid of target character */
    EXCHANGE_SUBHEADER_CG_ITEM_ADD, /* arg1 == position of item */
    EXCHANGE_SUBHEADER_CG_ITEM_DEL, /* arg1 == position of item */
    EXCHANGE_SUBHEADER_CG_ELK_ADD,  /* arg1 == amount of gold */
    EXCHANGE_SUBHEADER_CG_ACCEPT,   /* arg1 == not used */
    EXCHANGE_SUBHEADER_CG_CANCEL,   /* arg1 == not used */
};

using TPacketCGExchange = struct command_exchange
{
    BYTE    header;
    BYTE    sub_header;
    DWORD   arg1;
    BYTE    arg2;
    TItemPos    Pos;
};

using TPacketCGPosition = struct command_position
{
    BYTE    header;
    BYTE    position;
};

using TPacketCGScriptAnswer = struct command_script_answer
{
    BYTE    header;
    BYTE    answer;
    //char  file[32 + 1];
    //BYTE  answer[16 + 1];
};


using TPacketCGScriptButton = struct command_script_button
{
    BYTE        header;
    unsigned int    idx;
};

using TPacketCGQuestInputString = struct command_quest_input_string
{
    BYTE header;
    char msg[64 + 1];
};

using TPacketCGQuestConfirm = struct command_quest_confirm
{
    BYTE header;
    BYTE answer;
    DWORD requestPID;
};

/*
 * 서버 측에서 보내는 패킷
 */
using TPacketGCQuestConfirm = struct packet_quest_confirm
{
    BYTE header;
    char msg[64 + 1];
    long timeout;
    DWORD requestPID;
};

using TPacketGCHandshake = struct packet_handshake
{
    BYTE    bHeader;
    DWORD   dwHandshake;
    DWORD   dwTime;
    long    lDelta;
};

enum EPhase
{
    PHASE_CLOSE,
    PHASE_HANDSHAKE,
    PHASE_LOGIN,
    PHASE_SELECT,
    PHASE_LOADING,
    PHASE_GAME,
    PHASE_DEAD,

    PHASE_CLIENT_CONNECTING,
    PHASE_DBCLIENT,
    PHASE_P2P,
    PHASE_AUTH
};

using TPacketGCPhase = struct packet_phase
{
    BYTE    header;
    BYTE    phase;
};

using TPacketGCBindUDP = struct packet_bindudp
{
    BYTE    header;
    DWORD   addr;
    WORD    port;
};

enum
{
    LOGIN_FAILURE_ALREADY   = 1,
    LOGIN_FAILURE_ID_NOT_EXIST  = 2,
    LOGIN_FAILURE_WRONG_PASS    = 3,
    LOGIN_FAILURE_FALSE     = 4,
    LOGIN_FAILURE_NOT_TESTOR    = 5,
    LOGIN_FAILURE_NOT_TEST_TIME = 6,
    LOGIN_FAILURE_FULL      = 7
};

using TPacketGCLoginSuccess = struct packet_login_success
{
    BYTE        bHeader;
    TSimplePlayer   players[PLAYER_PER_ACCOUNT];
    DWORD       guild_id[PLAYER_PER_ACCOUNT];
    char        guild_name[PLAYER_PER_ACCOUNT][GUILD_NAME_MAX_LEN + 1];

    DWORD       handle;
    DWORD       random_key;
};

using TPacketGCAuthSuccess = struct packet_auth_success
{
    BYTE    bHeader;
    DWORD   dwLoginKey;
    BYTE    bResult;
};

using TPacketGCLoginFailure = struct packet_login_failure
{
    BYTE    header;
    char    szStatus[ACCOUNT_STATUS_MAX_LEN + 1];
};

using TPacketGCCreateFailure = struct packet_create_failure
{
    BYTE    header;
    BYTE    bType;
};

enum
{
    ADD_CHARACTER_STATE_DEAD        = (1 << 0),
    ADD_CHARACTER_STATE_SPAWN       = (1 << 1),
    ADD_CHARACTER_STATE_GUNGON      = (1 << 2),
    ADD_CHARACTER_STATE_KILLER      = (1 << 3),
    ADD_CHARACTER_STATE_PARTY       = (1 << 4),
};

enum ECharacterEquipmentPart
{
    CHR_EQUIPPART_ARMOR,
    CHR_EQUIPPART_WEAPON,
    CHR_EQUIPPART_HEAD,
    CHR_EQUIPPART_HAIR,
    CHR_EQUIPPART_NUM,
};

using TPacketGCCharacterAdd = struct packet_add_char
{
    BYTE    header;
    DWORD   dwVID;

    float   angle;
    long    x;
    long    y;
    long    z;

    BYTE    bType;
    WORD    wRaceNum;
    BYTE    bMovingSpeed;
    BYTE    bAttackSpeed;

    BYTE    bStateFlag;
    DWORD   dwAffectFlag[2];    // 효과
};

using TPacketGCCharacterAdditionalInfo = struct packet_char_additional_info
{
    BYTE    header;
    DWORD   dwVID;
    char    name[CHARACTER_NAME_MAX_LEN + 1];
    WORD    awPart[CHR_EQUIPPART_NUM];
    BYTE    bEmpire;
    DWORD   dwGuildID;
    DWORD   dwLevel;
    short   sAlignment;
    BYTE    bPKMode;
    DWORD   dwMountVnum;
};

/*
   typedef struct packet_update_char_old
   {
   BYTE header;
   DWORD    dwVID;

   WORD        awPart[CHR_EQUIPPART_NUM];
   BYTE bMovingSpeed;
   BYTE bAttackSpeed;

   BYTE bStateFlag;
   DWORD    dwAffectFlag[2];

   DWORD    dwGuildID;
   short    sAlignment;
   BYTE bPKMode;
   DWORD    dwMountVnum;
   } TPacketGCCharacterUpdateOld;
 */

using TPacketGCCharacterUpdate = struct packet_update_char
{
    BYTE    header;
    DWORD   dwVID;

    WORD        awPart[CHR_EQUIPPART_NUM];
    BYTE    bMovingSpeed;
    BYTE    bAttackSpeed;

    BYTE    bStateFlag;
    DWORD   dwAffectFlag[2];

    DWORD   dwGuildID;
    short   sAlignment;
    BYTE    bPKMode;
    DWORD   dwMountVnum;
    //WORD  wRaceNum;
};

using TPacketGCCharacterDelete = struct packet_del_char
{
    BYTE    header;
    DWORD   id;
};

using TPacketGCChat = struct packet_chat    // 가변 패킷
{
    BYTE    header;
    WORD    size;
    BYTE    type;
    DWORD   id;
    BYTE    bEmpire;

    /* - CLIENT_LOCALE_STRING ------------------------------ */
    bool    bCanFormat;
    packet_chat() : bCanFormat(true) {}
    /* ----------------------------------------------------- */
};

using TPacketGCWhisper = struct packet_whisper  // 가변 패킷
{
    BYTE    bHeader;
    WORD    wSize;
    BYTE    bType;
    char    szNameFrom[CHARACTER_NAME_MAX_LEN + 1];

    /* - CLIENT_LOCALE_STRING ------------------------------ */
    bool    bCanFormat;
    packet_whisper() : bCanFormat(true) {}
    /* ----------------------------------------------------- */
};

using TPacketGCMainCharacter = struct packet_main_character
{
    BYTE        header;
    DWORD   dwVID;
    WORD    wRaceNum;
    char    szName[CHARACTER_NAME_MAX_LEN + 1];
    long    lx, ly, lz;
    BYTE    empire;
    BYTE    skill_group;
};

// SUPPORT_BGM
using TPacketGCMainCharacter3_BGM = struct packet_main_character3_bgm
{
    enum
    {
        MUSIC_NAME_LEN = 24,
    };

    BYTE    header;
    DWORD   dwVID;
    WORD    wRaceNum;
    char    szChrName[CHARACTER_NAME_MAX_LEN + 1];
    char    szBGMName[MUSIC_NAME_LEN + 1];
    long    lx, ly, lz;
    BYTE    empire;
    BYTE    skill_group;
};

using TPacketGCMainCharacter4_BGM_VOL = struct packet_main_character4_bgm_vol
{
    enum
    {
        MUSIC_NAME_LEN = 24,
    };

    BYTE    header;
    DWORD   dwVID;
    WORD    wRaceNum;
    char    szChrName[CHARACTER_NAME_MAX_LEN + 1];
    char    szBGMName[MUSIC_NAME_LEN + 1];
    float   fBGMVol;
    long    lx, ly, lz;
    BYTE    empire;
    BYTE    skill_group;
};
// END_OF_SUPPORT_BGM

using TPacketGCPoints = struct packet_points
{
    BYTE    header;
    INT     points[POINT_MAX_NUM];
};

using TPacketGCSkillLevel = struct packet_skill_level
{
    BYTE        bHeader;
    TPlayerSkill    skills[SKILL_MAX_NUM];
};

using TPacketGCPointChange = struct packet_point_change
{
    int     header;
    DWORD   dwVID;
    BYTE    type;
    long    amount;
    long    value;
};

using TPacketGCStun = struct packet_stun
{
    BYTE    header;
    DWORD   vid;
};

using TPacketGCDead = struct packet_dead
{
    BYTE    header;
    DWORD   vid;
};

struct TPacketGCItemDelDeprecated
{
    BYTE    header;
    TItemPos Cell;
    DWORD   vnum;
    BYTE    count;
    long    alSockets[ITEM_SOCKET_MAX_NUM];
    TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_MAX_NUM];
};

using TPacketGCItemSet = struct packet_item_set
{
    BYTE    header;
    TItemPos Cell;
    DWORD   vnum;
    BYTE    count;
    DWORD   flags;
    DWORD   anti_flags;
    bool    highlight;
    long    alSockets[ITEM_SOCKET_MAX_NUM];
    TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_MAX_NUM];
};

using TPacketGCItemDel = struct packet_item_del
{
    BYTE    header;
    BYTE    pos;
};

struct packet_item_use
{
    BYTE    header;
    TItemPos Cell;
    DWORD   ch_vid;
    DWORD   victim_vid;
    DWORD   vnum;
};

struct packet_item_move
{
    BYTE    header;
    TItemPos Cell;
    TItemPos CellTo;
};

using TPacketGCItemUpdate = struct packet_item_update
{
    BYTE    header;
    TItemPos Cell;
    BYTE    count;
    long    alSockets[ITEM_SOCKET_MAX_NUM];
    TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_MAX_NUM];
};

using TPacketGCItemGroundAdd = struct packet_item_ground_add
{
    BYTE    bHeader;
    long    x, y, z;
    DWORD   dwVID;
    DWORD   dwVnum;
};

using TPacketGCItemOwnership = struct packet_item_ownership
{
    BYTE    bHeader;
    DWORD   dwVID;
    char    szName[CHARACTER_NAME_MAX_LEN + 1];
};

using TPacketGCItemGroundDel = struct packet_item_ground_del
{
    BYTE    bHeader;
    DWORD   dwVID;
};

struct packet_quickslot_add
{
    BYTE    header;
    BYTE    pos;
    TQuickslot  slot;
};

struct packet_quickslot_del
{
    BYTE    header;
    BYTE    pos;
};

struct packet_quickslot_swap
{
    BYTE    header;
    BYTE    pos;
    BYTE    pos_to;
};

struct packet_motion
{
    BYTE    header;
    DWORD   vid;
    DWORD   victim_vid;
    WORD    motion;
};

enum EPacketShopSubHeaders
{
    SHOP_SUBHEADER_GC_START,
    SHOP_SUBHEADER_GC_END,
    SHOP_SUBHEADER_GC_UPDATE_ITEM,
    SHOP_SUBHEADER_GC_UPDATE_PRICE,
    SHOP_SUBHEADER_GC_OK,
    SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY,
    SHOP_SUBHEADER_GC_SOLDOUT,
    SHOP_SUBHEADER_GC_INVENTORY_FULL,
    SHOP_SUBHEADER_GC_INVALID_POS,
    SHOP_SUBHEADER_GC_SOLD_OUT,
    SHOP_SUBHEADER_GC_START_EX,
    SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY_EX,
};

struct packet_shop_item
{
    DWORD       vnum;
    DWORD       price;
    BYTE        count;
    BYTE        display_pos;
    long    alSockets[ITEM_SOCKET_MAX_NUM];
    TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_MAX_NUM];
};

using TPacketGCShopStart = struct packet_shop_start
{
    DWORD   owner_vid;
    struct packet_shop_item items[SHOP_HOST_ITEM_MAX_NUM];
};

using TPacketGCShopStartEx = struct packet_shop_start_ex // 다음에 TSubPacketShopTab* shop_tabs 이 따라옴.
{
    typedef struct sub_packet_shop_tab
    {
        char name[SHOP_TAB_NAME_MAX];
        BYTE coin_type;
        packet_shop_item items[SHOP_HOST_ITEM_MAX_NUM];
    } TSubPacketShopTab;
    DWORD owner_vid;
    BYTE shop_tab_count;
};

using TPacketGCShopUpdateItem = struct packet_shop_update_item
{
    BYTE            pos;
    struct packet_shop_item item;
};

using TPacketGCShopUpdatePrice = struct packet_shop_update_price
{
    int             iPrice;
};

using TPacketGCShop = struct packet_shop    // 가변 패킷
{
    BYTE        header;
    WORD    size;
    BYTE        subheader;
};

struct packet_exchange
{
    BYTE    header;
    BYTE    sub_header;
    BYTE    is_me;
    DWORD   arg1;   // vnum
    TItemPos    arg2;   // cell
    DWORD   arg3;   // count
    long    alSockets[ITEM_SOCKET_MAX_NUM];
    TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_MAX_NUM];
};

enum EPacketTradeSubHeaders
{
    EXCHANGE_SUBHEADER_GC_START,    /* arg1 == vid */
    EXCHANGE_SUBHEADER_GC_ITEM_ADD, /* arg1 == vnum  arg2 == pos  arg3 == count */
    EXCHANGE_SUBHEADER_GC_ITEM_DEL,
    EXCHANGE_SUBHEADER_GC_GOLD_ADD, /* arg1 == gold */
    EXCHANGE_SUBHEADER_GC_ACCEPT,   /* arg1 == accept */
    EXCHANGE_SUBHEADER_GC_END,      /* arg1 == not used */
    EXCHANGE_SUBHEADER_GC_ALREADY,  /* arg1 == not used */
    EXCHANGE_SUBHEADER_GC_LESS_GOLD,    /* arg1 == not used */
};

struct packet_position
{
    BYTE    header;
    DWORD   vid;
    BYTE    position;
};

using TPacketGCPing = struct packet_ping
{
    BYTE    header;
};

struct packet_script
{
    BYTE    header;
    WORD    size;
    BYTE    skin;
    WORD    src_size;
};

using TPacketGCChangeSpeed = struct packet_change_speed
{
    BYTE        header;
    DWORD       vid;
    WORD        moving_speed;
};

struct packet_mount
{
    BYTE    header;
    DWORD   vid;
    DWORD   mount_vid;
    BYTE    pos;
    DWORD   x, y;
};

using TPacketGCMove = struct packet_move
{
    BYTE        bHeader;
    BYTE        bFunc;
    BYTE        bArg;
    BYTE        bRot;
    DWORD       dwVID;
    long        lX;
    long        lY;
    DWORD       dwTime;
    DWORD       dwDuration;
};

// 소유권
using TPacketGCOwnership = struct packet_ownership
{
    BYTE        bHeader;
    DWORD       dwOwnerVID;
    DWORD       dwVictimVID;
};

// 위치 동기화 패킷의 bCount 만큼 붙는 단위
using TPacketGCSyncPositionElement = struct packet_sync_position_element
{
    DWORD   dwVID;
    long    lX;
    long    lY;
};

// 위치 동기화
using TPacketGCSyncPosition = struct packet_sync_position   // 가변 패킷
{
    BYTE    bHeader;
    WORD    wSize;  // 개수 = (wSize - sizeof(TPacketGCSyncPosition)) / sizeof(TPacketGCSyncPositionElement)
};

using TPacketGCCreateFly = struct packet_fly
{
    BYTE    bHeader;
    BYTE    bType;
    DWORD   dwStartVID;
    DWORD   dwEndVID;
};

using TPacketCGFlyTargeting = struct command_fly_targeting
{
    BYTE        bHeader;
    DWORD       dwTargetVID;
    long        x, y;
};

using TPacketGCFlyTargeting = struct packet_fly_targeting
{
    BYTE        bHeader;
    DWORD       dwShooterVID;
    DWORD       dwTargetVID;
    long        x, y;
};

using TPacketCGShoot = struct packet_shoot
{
    BYTE        bHeader;
    BYTE        bType;
};

using TPacketGCDuelStart = struct packet_duel_start
{
    BYTE    header;
    WORD    wSize;  // DWORD가 몇개? 개수 = (wSize - sizeof(TPacketGCPVPList)) / 4
};

enum EPVPModes
{
    PVP_MODE_NONE,
    PVP_MODE_AGREE,
    PVP_MODE_FIGHT,
    PVP_MODE_REVENGE
};

using TPacketGCPVP = struct packet_pvp
{
    BYTE        bHeader;
    DWORD       dwVIDSrc;
    DWORD       dwVIDDst;
    BYTE        bMode;  // 0 이면 끔, 1이면 켬
};

using TPacketCGUseSkill = struct command_use_skill
{
    BYTE    bHeader;
    DWORD   dwVnum;
    DWORD   dwVID;
};

using TPacketCGTarget = struct command_target
{
    BYTE    header;
    DWORD   dwVID;
};

using TPacketGCTarget = struct packet_target
{
    BYTE    header;
    DWORD   dwVID;
    BYTE    bHPPercent;
};

using TPacketGCWarp = struct packet_warp
{
    BYTE    bHeader;
    long    lX;
    long    lY;
    long    lAddr;
    WORD    wPort;
};

using TPacketCGWarp = struct command_warp
{
    BYTE    bHeader;
};

struct packet_quest_info
{
    BYTE header;
    WORD size;
    WORD index;
    BYTE flag;
};

enum
{
    MESSENGER_SUBHEADER_GC_LIST,
    MESSENGER_SUBHEADER_GC_LOGIN,
    MESSENGER_SUBHEADER_GC_LOGOUT,
    MESSENGER_SUBHEADER_GC_INVITE
};

using TPacketGCMessenger = struct packet_messenger
{
    BYTE header;
    WORD size;
    BYTE subheader;
};

using TPacketGCMessengerGuildList = struct packet_messenger_guild_list
{
    BYTE connected;
    BYTE length;
    //char login[LOGIN_MAX_LEN+1];
};

using TPacketGCMessengerGuildLogin = struct packet_messenger_guild_login
{
    BYTE length;
    //char login[LOGIN_MAX_LEN+1];
};

using TPacketGCMessengerGuildLogout = struct packet_messenger_guild_logout
{
    BYTE length;

    //char login[LOGIN_MAX_LEN+1];
};

using TPacketGCMessengerListOffline = struct packet_messenger_list_offline
{
    BYTE connected; // always 0
    BYTE length;
};

using TPacketGCMessengerListOnline = struct packet_messenger_list_online
{
    BYTE connected; // always 1
    BYTE length;
};

enum
{
    MESSENGER_SUBHEADER_CG_ADD_BY_VID,
    MESSENGER_SUBHEADER_CG_ADD_BY_NAME,
    MESSENGER_SUBHEADER_CG_REMOVE,
    MESSENGER_SUBHEADER_CG_INVITE_ANSWER,
};

using TPacketCGMessenger = struct command_messenger
{
    BYTE header;
    BYTE subheader;
};

using TPacketCGMessengerAddByVID = struct command_messenger_add_by_vid
{
    DWORD vid;
};

using TPacketCGMessengerAddByName = struct command_messenger_add_by_name
{
    BYTE length;
    //char login[LOGIN_MAX_LEN+1];
};

using TPacketCGMessengerRemove = struct command_messenger_remove
{
    char login[LOGIN_MAX_LEN + 1];
    //DWORD account;
};

using TPacketCGSafeboxCheckout = struct command_safebox_checkout
{
    BYTE    bHeader;
    BYTE    bSafePos;
    TItemPos    ItemPos;
};

using TPacketCGSafeboxCheckin = struct command_safebox_checkin
{
    BYTE    bHeader;
    BYTE    bSafePos;
    TItemPos    ItemPos;
};

///////////////////////////////////////////////////////////////////////////////////
// Party

using TPacketCGPartyParameter = struct command_party_parameter
{
    BYTE    bHeader;
    BYTE    bDistributeMode;
};

using TPacketGCPartyParameter = struct paryt_parameter
{
    BYTE    bHeader;
    BYTE    bDistributeMode;
};

using TPacketGCPartyAdd = struct packet_party_add
{
    BYTE    header;
    DWORD   pid;
    char    name[CHARACTER_NAME_MAX_LEN + 1];
};

using TPacketCGPartyInvite = struct command_party_invite
{
    BYTE    header;
    DWORD   vid;
};

using TPacketGCPartyInvite = struct packet_party_invite
{
    BYTE    header;
    DWORD   leader_vid;
};

using TPacketCGPartyInviteAnswer = struct command_party_invite_answer
{
    BYTE    header;
    DWORD   leader_vid;
    BYTE    accept;
};

using TPacketGCPartyUpdate = struct packet_party_update
{
    BYTE    header;
    DWORD   pid;
    BYTE    role;
    BYTE    percent_hp;
    short   affects[7];
};

using TPacketGCPartyRemove = struct packet_party_remove
{
    BYTE header;
    DWORD pid;
};

using TPacketGCPartyLink = struct packet_party_link
{
    BYTE header;
    DWORD pid;
    DWORD vid;
};

using TPacketGCPartyUnlink = struct packet_party_unlink
{
    BYTE header;
    DWORD pid;
    DWORD vid;
};

using TPacketCGPartyRemove = struct command_party_remove
{
    BYTE header;
    DWORD pid;
};

using TPacketCGPartySetState = struct command_party_set_state
{
    BYTE header;
    DWORD pid;
    BYTE byRole;
    BYTE flag;
};

enum
{
    PARTY_SKILL_HEAL = 1,
    PARTY_SKILL_WARP = 2
};

using TPacketCGPartyUseSkill = struct command_party_use_skill
{
    BYTE header;
    BYTE bySkillIndex;
    DWORD vid;
};

using TPacketCGSafeboxSize = struct packet_safebox_size
{
    BYTE bHeader;
    BYTE bSize;
};

using TPacketCGSafeboxWrongPassword = struct packet_safebox_wrong_password
{
    BYTE    bHeader;
};

using TPacketCGEmpire = struct command_empire
{
    BYTE    bHeader;
    BYTE    bEmpire;
};

using TPacketGCEmpire = struct packet_empire
{
    BYTE    bHeader;
    BYTE    bEmpire;
};

enum
{
    SAFEBOX_MONEY_STATE_SAVE,
    SAFEBOX_MONEY_STATE_WITHDRAW,
};

using TPacketCGSafeboxMoney = struct command_safebox_money
{
    BYTE        bHeader;
    BYTE        bState;
    long    lMoney;
};

using TPacketGCSafeboxMoneyChange = struct packet_safebox_money_change
{
    BYTE    bHeader;
    long    lMoney;
};

// Guild

enum
{
    GUILD_SUBHEADER_GC_LOGIN,
    GUILD_SUBHEADER_GC_LOGOUT,
    GUILD_SUBHEADER_GC_LIST,
    GUILD_SUBHEADER_GC_GRADE,
    GUILD_SUBHEADER_GC_ADD,
    GUILD_SUBHEADER_GC_REMOVE,
    GUILD_SUBHEADER_GC_GRADE_NAME,
    GUILD_SUBHEADER_GC_GRADE_AUTH,
    GUILD_SUBHEADER_GC_INFO,
    GUILD_SUBHEADER_GC_COMMENTS,
    GUILD_SUBHEADER_GC_CHANGE_EXP,
    GUILD_SUBHEADER_GC_CHANGE_MEMBER_GRADE,
    GUILD_SUBHEADER_GC_SKILL_INFO,
    GUILD_SUBHEADER_GC_CHANGE_MEMBER_GENERAL,
    GUILD_SUBHEADER_GC_GUILD_INVITE,
    GUILD_SUBHEADER_GC_WAR,
    GUILD_SUBHEADER_GC_GUILD_NAME,
    GUILD_SUBHEADER_GC_GUILD_WAR_LIST,
    GUILD_SUBHEADER_GC_GUILD_WAR_END_LIST,
    GUILD_SUBHEADER_GC_WAR_SCORE,
    GUILD_SUBHEADER_GC_MONEY_CHANGE,
};

enum GUILD_SUBHEADER_CG
{
    GUILD_SUBHEADER_CG_ADD_MEMBER,
    GUILD_SUBHEADER_CG_REMOVE_MEMBER,
    GUILD_SUBHEADER_CG_CHANGE_GRADE_NAME,
    GUILD_SUBHEADER_CG_CHANGE_GRADE_AUTHORITY,
    GUILD_SUBHEADER_CG_OFFER,
    GUILD_SUBHEADER_CG_POST_COMMENT,
    GUILD_SUBHEADER_CG_DELETE_COMMENT,
    GUILD_SUBHEADER_CG_REFRESH_COMMENT,
    GUILD_SUBHEADER_CG_CHANGE_MEMBER_GRADE,
    GUILD_SUBHEADER_CG_USE_SKILL,
    GUILD_SUBHEADER_CG_CHANGE_MEMBER_GENERAL,
    GUILD_SUBHEADER_CG_GUILD_INVITE_ANSWER,
    GUILD_SUBHEADER_CG_CHARGE_GSP,
    GUILD_SUBHEADER_CG_DEPOSIT_MONEY,
    GUILD_SUBHEADER_CG_WITHDRAW_MONEY,
};

using TPacketGCGuild = struct packet_guild
{
    BYTE header;
    WORD size;
    BYTE subheader;
};

using TPacketGCGuildName = struct packet_guild_name_t
{
    BYTE header;
    WORD size;
    BYTE subheader;
    DWORD   guildID;
    char    guildName[GUILD_NAME_MAX_LEN];
};

using TPacketGCGuildWar = struct packet_guild_war
{
    DWORD   dwGuildSelf;
    DWORD   dwGuildOpp;
    BYTE    bType;
    BYTE    bWarState;
};

using TPacketCGGuild = struct command_guild
{
    BYTE header;
    BYTE subheader;
};

using TPacketCGAnswerMakeGuild = struct command_guild_answer_make_guild
{
    BYTE header;
    char guild_name[GUILD_NAME_MAX_LEN + 1];
};

using TPacketCGGuildUseSkill = struct command_guild_use_skill
{
    DWORD   dwVnum;
    DWORD   dwPID;
};

// Guild Mark
using TPacketCGMarkLogin = struct command_mark_login
{
    BYTE    header;
    DWORD   handle;
    DWORD   random_key;
};

using TPacketCGMarkUpload = struct command_mark_upload
{
    BYTE    header;
    DWORD   gid;
    BYTE    image[16 * 12 * 4];
};

using TPacketCGMarkIDXList = struct command_mark_idxlist
{
    BYTE    header;
};

using TPacketCGMarkCRCList = struct command_mark_crclist
{
    BYTE    header;
    BYTE    imgIdx;
    DWORD   crclist[80];
};

using TPacketGCMarkIDXList = struct packet_mark_idxlist
{
    BYTE    header;
    DWORD   bufSize;
    WORD    count;
    //뒤에 size * (WORD + WORD)만큼 데이터 붙음
};

using TPacketGCMarkBlock = struct packet_mark_block
{
    BYTE    header;
    DWORD   bufSize;
    BYTE    imgIdx;
    DWORD   count;
    // 뒤에 64 x 48 x 픽셀크기(4바이트) = 12288만큼 데이터 붙음
};

using TPacketCGGuildSymbolUpload = struct command_symbol_upload
{
    BYTE    header;
    WORD    size;
    DWORD   guild_id;
};

using TPacketCGSymbolCRC = struct command_symbol_crc
{
    BYTE header;
    DWORD guild_id;
    DWORD crc;
    DWORD size;
};

using TPacketGCGuildSymbolData = struct packet_symbol_data
{
    BYTE header;
    WORD size;
    DWORD guild_id;
};

// Fishing

using TPacketCGFishing = struct command_fishing
{
    BYTE header;
    BYTE dir;
};

using TPacketGCFishing = struct packet_fishing
{
    BYTE header;
    BYTE subheader;
    DWORD info;
    BYTE dir;
};

enum
{
    FISHING_SUBHEADER_GC_START,
    FISHING_SUBHEADER_GC_STOP,
    FISHING_SUBHEADER_GC_REACT,
    FISHING_SUBHEADER_GC_SUCCESS,
    FISHING_SUBHEADER_GC_FAIL,
    FISHING_SUBHEADER_GC_FISH,
};

using TPacketCGGiveItem = struct command_give_item
{
    BYTE byHeader;
    DWORD dwTargetVID;
    TItemPos ItemPos;
    BYTE byItemCount;
};

using TPacketCGHack = struct SPacketCGHack
{
    BYTE    bHeader;
    char    szBuf[255 + 1];
};

// SubHeader - Dungeon
enum
{
    DUNGEON_SUBHEADER_GC_TIME_ATTACK_START = 0,
    DUNGEON_SUBHEADER_GC_DESTINATION_POSITION = 1,
};

using TPacketGCDungeon = struct packet_dungeon
{
    BYTE bHeader;
    WORD size;
    BYTE subheader;
};

using TPacketGCDungeonDestPosition = struct packet_dungeon_dest_position
{
    long x;
    long y;
};

using TPacketGCShopSign = struct SPacketGCShopSign
{
    BYTE    bHeader;
    DWORD   dwVID;
    char    szSign[SHOP_SIGN_MAX_LEN + 1];
};

using TPacketCGMyShop = struct SPacketCGMyShop
{
    BYTE    bHeader;
    char    szSign[SHOP_SIGN_MAX_LEN + 1];
    BYTE    bCount;
};

using TPacketGCTime = struct SPacketGCTime
{
    BYTE    bHeader;
    time_t  time;
};

enum
{
    WALKMODE_RUN,
    WALKMODE_WALK,
};

using TPacketGCWalkMode = struct SPacketGCWalkMode
{
    BYTE    header;
    DWORD   vid;
    BYTE    mode;
};

using TPacketGCChangeSkillGroup = struct SPacketGCChangeSkillGroup
{
    BYTE        header;
    BYTE        skill_group;
};

using TPacketCGRefine = struct SPacketCGRefine
{
    BYTE    header;
    BYTE    pos;
    BYTE    type;
};

using TPacketCGRequestRefineInfo = struct SPacketCGRequestRefineInfo
{
    BYTE    header;
    BYTE    pos;
};

using TPacketGCRefineInformation = struct SPacketGCRefineInformaion
{
    BYTE    header;
    BYTE    type;
    BYTE    pos;
    DWORD   src_vnum;
    DWORD   result_vnum;
    BYTE    material_count;
    int     cost; // 소요 비용
    int     prob; // 확률
    TRefineMaterial materials[REFINE_MATERIAL_MAX_NUM];
};

struct TNPCPosition
{
    BYTE bType;
    char name[CHARACTER_NAME_MAX_LEN + 1];
    long x;
    long y;
};

using TPacketGCSpecialEffect = struct SPacketGCSpecialEffect
{
    BYTE header;
    BYTE type;
    DWORD vid;
};

using TPacketCGChangeName = struct SPacketCGChangeName
{
    BYTE header;
    BYTE index;
    char name[CHARACTER_NAME_MAX_LEN + 1];
};

using TPacketGCChangeName = struct SPacketGCChangeName
{
    BYTE header;
    DWORD pid;
    char name[CHARACTER_NAME_MAX_LEN + 1];
};


using TPacketCGClientVersion = struct command_client_version
{
    BYTE header;
    char filename[32 + 1];
    char timestamp[32 + 1];
};

using TPacketCGClientVersion2 = struct command_client_version2
{
    BYTE header;
    char filename[32 + 1];
    char timestamp[32 + 1];
};

using TPacketGCChannel = struct packet_channel
{
    BYTE header;
    BYTE channel;
};

using TPacketViewEquip = struct pakcet_view_equip
{
    BYTE  header;
    DWORD vid;
    struct
    {
        DWORD   vnum;
        BYTE    count;
        long    alSockets[ITEM_SOCKET_MAX_NUM];
        TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_MAX_NUM];
    } equips[WEAR_MAX_NUM];
};

using TLandPacketElement = struct
{
    DWORD   dwID;
    long    x, y;
    long    width, height;
    DWORD   dwGuildID;
};

using TPacketGCLandList = struct packet_land_list
{
    BYTE    header;
    WORD    size;
};

using TPacketGCTargetCreate = struct
{
    BYTE    bHeader;
    long    lID;
    char    szName[32 + 1];
    DWORD   dwVID;
    BYTE    bType;
};

using TPacketGCTargetUpdate = struct
{
    BYTE    bHeader;
    long    lID;
    long    lX, lY;
};

using TPacketGCTargetDelete = struct
{
    BYTE    bHeader;
    long    lID;
};

using TPacketGCAffectAdd = struct
{
    BYTE        bHeader;
    TPacketAffectElement elem;
};

using TPacketGCAffectRemove = struct
{
    BYTE    bHeader;
    DWORD   dwType;
    BYTE    bApplyOn;
};

using TPacketGCLoverInfo = struct packet_lover_info
{
    BYTE header;
    char name[CHARACTER_NAME_MAX_LEN + 1];
    BYTE love_point;
};

using TPacketGCLovePointUpdate = struct packet_love_point_update
{
    BYTE header;
    BYTE love_point;
};

// MINING
using TPacketGCDigMotion = struct packet_dig_motion
{
    BYTE header;
    DWORD vid;
    DWORD target_vid;
    BYTE count;
};
// END_OF_MINING

// SCRIPT_SELECT_ITEM
using TPacketCGScriptSelectItem = struct command_script_select_item
{
    BYTE header;
    DWORD selection;
};
// END_OF_SCRIPT_SELECT_ITEM

using TPacketGCDamageInfo = struct packet_damage_info
{
    BYTE header;
    DWORD dwVID;
    BYTE flag;
    int damage;
};

using TPacketGGCheckAwakeness = struct SPacketGGCheckAwakeness
{
    BYTE bHeader;
};

//TODO :  아우 짱나..가변패킷 사이즈 받아들일수 있게 패킷 핸들러 Refactoring 하자.
using TPacketGCHybridCryptKeys = struct SPacketGCHybridCryptKeys
{
        SPacketGCHybridCryptKeys() : m_pStream(NULL) {}
        ~SPacketGCHybridCryptKeys()
        {
            //GCC 에선 NULL delete 해도 괜찮나? 일단 안전하게 NULL 체크 하자. ( 근데 이거 C++ 표준아니었나 --a )
            if (m_pStream)
            {
                delete[] m_pStream;
                m_pStream = NULL;
            }
        }

        DWORD GetStreamSize()
        {
            return sizeof(bHeader) + sizeof(WORD) + sizeof(int) + KeyStreamLen;
        }

        BYTE* GetStreamData()
        {
            if (m_pStream)
            {
                delete[] m_pStream;
            }

            uDynamicPacketSize = (WORD)GetStreamSize();

            m_pStream = new BYTE[uDynamicPacketSize];

            memcpy(m_pStream, &bHeader, 1);
            memcpy(m_pStream + 1, &uDynamicPacketSize, 2);
            memcpy(m_pStream + 3, &KeyStreamLen, 4);

            if (KeyStreamLen > 0)
            {
                memcpy(m_pStream + 7, pDataKeyStream, KeyStreamLen);
            }

            return m_pStream;
        }

        BYTE    bHeader;
        WORD    uDynamicPacketSize; // 빌어먹을 클라  DynamicPacketHeader 구조때문에 맞춰줘야한다 -_-;
        int     KeyStreamLen;
        BYTE*   pDataKeyStream;

    private:
        BYTE* m_pStream;


};


using TPacketGCPackageSDB = struct SPacketGCPackageSDB
{
        SPacketGCPackageSDB() : m_pDataSDBStream(NULL), m_pStream(NULL) {}
        ~SPacketGCPackageSDB()
        {
            if (m_pStream)
            {
                delete[] m_pStream;
                m_pStream = NULL;
            }
        }

        DWORD GetStreamSize()
        {
            return sizeof(bHeader) + sizeof(WORD) + sizeof(int) + iStreamLen;
        }

        BYTE* GetStreamData()
        {
            if (m_pStream)
            {
                delete[] m_pStream;
            }

            uDynamicPacketSize =  GetStreamSize();

            m_pStream = new BYTE[uDynamicPacketSize];

            memcpy(m_pStream, &bHeader, 1);
            memcpy(m_pStream + 1, &uDynamicPacketSize, 2);
            memcpy(m_pStream + 3, &iStreamLen, 4);

            if (iStreamLen > 0)
            {
                memcpy(m_pStream + 7, m_pDataSDBStream, iStreamLen);
            }

            return m_pStream;
        }

        BYTE    bHeader;
        WORD    uDynamicPacketSize; // 빌어먹을 클라  DynamicPacketHeader 구조때문에 맞춰줘야한다 -_-;
        int     iStreamLen;
        BYTE*   m_pDataSDBStream;

    private:
        BYTE* m_pStream;


};

#ifdef _IMPROVED_PACKET_ENCRYPTION_
struct TPacketKeyAgreement
{
    static const int MAX_DATA_LEN = 256;
    BYTE bHeader;
    WORD wAgreedLength;
    WORD wDataLength;
    BYTE data[MAX_DATA_LEN];
};

struct TPacketKeyAgreementCompleted
{
    BYTE bHeader;
    BYTE data[3]; // dummy (not used)
};

#endif // _IMPROVED_PACKET_ENCRYPTION_

#define MAX_EFFECT_FILE_NAME 128
using TPacketGCSpecificEffect = struct SPacketGCSpecificEffect
{
    BYTE header;
    DWORD vid;
    char effect_file[MAX_EFFECT_FILE_NAME];
};

// 용혼석
enum EDragonSoulRefineWindowRefineType
{
    DragonSoulRefineWindow_UPGRADE,
    DragonSoulRefineWindow_IMPROVEMENT,
    DragonSoulRefineWindow_REFINE,
};

enum EPacketCGDragonSoulSubHeaderType
{
    DS_SUB_HEADER_OPEN,
    DS_SUB_HEADER_CLOSE,
    DS_SUB_HEADER_DO_REFINE_GRADE,
    DS_SUB_HEADER_DO_REFINE_STEP,
    DS_SUB_HEADER_DO_REFINE_STRENGTH,
    DS_SUB_HEADER_REFINE_FAIL,
    DS_SUB_HEADER_REFINE_FAIL_MAX_REFINE,
    DS_SUB_HEADER_REFINE_FAIL_INVALID_MATERIAL,
    DS_SUB_HEADER_REFINE_FAIL_NOT_ENOUGH_MONEY,
    DS_SUB_HEADER_REFINE_FAIL_NOT_ENOUGH_MATERIAL,
    DS_SUB_HEADER_REFINE_FAIL_TOO_MUCH_MATERIAL,
    DS_SUB_HEADER_REFINE_SUCCEED,
};
using TPacketCGDragonSoulRefine = struct SPacketCGDragonSoulRefine
{
    SPacketCGDragonSoulRefine() : header(HEADER_CG_DRAGON_SOUL_REFINE)
    {}
    BYTE header;
    BYTE bSubType;
    TItemPos ItemGrid[DRAGON_SOUL_REFINE_GRID_SIZE];
};

using TPacketGCDragonSoulRefine = struct SPacketGCDragonSoulRefine
{
    SPacketGCDragonSoulRefine() : header(HEADER_GC_DRAGON_SOUL_REFINE)
    {}
    BYTE header;
    BYTE bSubType;
    TItemPos Pos;
};

using TPacketCGStateCheck = struct SPacketCGStateCheck
{
    BYTE header;
    unsigned long key;
    unsigned long index;
};

using TPacketGCStateCheck = struct SPacketGCStateCheck
{
    BYTE header;
    unsigned long key;
    unsigned long index;
    unsigned char state;
};

#pragma pack()
#endif
