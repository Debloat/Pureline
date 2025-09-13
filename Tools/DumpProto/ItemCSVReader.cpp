#include <math.h>
#include <span>
#include "ItemCSVReader.h"

using namespace std;

inline string trim_left (const string& str)
{
    string::size_type n = str.find_first_not_of (" \t\v\n\r");
    return n == string::npos ? str : str.substr (n, str.length());
}

inline string trim_right (const string& str)
{
    string::size_type n = str.find_last_not_of (" \t\v\n\r");
    return n == string::npos ? str : str.substr (0, n + 1);
}

string trim (const string& str)
{
    return trim_left (trim_right (str));
}

static string* StringSplit (string strOrigin, string strTok)
{
    int cutAt;                              //자르는위치
    int index = 0;                          //문자열인덱스
    string* strResult = new string[30];     //결과return 할변수

    //strTok을찾을때까지반복
    while ((cutAt = strOrigin.find_first_of (strTok)) != strOrigin.npos)
    {
        if (cutAt > 0)  //자르는위치가0보다크면(성공시)
        {
            strResult[index++] = strOrigin.substr (0, cutAt); //결과배열에추가
        }
        strOrigin = strOrigin.substr (cutAt + 1); //원본은자른부분제외한나머지
    }

    if (strOrigin.length() > 0)  //원본이아직남았으면
    {
        strResult[index++] = strOrigin.substr (0, cutAt); //나머지를결과배열에추가
    }

    for (int i = 0; i < index; i++)
    {
        strResult[i] = trim (strResult[i]);
    }

    return strResult;  //결과return
}


int get_Item_Type_Value (string inputString)
{
    string arType[] =
    {
        "ITEM_NONE",            // 0
        "ITEM_WEAPON",          // 1
        "ITEM_ARMOR",           // 2
        "ITEM_USE",             // 3
        "ITEM_AUTOUSE",         // 4
        "ITEM_MATERIAL",        // 5
        "ITEM_SPECIAL",         // 6
        "ITEM_TOOL",            // 7
        "ITEM_ELK",             // 8

        "ITEM_METIN",           // 9
        "ITEM_CONTAINER",       // 10
        "ITEM_FISH",            // 11
        "ITEM_ROD",             // 12
        "ITEM_RESOURCE",        // 13
        "ITEM_CAMPFIRE",        // 14
        "ITEM_UNIQUE",          // 15
        "ITEM_SKILLBOOK",       // 16
        "ITEM_QUEST",           // 17
        "ITEM_POLYMORPH",       // 18

        "ITEM_TREASURE_BOX",    // 19
        "ITEM_TREASURE_KEY",    // 20
        "ITEM_SKILLFORGET",     // 21
        "ITEM_GIFTBOX",         // 22
        "ITEM_PICK",            // 23
        "ITEM_HAIR",            // 24
        "ITEM_TOTEM",           // 25
        "ITEM_BLEND",           // 26
        "ITEM_COSTUME",         // 27
        "ITEM_DS",              // 28

        "ITEM_SPECIAL_DS",      // 29
        "ITEM_EXTRACT",         // 30
        "ITEM_SECONDARY_COIN",  // 31

        "ITEM_RING",            // 32
        "ITEM_BELT"             // 33 (EItemTypes 33)
    };


    int retInt = -1;
    //cout << "Type : " << typeStr << " -> ";
    for (int j = 0; j < std::size (arType); j++)
    {
        string tempString = arType[j];
        if (inputString.contains (tempString) && tempString.contains (inputString))
        {
            //cout << j << " ";
            retInt = j;
            break;
        }
    }
    //cout << endl;

    return retInt;

}

int get_Item_SubType_Value (int type_value, string inputString)
{
    static string arSub1[]  =
    {
        "WEAPON_SWORD",
        "WEAPON_DAGGER",
        "WEAPON_BOW",
        "WEAPON_TWO_HANDED",
        "WEAPON_BELL",
        "WEAPON_FAN",
        "WEAPON_ARROW",
        "WEAPON_MOUNT_SPEAR"
    };

    static string arSub2[]  =
    {
        "ARMOR_BODY",
        "ARMOR_HEAD",
        "ARMOR_SHIELD",
        "ARMOR_WRIST",
        "ARMOR_FOOTS",
        "ARMOR_NECK",
        "ARMOR_EAR",
        "ARMOR_NUM_TYPES"
    };

    static string arSub3[]  =
    {
        "USE_POTION",
        "USE_TALISMAN",
        "USE_TUNING",
        "USE_MOVE",
        "USE_TREASURE_BOX",
        "USE_MONEYBAG",
        "USE_BAIT",
        "USE_ABILITY_UP",
        "USE_AFFECT",
        "USE_CREATE_STONE",
        "USE_SPECIAL",
        "USE_POTION_NODELAY",
        "USE_CLEAR",
        "USE_INVISIBILITY",
        "USE_DETACHMENT",
        "USE_BUCKET",
        "USE_POTION_CONTINUE",
        "USE_CLEAN_SOCKET",
        "USE_CHANGE_ATTRIBUTE",
        "USE_ADD_ATTRIBUTE",
        "USE_ADD_ACCESSORY_SOCKET",
        "USE_PUT_INTO_ACCESSORY_SOCKET",
        "USE_ADD_ATTRIBUTE2",
        "USE_RECIPE",
        "USE_CHANGE_ATTRIBUTE2",
        "USE_BIND",
        "USE_UNBIND",
        "USE_TIME_CHARGE_PER",
        "USE_TIME_CHARGE_FIX",
        "USE_PUT_INTO_BELT_SOCKET",
        "USE_PUT_INTO_RING_SOCKET"
    };

    static string arSub4[]  =
    {
        "AUTOUSE_POTION",
        "AUTOUSE_ABILITY_UP",
        "AUTOUSE_BOMB",
        "AUTOUSE_GOLD",
        "AUTOUSE_MONEYBAG",
        "AUTOUSE_TREASURE_BOX"
    };

    static string arSub5[]  =
    {
        "MATERIAL_LEATHER",
        "MATERIAL_BLOOD",
        "MATERIAL_ROOT",
        "MATERIAL_NEEDLE",
        "MATERIAL_JEWEL",
        "MATERIAL_DS_REFINE_NORMAL",
        "MATERIAL_DS_REFINE_BLESSED",
        "MATERIAL_DS_REFINE_HOLLY"
    };

    static string arSub6[]  =
    {
        "SPECIAL_MAP",
        "SPECIAL_KEY",
        "SPECIAL_DOC",
        "SPECIAL_SPIRIT"
    };

    static string arSub7[]  =
    {
        "TOOL_FISHING_ROD"
    };

    static string arSub9[]  =
    {
        "METIN_NORMAL",
        "METIN_GOLD"
    };

    static string arSub11[] =
    {
        "FISH_ALIVE",
        "FISH_DEAD"
    };

    static string arSub13[] =
    {
        "RESOURCE_FISHBONE",
        "RESOURCE_WATERSTONEPIECE",
        "RESOURCE_WATERSTONE",
        "RESOURCE_BLOOD_PEARL",
        "RESOURCE_BLUE_PEARL",
        "RESOURCE_WHITE_PEARL",
        "RESOURCE_BUCKET",
        "RESOURCE_CRYSTAL",
        "RESOURCE_GEM",
        "RESOURCE_STONE",
        "RESOURCE_METIN",
        "RESOURCE_ORE"
    };

    static string arSub15[] =
    {
        "UNIQUE_NONE",
        "UNIQUE_BOOK",
        "UNIQUE_SPECIAL_RIDE",
        "UNIQUE_3",
        "UNIQUE_4",
        "UNIQUE_5",
        "UNIQUE_6",
        "UNIQUE_7",
        "UNIQUE_8",
        "UNIQUE_9",
        "USE_SPECIAL"
    };

    static string arSub27[] =
    {
        "COSTUME_BODY",
        "COSTUME_HAIR"
    };

    static string arSub28[] =
    {
        "DS_SLOT1",
        "DS_SLOT2",
        "DS_SLOT3",
        "DS_SLOT4",
        "DS_SLOT5",
        "DS_SLOT6"
    };

    static string arSub30[] =
    {
        "EXTRACT_DRAGON_SOUL",
        "EXTRACT_DRAGON_HEART"
    };

    static string* arSubType[] =
    {
        nullptr,    //0
        arSub1,     //1
        arSub2,     //2
        arSub3,     //3
        arSub4,     //4
        arSub5,     //5
        arSub6,     //6
        arSub7,     //7
        nullptr,    //8
        arSub9,     //9
        nullptr,    //10
        arSub11,    //11
        nullptr,    //12
        arSub13,    //13
        nullptr,    //14
        arSub15,    //15
        nullptr,    //16
        nullptr,    //17
        nullptr,    //18
        nullptr,    //19
        nullptr,    //20
        nullptr,    //21
        nullptr,    //22
        nullptr,    //23
        nullptr,    //24
        nullptr,    //25
        nullptr,    //26
        arSub27,    //27
        arSub28,    //28
        arSub28,    //29
        arSub30,    //30
        nullptr,    //31
        nullptr,    //32
        nullptr     //33
    };
    static int arNumberOfSubtype[_countof (arSubType)] =
    {
        0,                                  // 0
        std::size (arSub1), // 1
        std::size (arSub2), // 2
        std::size (arSub3), // 3
        std::size (arSub4), // 4
        std::size (arSub5), // 5
        std::size (arSub6), // 6
        std::size (arSub7), // 7
        0,                  // 8
        std::size (arSub9), // 9
        0,                  // 10
        std::size (arSub11),    // 11
        0,                  // 12
        std::size (arSub13),    // 13
        0,                  // 14
        std::size (arSub15),    // 15
        0,                  // 16
        0,                  // 17
        0,                  // 18
        0,                  // 19
        0,                  // 20
        0,                  // 21
        0,                  // 22
        0,                  // 23
        0,                  // 24
        0,                  // 25
        0,                  // 26
        std::size (arSub27),    // 27
        std::size (arSub28),    // 28
        std::size (arSub28),    // 29
        std::size (arSub30),    // 30
        0,                  // 31
        0,                  // 32 반지
        0                   // 33 벨트
    };

    //아이템 타입의 서브타입 어레이가 존재하는지 알아보고, 없으면 0 리턴
    if (arSubType[type_value] == nullptr)
    {
        return 0;
    }
    //

    int retInt = -1;
    //cout << "SubType : " << subTypeStr << " -> ";
    for (int j = 0; j < arNumberOfSubtype[type_value]; j++)
    {
        string tempString = arSubType[type_value][j];
        string tempInputString = trim (inputString);
        if (tempInputString.compare (tempString) == 0)
        {
            //cout << j << " ";
            retInt = j;
            break;
        }
    }
    //cout << endl;

    return retInt;
}

int get_Item_AntiFlag_Value (string inputString)
{

    string arAntiFlag[] =
    {
        "ANTI_FEMALE",      // 0
        "ANTI_MALE",        // 1
        "ANTI_MUSA",        // 2
        "ANTI_ASSASSIN",    // 3
        "ANTI_SURA",        // 4
        "ANTI_MUDANG",      // 5
        "ANTI_GET",         // 6
        "ANTI_DROP",        // 7
        "ANTI_SELL",        // 8
        "ANTI_EMPIRE_A",    // 9
        "ANTI_EMPIRE_B",    // 10
        "ANTI_EMPIRE_C",    // 11
        "ANTI_SAVE",        // 12
        "ANTI_GIVE",        // 13
        "ANTI_PKDROP",      // 14
        "ANTI_STACK",       // 15
        "ANTI_MYSHOP",      // 16
        "ANTI_SAFEBOX"      // 17
    };

    int retValue = 0;
    string* arInputString = StringSplit (inputString, "|");             //프로토 정보 내용을 단어별로 쪼갠 배열.
    for (int i = 0; i < std::size (arAntiFlag); i++)
    {
        string tempString = arAntiFlag[i];
        for (int j = 0; j < 30; j++)        //최대 30개 단어까지. (하드코딩)
        {
            string tempString2 = arInputString[j];
            if (tempString2.compare (tempString) == 0)                  //일치하는지 확인.
            {
                retValue = retValue + pow ((float)2, (float)i);
            }

            if (tempString2.compare ("") == 0)
            {
                break;
            }
        }
    }
    delete[]arInputString;
    //cout << "AntiFlag : " << antiFlagStr << " -> " << retValue << endl;

    return retValue;
}

int get_Item_Flag_Value (string inputString)
{

    string arFlag[] =
    {
        "ITEM_TUNABLE",         // 0
        "ITEM_SAVE",            // 1
        "ITEM_STACKABLE",       // 2
        "COUNT_PER_1GOLD",      // 3
        "ITEM_SLOW_QUERY",      // 4
        "ITEM_UNIQUE",          // 5
        "ITEM_MAKECOUNT",       // 6
        "ITEM_IRREMOVABLE",     // 7
        "CONFIRM_WHEN_USE",     // 8
        "QUEST_USE",            // 9
        "QUEST_USE_MULTIPLE",   // 10
        "QUEST_GIVE",           // 11
        "ITEM_QUEST",           // 12
        "LOG",                  // 13
        "STACKABLE",            // 14
        "SLOW_QUERY",           // 15
        "REFINEABLE",           // 16
        "IRREMOVABLE",          // 17
        "ITEM_APPLICABLE"       // 18
    };

    int retValue = 0;
    string* arInputString = StringSplit (inputString, "|");             //프로토 정보 내용을 단어별로 쪼갠 배열.
    for (int i = 0; i < std::size (arFlag); i++)
    {
        string tempString = arFlag[i];
        for (int j = 0; j < 30; j++)        //최대 30개 단어까지. (하드코딩)
        {
            string tempString2 = arInputString[j];
            if (tempString2.compare (tempString) == 0)                  //일치하는지 확인.
            {
                retValue = retValue + pow ((float)2, (float)i);
            }

            if (tempString2.compare ("") == 0)
            {
                break;
            }
        }
    }
    delete[]arInputString;
    //cout << "Flag : " << flagStr << " -> " << retValue << endl;

    return retValue;
}

int get_Item_WearFlag_Value (string inputString)
{

    string arWearrFlag[] =
    {
        "WEAR_BODY",    // 0
        "WEAR_HEAD",    // 1
        "WEAR_FOOTS",   // 2
        "WEAR_WRIST",   // 3
        "WEAR_WEAPON",  // 4
        "WEAR_NECK",    // 5
        "WEAR_EAR",     // 6
        "WEAR_SHIELD",  // 7
        "WEAR_UNIQUE",  // 8
        "WEAR_ARROW",   // 9
        "WEAR_HAIR",    // 10
        "WEAR_ABILITY"  // 11
    };

    int retValue = 0;
    string* arInputString = StringSplit (inputString, "|");             //프로토 정보 내용을 단어별로 쪼갠 배열.
    for (int i = 0; i < std::size (arWearrFlag); i++)
    {
        string tempString = arWearrFlag[i];
        for (int j = 0; j < 30; j++)        //최대 30개 단어까지. (하드코딩)
        {
            string tempString2 = arInputString[j];
            if (tempString2.compare (tempString) == 0)                  //일치하는지 확인.
            {
                retValue = retValue + pow ((float)2, (float)i);
            }

            if (tempString2.compare ("") == 0)
            {
                break;
            }
        }
    }
    delete[]arInputString;
    //cout << "WearFlag : " << wearFlagStr << " -> " << retValue << endl;

    return retValue;
}

int get_Item_Immune_Value (string inputString)
{

    string arImmune[] =
    {
        "PARA",
        "CURSE",
        "STUN",
        "SLEEP",
        "SLOW",
        "POISON",
        "TERROR"
    };

    int retValue = 0;
    string* arInputString = StringSplit (inputString, "|");             //프로토 정보 내용을 단어별로 쪼갠 배열.
    for (int i = 0; i < std::size (arImmune); i++)
    {
        string tempString = arImmune[i];
        for (int j = 0; j < 30; j++)        //최대 30개 단어까지. (하드코딩)
        {
            string tempString2 = arInputString[j];
            if (tempString2.compare (tempString) == 0)                  //일치하는지 확인.
            {
                retValue = retValue + pow ((float)2, (float)i);
            }

            if (tempString2.compare ("") == 0)
            {
                break;
            }
        }
    }
    delete[]arInputString;
    //cout << "Immune : " << immuneStr << " -> " << retValue << endl;

    return retValue;
}


int get_Item_LimitType_Value (string inputString)
{
    string arLimitType[] =
    {
        "LIMIT_NONE",
        "LEVEL",
        "STR",
        "DEX",
        "INT",
        "CON",
        "REAL_TIME",
        "REAL_TIME_FIRST_USE",
        "TIMER_BASED_ON_WEAR"
    };

    int retInt = -1;
    //cout << "LimitType : " << limitTypeStr << " -> ";
    for (int j = 0; j < std::size (arLimitType); j++)
    {
        string tempString = arLimitType[j];
        string tempInputString = trim (inputString);
        if (tempInputString.compare (tempString) == 0)
        {
            //cout << j << " ";
            retInt = j;
            break;
        }
    }
    //cout << endl;

    return retInt;
}


int get_Item_ApplyType_Value (string inputString)
{
    string arApplyType[] =
    {
        "APPLY_NONE",
        "APPLY_MAX_HP",
        "APPLY_MAX_SP",
        "APPLY_CON",
        "APPLY_INT",
        "APPLY_STR",
        "APPLY_DEX",
        "APPLY_ATT_SPEED",
        "APPLY_MOV_SPEED",
        "APPLY_CAST_SPEED",
        "APPLY_HP_REGEN",
        "APPLY_SP_REGEN",
        "APPLY_POISON_PCT",
        "APPLY_STUN_PCT",
        "APPLY_SLOW_PCT",
        "APPLY_CRITICAL_PCT",
        "APPLY_PENETRATE_PCT",
        "APPLY_ATTBONUS_HUMAN",
        "APPLY_ATTBONUS_ANIMAL",
        "APPLY_ATTBONUS_ORC",
        "APPLY_ATTBONUS_MILGYO",
        "APPLY_ATTBONUS_UNDEAD",
        "APPLY_ATTBONUS_DEVIL",
        "APPLY_STEAL_HP",
        "APPLY_STEAL_SP",
        "APPLY_MANA_BURN_PCT",
        "APPLY_DAMAGE_SP_RECOVER",
        "APPLY_BLOCK",
        "APPLY_DODGE",
        "APPLY_RESIST_SWORD",
        "APPLY_RESIST_TWOHAND",
        "APPLY_RESIST_DAGGER",
        "APPLY_RESIST_BELL",
        "APPLY_RESIST_FAN",
        "APPLY_RESIST_BOW",
        "APPLY_RESIST_FIRE",
        "APPLY_RESIST_ELEC",
        "APPLY_RESIST_MAGIC",
        "APPLY_RESIST_WIND",
        "APPLY_REFLECT_MELEE",
        "APPLY_REFLECT_CURSE",
        "APPLY_POISON_REDUCE",
        "APPLY_KILL_SP_RECOVER",
        "APPLY_EXP_DOUBLE_BONUS",
        "APPLY_GOLD_DOUBLE_BONUS",
        "APPLY_ITEM_DROP_BONUS",
        "APPLY_POTION_BONUS",
        "APPLY_KILL_HP_RECOVER",
        "APPLY_IMMUNE_STUN",
        "APPLY_IMMUNE_SLOW",
        "APPLY_IMMUNE_FALL",
        "APPLY_SKILL",
        "APPLY_BOW_DISTANCE",
        "APPLY_ATT_GRADE_BONUS",
        "APPLY_DEF_GRADE_BONUS",
        "APPLY_MAGIC_ATT_GRADE",
        "APPLY_MAGIC_DEF_GRADE",
        "APPLY_CURSE_PCT",
        "APPLY_MAX_STAMINA",
        "APPLY_ATTBONUS_WARRIOR",
        "APPLY_ATTBONUS_ASSASSIN",
        "APPLY_ATTBONUS_SURA",
        "APPLY_ATTBONUS_SHAMAN",
        "APPLY_ATTBONUS_MONSTER",
        "APPLY_MALL_ATTBONUS",
        "APPLY_MALL_DEFBONUS",
        "APPLY_MALL_EXPBONUS",
        "APPLY_MALL_ITEMBONUS",
        "APPLY_MALL_GOLDBONUS",
        "APPLY_MAX_HP_PCT",
        "APPLY_MAX_SP_PCT",
        "APPLY_SKILL_DAMAGE_BONUS",
        "APPLY_NORMAL_HIT_DAMAGE_BONUS",
        "APPLY_SKILL_DEFEND_BONUS",
        "APPLY_NORMAL_HIT_DEFEND_BONUS",
        "APPLY_EXTRACT_HP_PCT",
        "APPLY_RESIST_WARRIOR",
        "APPLY_RESIST_ASSASSIN",
        "APPLY_RESIST_SURA",
        "APPLY_RESIST_SHAMAN",
        "APPLY_ENERGY",
        "APPLY_DEF_GRADE",
        "APPLY_COSTUME_ATTR_BONUS",
        "APPLY_MAGIC_ATTBONUS_PER",
        "APPLY_MELEE_MAGIC_ATTBONUS_PER",
        "APPLY_RESIST_ICE",
        "APPLY_RESIST_EARTH",
        "APPLY_RESIST_DARK",
        "APPLY_ANTI_CRITICAL_PCT",
        "APPLY_ANTI_PENETRATE_PCT"
    };

    int retInt = -1;
    //cout << "ApplyType : " << applyTypeStr << " -> ";
    for (int j = 0; j < std::size (arApplyType); j++)
    {
        string tempString = arApplyType[j];
        string tempInputString = trim (inputString);
        if (tempInputString.compare (tempString) == 0)
        {
            //cout << j << " ";
            retInt = j;
            break;
        }
    }
    //cout << endl;

    return retInt;

}


//몬스터 프로토도 읽는다.


int get_Mob_Rank_Value (string inputString)
{
    string arRank[] =
    {
        "PAWN",
        "S_PAWN",
        "KNIGHT",
        "S_KNIGHT",
        "BOSS",
        "KING"
    };

    int retInt = -1;
    //cout << "Rank : " << rankStr << " -> ";
    for (int j = 0; j < std::size (arRank); j++)
    {
        string tempString = arRank[j];
        string tempInputString = trim (inputString);
        if (tempInputString.compare (tempString) == 0)
        {
            //cout << j << " ";
            retInt = j;
            break;
        }
    }
    //cout << endl;

    return retInt;
}


int get_Mob_Type_Value (string inputString)
{
    string arType[] =
    {
        "MONSTER",
        "NPC",
        "STONE",
        "WARP",
        "DOOR",
        "BUILDING",
        "PC",
        "POLYMORPH_PC",
        "HORSE",
        "GOTO"
    };

    int retInt = -1;
    //cout << "Type : " << typeStr << " -> ";
    for (int j = 0; j < std::size (arType); j++)
    {
        string tempString = arType[j];
        string tempInputString = trim (inputString);
        if (tempInputString.compare (tempString) == 0)
        {
            //cout << j << " ";
            retInt = j;
            break;
        }
    }
    //cout << endl;

    return retInt;
}

int get_Mob_BattleType_Value (string inputString)
{
    string arBattleType[] =
    {
        "MELEE",
        "RANGE",
        "MAGIC",
        "SPECIAL",
        "POWER",
        "TANKER",
        "SUPER_POWER",
        "SUPER_TANKER"
    };

    int retInt = -1;
    //cout << "Battle Type : " << battleTypeStr << " -> ";
    for (int j = 0; j < std::size (arBattleType); j++)
    {
        string tempString = arBattleType[j];
        string tempInputString = trim (inputString);
        if (tempInputString.compare (tempString) == 0)
        {
            //cout << j << " ";
            retInt = j;
            break;
        }
    }
    //cout << endl;

    return retInt;
}

int get_Mob_Size_Value (string inputString)
{
    string arSize[] =
    {
        /* - YOSUN_DUMP_PROTO_FIX_001 -------------------------- */
        "SMALL",
        /* ----------------------------------------------------- */
        "MEDIUM",
        "BIG"
    };

    int retInt = 0;
    //cout << "Size : " << sizeStr << " -> ";
    for (int j = 0; j < std::size (arSize); j++)
    {
        string tempString = arSize[j];
        string tempInputString = trim (inputString);
        if (tempInputString.compare (tempString) == 0)
        {
            //cout << j << " ";
            retInt = j + 1;
            break;
        }
    }
    //cout << endl;

    return retInt;
}

int get_Mob_AIFlag_Value (string inputString)
{
    string arAIFlag[] =
    {
        "AGGR",
        "NOMOVE",
        "COWARD",
        "NOATTSHINSU",
        "NOATTCHUNJO",
        "NOATTJINNO",
        "ATTMOB",
        "BERSERK",
        "STONESKIN",
        "GODSPEED",
        "DEATHBLOW",
        "REVIVE"
    };


    int retValue = 0;
    string* arInputString = StringSplit (inputString, ",");             //프로토 정보 내용을 단어별로 쪼갠 배열.
    for (int i = 0; i < std::size (arAIFlag); i++)
    {
        string tempString = arAIFlag[i];
        for (int j = 0; j < 30; j++)        //최대 30개 단어까지. (하드코딩)
        {
            string tempString2 = arInputString[j];
            if (tempString2.compare (tempString) == 0)                  //일치하는지 확인.
            {
                retValue = retValue + pow ((float)2, (float)i);
            }

            if (tempString2.compare ("") == 0)
            {
                break;
            }
        }
    }
    delete[]arInputString;
    //cout << "AIFlag : " << aiFlagStr << " -> " << retValue << endl;

    return retValue;
}

int get_Mob_RaceFlag_Value (string inputString)
{
    string arRaceFlag[] =
    {
        "ANIMAL",
        "UNDEAD",
        "DEVIL",
        "HUMAN",
        "ORC",
        "MILGYO",
        "INSECT",
        "FIRE",
        "ICE",
        "DESERT",
        "TREE",
        "ATT_ELEC",
        "ATT_FIRE",
        "ATT_ICE",
        "ATT_WIND",
        "ATT_EARTH",
        "ATT_DARK"
    };

    int retValue = 0;
    string* arInputString = StringSplit (inputString, "|");             //프로토 정보 내용을 단어별로 쪼갠 배열.
    for (int i = 0; i < std::size (arRaceFlag); i++)
    {
        string tempString = arRaceFlag[i];
        for (int j = 0; j < 30; j++)        //최대 30개 단어까지. (하드코딩)
        {
            string tempString2 = arInputString[j];
            if (tempString2.compare (tempString) == 0)                  //일치하는지 확인.
            {
                retValue = retValue + pow ((float)2, (float)i);
            }

            if (tempString2.compare ("") == 0)
            {
                break;
            }
        }
    }
    delete[]arInputString;
    //cout << "Race Flag : " << raceFlagStr << " -> " << retValue << endl;

    return retValue;
}
int get_Mob_ImmuneFlag_Value (string inputString)
{
    string arImmuneFlag[] =
    {
        "STUN",
        "SLOW",
        "FALL",
        "CURSE",
        "POISON",
        "TERROR"
    };

    int retValue = 0;
    string* arInputString = StringSplit (inputString, ",");             //프로토 정보 내용을 단어별로 쪼갠 배열.
    for (int i = 0; i < std::size (arImmuneFlag); i++)
    {
        string tempString = arImmuneFlag[i];
        for (int j = 0; j < 30; j++)        //최대 30개 단어까지. (하드코딩)
        {
            string tempString2 = arInputString[j];
            if (tempString2.compare (tempString) == 0)                  //일치하는지 확인.
            {
                retValue = retValue + pow ((float)2, (float)i);
            }

            if (tempString2.compare ("") == 0)
            {
                break;
            }
        }
    }
    delete[]arInputString;
    //cout << "Immune Flag : " << immuneFlagStr << " -> " << retValue << endl;


    return retValue;
}
