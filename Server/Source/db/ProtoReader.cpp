#include "stdafx.h"

#include <math.h>
#include "ProtoReader.h"

#include "CsvReader.h"

#include <span>
#include <sstream>

using namespace std;

inline static string trim_left(const string& str)
{
    string::size_type n = str.find_first_not_of(" \t\v\n\r");
    return n == string::npos ? str : str.substr(n, str.length());
}

inline static string trim_right(const string& str)
{
    string::size_type n = str.find_last_not_of(" \t\v\n\r");
    return n == string::npos ? str : str.substr(0, n + 1);
}

string trim(const string& str)
{
    return trim_left(trim_right(str));
}

static string* StringSplit(string strOrigin, string strTok)
{
    int     cutAt;                            //ÀÚ¸£´ÂÀ§Ä¡
    int     index     = 0;                    //¹®ÀÚ¿­ÀÎµ¦½º
    auto* strResult = new string[30];       //°á°úreturn ÇÒº¯¼ö

    //strTokÀ»Ã£À»¶§±îÁö¹Ýº¹
    while ((cutAt = strOrigin.find_first_of(strTok)) != strOrigin.npos)
    {
        if (cutAt > 0)  //ÀÚ¸£´ÂÀ§Ä¡°¡0º¸´ÙÅ©¸é(¼º°ø½Ã)
        {
            strResult[index++] = strOrigin.substr(0, cutAt);  //°á°ú¹è¿­¿¡Ãß°¡
        }
        strOrigin = strOrigin.substr(cutAt + 1);  //¿øº»ÀºÀÚ¸¥ºÎºÐÁ¦¿ÜÇÑ³ª¸ÓÁö
    }

    if (strOrigin.length() > 0) //¿øº»ÀÌ¾ÆÁ÷³²¾ÒÀ¸¸é
    {
        strResult[index++] = strOrigin.substr(0, cutAt);  //³ª¸ÓÁö¸¦°á°ú¹è¿­¿¡Ãß°¡
    }

    for (int i = 0; i < index; i++)
    {
        strResult[i] = trim(strResult[i]);
    }

    return strResult;  //°á°úreturn
}


int get_Item_Type_Value(string inputString)
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
    for (int j = 0; j < std::size(arType); j++)
    {
        string tempString = arType[j];
        if (inputString.contains(tempString) && tempString.contains(inputString))
        {
            //cout << j << " ";
            retInt =  j;
            break;
        }
    }
    //cout << endl;

    return retInt;

}

int get_Item_SubType_Value(int type_value, string inputString)
{
    static string arSub1[] =
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

    static string arSub2[] =
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

    static string arSub3[] =
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

    static string arSub4[] =
    {
        "AUTOUSE_POTION",
        "AUTOUSE_ABILITY_UP",
        "AUTOUSE_BOMB",
        "AUTOUSE_GOLD",
        "AUTOUSE_MONEYBAG",
        "AUTOUSE_TREASURE_BOX"
    };

    static string arSub5[] =
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

    static string arSub6[] =
    {
        "SPECIAL_MAP",
        "SPECIAL_KEY",
        "SPECIAL_DOC",
        "SPECIAL_SPIRIT"
    };

    static string arSub7[] =
    {
        "TOOL_FISHING_ROD"
    };

    static string arSub9[] =
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
        nullptr,            //0
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

    static int arNumberOfSubtype[_countof(arSubType)] =
    {
        0,                                  // 0
        std::size(arSub1),  // 1
        std::size(arSub2),  // 2
        std::size(arSub3),  // 3
        std::size(arSub4),  // 4
        std::size(arSub5),  // 5
        std::size(arSub6),  // 6
        std::size(arSub7),  // 7
        0,                  // 8
        std::size(arSub9),  // 9
        0,                  // 10
        std::size(arSub11),     // 11
        0,                  // 12
        std::size(arSub13),     // 13
        0,                  // 14
        std::size(arSub15),     // 15
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
        std::size(arSub27),     // 27
        std::size(arSub28),     // 28
        std::size(arSub28),     // 29
        std::size(arSub30),     // 30
        0,                  // 31
        0,                  // 32 ¹ÝÁö
        0,                  // 33 º§Æ®
    };


    assert(_countof(arSubType) > type_value && "Subtype rule: Out of range!!");

    // assert ¾È ¸ÔÈ÷´Â µí..
    if (_countof(arSubType) <= type_value)
    {
        sys_err("SubType : Out of range!! (type_value: %d, count of registered subtype: %d", type_value, _countof(arSubType));
        return -1;
    }

    //¾ÆÀÌÅÛ Å¸ÀÔÀÇ ¼­ºêÅ¸ÀÔ ¾î·¹ÀÌ°¡ Á¸ÀçÇÏ´ÂÁö ¾Ë¾Æº¸°í, ¾øÀ¸¸é 0 ¸®ÅÏ
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
        string tempInputString = trim(inputString);
        if (tempInputString.compare(tempString) == 0)
        {
            //cout << j << " ";
            retInt =  j;
            break;
        }
    }
    //cout << endl;

    return retInt;
}


int get_Item_AntiFlag_Value(string inputString)
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
    string* arInputString = StringSplit(inputString, "|");              //ÇÁ·ÎÅä Á¤º¸ ³»¿ëÀ» ´Ü¾îº°·Î ÂÉ°µ ¹è¿­.
    for (int i = 0; i < std::size(arAntiFlag); i++)
    {
        string tempString = arAntiFlag[i];
        for (int j = 0; j < 30 ; j++)       //ÃÖ´ë 30°³ ´Ü¾î±îÁö. (ÇÏµåÄÚµù)
        {
            string tempString2 = arInputString[j];
            if (tempString2.compare(tempString) == 0)                   //ÀÏÄ¡ÇÏ´ÂÁö È®ÀÎ.
            {
                retValue = retValue + pow((float)2, (float)i);
            }

            if (tempString2.compare("") == 0)
            {
                break;
            }
        }
    }
    delete []arInputString;
    //cout << "AntiFlag : " << antiFlagStr << " -> " << retValue << endl;

    return retValue;
}

int get_Item_Flag_Value(string inputString)
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
    string* arInputString = StringSplit(inputString, "|");              //ÇÁ·ÎÅä Á¤º¸ ³»¿ëÀ» ´Ü¾îº°·Î ÂÉ°µ ¹è¿­.
    for (int i = 0; i < std::size(arFlag); i++)
    {
        string tempString = arFlag[i];
        for (int j = 0; j < 30 ; j++)       //ÃÖ´ë 30°³ ´Ü¾î±îÁö. (ÇÏµåÄÚµù)
        {
            string tempString2 = arInputString[j];
            if (tempString2.compare(tempString) == 0)                   //ÀÏÄ¡ÇÏ´ÂÁö È®ÀÎ.
            {
                retValue = retValue + pow((float)2, (float)i);
            }

            if (tempString2.compare("") == 0)
            {
                break;
            }
        }
    }
    delete []arInputString;
    //cout << "Flag : " << flagStr << " -> " << retValue << endl;

    return retValue;
}

int get_Item_WearFlag_Value(string inputString)
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
    string* arInputString = StringSplit(inputString, "|");              //ÇÁ·ÎÅä Á¤º¸ ³»¿ëÀ» ´Ü¾îº°·Î ÂÉ°µ ¹è¿­.
    for (int i = 0; i < std::size(arWearrFlag); i++)
    {
        string tempString = arWearrFlag[i];
        for (int j = 0; j < 30 ; j++)       //ÃÖ´ë 30°³ ´Ü¾î±îÁö. (ÇÏµåÄÚµù)
        {
            string tempString2 = arInputString[j];
            if (tempString2.compare(tempString) == 0)                   //ÀÏÄ¡ÇÏ´ÂÁö È®ÀÎ.
            {
                retValue = retValue + pow((float)2, (float)i);
            }

            if (tempString2.compare("") == 0)
            {
                break;
            }
        }
    }
    delete []arInputString;
    //cout << "WearFlag : " << wearFlagStr << " -> " << retValue << endl;

    return retValue;
}

int get_Item_Immune_Value(string inputString)
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
    string* arInputString = StringSplit(inputString, "|");              //ÇÁ·ÎÅä Á¤º¸ ³»¿ëÀ» ´Ü¾îº°·Î ÂÉ°µ ¹è¿­.
    for (int i = 0; i < std::size(arImmune); i++)
    {
        string tempString = arImmune[i];
        for (int j = 0; j < 30 ; j++)       //ÃÖ´ë 30°³ ´Ü¾î±îÁö. (ÇÏµåÄÚµù)
        {
            string tempString2 = arInputString[j];
            if (tempString2.compare(tempString) == 0)                   //ÀÏÄ¡ÇÏ´ÂÁö È®ÀÎ.
            {
                retValue = retValue + pow((float)2, (float)i);
            }

            if (tempString2.compare("") == 0)
            {
                break;
            }
        }
    }
    delete []arInputString;
    //cout << "Immune : " << immuneStr << " -> " << retValue << endl;

    return retValue;
}


int get_Item_LimitType_Value(string inputString)
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
    for (int j = 0; j < std::size(arLimitType); j++)
    {
        string tempString = arLimitType[j];
        string tempInputString = trim(inputString);
        if (tempInputString.compare(tempString) == 0)
        {
            //cout << j << " ";
            retInt =  j;
            break;
        }
    }
    //cout << endl;

    return retInt;
}


int get_Item_ApplyType_Value(string inputString)
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
    for (int j = 0; j < std::size(arApplyType); j++)
    {
        string tempString = arApplyType[j];
        string tempInputString = trim(inputString);
        if (tempInputString.compare(tempString) == 0)
        {
            //cout << j << " ";
            retInt =  j;
            break;
        }
    }
    //cout << endl;

    return retInt;

}


//¸ó½ºÅÍ ÇÁ·ÎÅäµµ ÀÐ´Â´Ù.


int get_Mob_Rank_Value(string inputString)
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
    for (int j = 0; j < std::size(arRank); j++)
    {
        string tempString = arRank[j];
        string tempInputString = trim(inputString);
        if (tempInputString.compare(tempString) == 0)
        {
            //cout << j << " ";
            retInt =  j;
            break;
        }
    }
    //cout << endl;

    return retInt;
}


int get_Mob_Type_Value(string inputString)
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
    for (int j = 0; j < std::size(arType); j++)
    {
        string tempString = arType[j];
        string tempInputString = trim(inputString);
        if (tempInputString.compare(tempString) == 0)
        {
            //cout << j << " ";
            retInt =  j;
            break;
        }
    }
    //cout << endl;

    return retInt;
}

int get_Mob_BattleType_Value(string inputString)
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
    for (int j = 0; j < std::size(arBattleType); j++)
    {
        string tempString = arBattleType[j];
        string tempInputString = trim(inputString);
        if (tempInputString.compare(tempString) == 0)
        {
            //cout << j << " ";
            retInt =  j;
            break;
        }
    }
    //cout << endl;

    return retInt;
}

int get_Mob_Size_Value(string inputString)
{
    string arSize[] =
    {
        /* - YOSUN_SERVER_FIX_001 ------------------------------ */
        "SMALL",
        /* ----------------------------------------------------- */
        "MEDIUM",
        "BIG"
    };

    int retInt = 0;
    //cout << "Size : " << sizeStr << " -> ";
    for (int j = 0; j < std::size(arSize); j++)
    {
        string tempString = arSize[j];
        string tempInputString = trim(inputString);
        if (tempInputString.compare(tempString) == 0)
        {
            //cout << j << " ";
            retInt =  j + 1;
            break;
        }
    }
    //cout << endl;

    return retInt;
}

int get_Mob_AIFlag_Value(string inputString)
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
    string* arInputString = StringSplit(inputString, ",");              //ÇÁ·ÎÅä Á¤º¸ ³»¿ëÀ» ´Ü¾îº°·Î ÂÉ°µ ¹è¿­.
    for (int i = 0; i < std::size(arAIFlag); i++)
    {
        string tempString = arAIFlag[i];
        for (int j = 0; j < 30 ; j++)       //ÃÖ´ë 30°³ ´Ü¾î±îÁö. (ÇÏµåÄÚµù)
        {
            string tempString2 = arInputString[j];
            if (tempString2.compare(tempString) == 0)                   //ÀÏÄ¡ÇÏ´ÂÁö È®ÀÎ.
            {
                retValue = retValue + pow((float)2, (float)i);
            }

            if (tempString2.compare("") == 0)
            {
                break;
            }
        }
    }
    delete []arInputString;
    //cout << "AIFlag : " << aiFlagStr << " -> " << retValue << endl;

    return retValue;
}
int get_Mob_RaceFlag_Value(string inputString)
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
    string* arInputString = StringSplit(inputString, ",");              //ÇÁ·ÎÅä Á¤º¸ ³»¿ëÀ» ´Ü¾îº°·Î ÂÉ°µ ¹è¿­.
    for (int i = 0; i < std::size(arRaceFlag); i++)
    {
        string tempString = arRaceFlag[i];
        for (int j = 0; j < 30 ; j++)       //ÃÖ´ë 30°³ ´Ü¾î±îÁö. (ÇÏµåÄÚµù)
        {
            string tempString2 = arInputString[j];
            if (tempString2.compare(tempString) == 0)                   //ÀÏÄ¡ÇÏ´ÂÁö È®ÀÎ.
            {
                retValue = retValue + pow((float)2, (float)i);
            }

            if (tempString2.compare("") == 0)
            {
                break;
            }
        }
    }
    delete []arInputString;
    //cout << "Race Flag : " << raceFlagStr << " -> " << retValue << endl;

    return retValue;
}
int get_Mob_ImmuneFlag_Value(string inputString)
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
    string* arInputString = StringSplit(inputString, ",");              //ÇÁ·ÎÅä Á¤º¸ ³»¿ëÀ» ´Ü¾îº°·Î ÂÉ°µ ¹è¿­.
    for (int i = 0; i < std::size(arImmuneFlag); i++)
    {
        string tempString = arImmuneFlag[i];
        for (int j = 0; j < 30 ; j++)       //ÃÖ´ë 30°³ ´Ü¾î±îÁö. (ÇÏµåÄÚµù)
        {
            string tempString2 = arInputString[j];
            if (tempString2.compare(tempString) == 0)                   //ÀÏÄ¡ÇÏ´ÂÁö È®ÀÎ.
            {
                retValue = retValue + pow((float)2, (float)i);
            }

            if (tempString2.compare("") == 0)
            {
                break;
            }
        }
    }
    delete []arInputString;
    //cout << "Immune Flag : " << immuneFlagStr << " -> " << retValue << endl;


    return retValue;
}


#ifndef __DUMP_PROTO__

//¸÷ Å×ÀÌºíÀ» ¼ÂÆÃÇØÁØ´Ù.
bool Set_Proto_Mob_Table(TMobTable* mobTable, cCsvTable& csvTable, std::map<int, const char*>& nameMap)
{
    int col = 0;

    /*======== VNUM =======*/
    const char* vnumStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->dwVnum, vnumStr);

    /*======== NAME =======*/
    strlcpy(mobTable->szName, csvTable.AsStringByIndex(col++), sizeof(mobTable->szName));

    // Overwrite name with localized name if found
    if (auto it = nameMap.find(mobTable->dwVnum); it != nameMap.end())
    {
        strlcpy(mobTable->szName, it->second, sizeof(mobTable->szName));
    }

    /*======== RANK =======*/
    std::string rankStr = csvTable.AsStringByIndex(col);
    ++col;

    int rankValue = get_Mob_Rank_Value(rankStr);
    mobTable->bRank = rankValue;

    /*======== TYPE =======*/
    std::string typeStr = csvTable.AsStringByIndex(col);
    ++col;

    int typeValue = get_Mob_Type_Value(typeStr);
    mobTable->bType = typeValue;

    /*======== BATTLE_TYPE =======*/
    std::string battleTypeStr = csvTable.AsStringByIndex(col);
    ++col;

    int battleTypeValue = get_Mob_BattleType_Value(battleTypeStr);

    mobTable->bBattleType = battleTypeValue;

    /*======== LEVEL =======*/
    const char* levelStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->bLevel, levelStr);

    /*======== SIZE =======*/
    std::string sizeStr = csvTable.AsStringByIndex(col);
    ++col;

    int sizeValue = get_Mob_Size_Value(sizeStr);
    mobTable->bSize = sizeValue;

    /*======== AI_FLAG =======*/
    std::string aiFlagStr = csvTable.AsStringByIndex(col);
    ++col;

    int aiFlagValue = get_Mob_AIFlag_Value(aiFlagStr);
    mobTable->dwAIFlag = aiFlagValue;

    /*======== MOUNT_CAPACITY =======*/
    col++;

    /*======== RACE_FLAG =======*/
    std::string raceFlagStr = csvTable.AsStringByIndex(col);
    ++col;

    int raceFlagValue = get_Mob_RaceFlag_Value(raceFlagStr);
    mobTable->dwRaceFlag = raceFlagValue;

    /*======== IMMUNE_FLAG =======*/
    std::string immuneFlagStr = csvTable.AsStringByIndex(col);
    ++col;

    int immuneFlagValue = get_Mob_ImmuneFlag_Value(immuneFlagStr);
    mobTable->dwImmuneFlag = immuneFlagValue;

    /*======== EMPIRE =======*/
    const char* empireStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->bEmpire, empireStr);

    /*======== FOLDER =======*/
    strlcpy(mobTable->szFolder, csvTable.AsStringByIndex(col++), sizeof(mobTable->szFolder));

    /*======== ON_CLICK =======*/
    const char* onClickStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->bOnClickType, onClickStr);

    /*======== STR =======*/
    const char* strValue = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->bStr, strValue);

    /*======== DEX =======*/
    const char* dexValue = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->bDex, dexValue);

    /*======== VIT =======*/
    const char* conValue = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->bCon, conValue);

    /*======== INT =======*/
    const char* intValue = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->bInt, intValue);

    /*======== DAMAGE_MIN =======*/
    const char* minDamageStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->dwDamageRange[0], minDamageStr);

    /*======== DAMAGE_MAX =======*/
    const char* maxDamageStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->dwDamageRange[1], maxDamageStr);

    /*======== MAX_HP =======*/
    const char* maxHpStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->dwMaxHP, maxHpStr);

    /*======== REGEN_CYCLE =======*/
    const char* regenCycleStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->bRegenCycle, regenCycleStr);

    /*======== REGEN_PERCENT =======*/
    const char* regenPercentStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->bRegenPercent, regenPercentStr);

    /*======== GOLD_MIN =======*/
    const char* goldMinStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->dwGoldMin, goldMinStr);

    /*======== GOLD_MAX =======*/
    const char* goldMaxStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->dwGoldMax, goldMaxStr);

    /*======== EXP =======*/
    const char* expStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->dwExp, expStr);

    /*======== DEF =======*/
    const char* defStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->wDef, defStr);

    /*======== ATTACK_SPEED =======*/
    const char* attackSpeedStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->sAttackSpeed, attackSpeedStr);

    /*======== MOVE_SPEED =======*/
    const char* movingSpeedStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->sMovingSpeed, movingSpeedStr);

    /*======== AGGRESSIVE_HP_PCT =======*/
    const char* aggressiveHpPctStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->bAggresiveHPPct, aggressiveHpPctStr);

    /*======== AGGRESSIVE_SIGHT =======*/
    const char* aggressiveSightStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->wAggressiveSight, aggressiveSightStr);

    /*======== ATTACK_RANGE =======*/
    const char* attackRangeStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->wAttackRange, attackRangeStr);

    /*======== DROP_ITEM =======*/
    const char* dropItemVnumStr = csvTable.AsStringByIndex(col);  // 32
    ++col;
    str_to_number(mobTable->dwDropItemVnum, dropItemVnumStr);

    /*======== RESURRECTION_VNUM =======*/
    const char* resurrectionVnumStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->dwResurrectionVnum, resurrectionVnumStr);

    /*======== EMobEnchants =======*/
    for (int i = 0; i < MOB_ENCHANTS_MAX_NUM; ++i)
    {
        const char* enchantStr = csvTable.AsStringByIndex(col);
        ++col;
        str_to_number(mobTable->cEnchants[i], enchantStr);
    }

    /*======== EMobResists =======*/
    for (int i = 0; i < MOB_RESISTS_MAX_NUM; ++i)
    {
        const char* resistStr = csvTable.AsStringByIndex(col);
        ++col;
        str_to_number(mobTable->cResists[i], resistStr);
    }

    /*======== DAM_MULTIPLY =======*/
    const char* damMultiplyStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->fDamMultiply, damMultiplyStr);

    /*======== SUMMON =======*/
    const char* summonVnumStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->dwSummonVnum, summonVnumStr);

    /*======== DRAIN_SP =======*/
    const char* drainSPStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->dwDrainSP, drainSPStr);

    /*======== MOB_COLOR =======*/
    ++col;

    /*======== POLYMORPH_ITEM =======*/
    const char* polymorphItemStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->dwPolymorphItemVnum, polymorphItemStr);

    /*======== SKILL_LEVEL0 =======*/
    const char* skillLevel0Str = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->Skills[0].bLevel, skillLevel0Str);

    /*======== SKILL_VNUM0 =======*/
    const char* skillVnum0Str = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->Skills[0].dwVnum, skillVnum0Str);

    /*======== SKILL_LEVEL1 =======*/
    const char* skillLevel1Str = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->Skills[1].bLevel, skillLevel1Str);

    /*======== SKILL_VNUM1 =======*/
    const char* skillVnum1Str = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->Skills[1].dwVnum, skillVnum1Str);

    /*======== SKILL_LEVEL2 =======*/
    const char* skillLevel2Str = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->Skills[2].bLevel, skillLevel2Str);

    /*======== SKILL_VNUM2 =======*/
    const char* skillVnum2Str = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->Skills[2].dwVnum, skillVnum2Str);

    /*======== SKILL_LEVEL3 =======*/
    const char* skillLevel3Str = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->Skills[3].bLevel, skillLevel3Str);

    /*======== SKILL_VNUM3 =======*/
    const char* skillVnum3Str = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->Skills[3].dwVnum, skillVnum3Str);

    /*======== SKILL_LEVEL4 =======*/
    const char* skillLevel4Str = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->Skills[4].bLevel, skillLevel4Str);

    /*======== SKILL_VNUM4 =======*/
    const char* skillVnum4Str = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->Skills[4].dwVnum, skillVnum4Str);

    /*======== SP_BERSERK =======*/
    const char* berserkPointStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->bBerserkPoint, berserkPointStr);

    /*======== SP_STONESKIN =======*/
    const char* stoneSkinStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->bStoneSkinPoint, stoneSkinStr);

    /*======== SP_GODSPEED =======*/
    const char* godSpeedStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->bGodSpeedPoint, godSpeedStr);

    /*======== SP_DEATHBLOW =======*/
    const char* deathBlowStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->bDeathBlowPoint, deathBlowStr);

    /*======== SP_REVIVE =======*/
    const char* reviveStr = csvTable.AsStringByIndex(col);
    ++col;
    str_to_number(mobTable->bRevivePoint, reviveStr);


    sys_log(0, "MOB #%-5d %-24s level: %-3u rank: %u empire: %d", mobTable->dwVnum, mobTable->szName, mobTable->bLevel, mobTable->bRank, mobTable->bEmpire);

    return true;
}

bool Set_Proto_Item_Table(TItemTable *itemTable, cCsvTable &csvTable, std::map<int, const char*>& nameMap)
{
    int col = 0;

    int dataArray[33];
    for (int i = 0; i < std::size(dataArray); i++)
    {
        int validCheck = 0;
        if (i == 2)
        {
            dataArray[i] = get_Item_Type_Value(csvTable.AsStringByIndex(col));
            validCheck = dataArray[i];
        }
        else if (i == 3)
        {
            dataArray[i] = get_Item_SubType_Value(dataArray[i - 1], csvTable.AsStringByIndex(col));
            validCheck = dataArray[i];
        }
        else if (i == 5)
        {
            dataArray[i] = get_Item_AntiFlag_Value(csvTable.AsStringByIndex(col));
            validCheck = dataArray[i];
        }
        else if (i == 6)
        {
            dataArray[i] = get_Item_Flag_Value(csvTable.AsStringByIndex(col));
            validCheck = dataArray[i];
        }
        else if (i == 7)
        {
            dataArray[i] = get_Item_WearFlag_Value(csvTable.AsStringByIndex(col));
            validCheck = dataArray[i];
        }
        else if (i == 8)
        {
            dataArray[i] = get_Item_Immune_Value(csvTable.AsStringByIndex(col));
            validCheck = dataArray[i];
        }
        else if (i == 14 || i == 16)
        {
            dataArray[i] = get_Item_LimitType_Value(csvTable.AsStringByIndex(col));
            validCheck = dataArray[i];
        }
        else if (i == 18 || i == 20 || i == 22)
        {
            dataArray[i] = get_Item_ApplyType_Value(csvTable.AsStringByIndex(col));
            validCheck = dataArray[i];
        }
        else
        {
            str_to_number(dataArray[i], csvTable.AsStringByIndex(col));
        }

        if (validCheck == -1)
        {
            std::ostringstream dataStream;

            for (int j = 0; j < i; ++j)
            {
                dataStream << dataArray[j] << ",";
            }

            //fprintf(stderr, "ItemProto Reading Failed : Invalid value.\n");
            sys_err("ItemProto Reading Failed : Invalid value. (index: %d, col: %d, value: %s)", i, col, csvTable.AsStringByIndex(col));
            sys_err("\t%d ~ %d Values: %s", 0, i, dataStream.str().c_str());

            exit(0);
        }

        col = col + 1;
    }

    // vnum ¹× vnum range ÀÐ±â.
    {
        std::string s(csvTable.AsStringByIndex(0));
        int pos = s.find("~");
        // vnum ÇÊµå¿¡ '~'°¡ ¾ø´Ù¸é ÆÐ½º
        if (std::string::npos == pos)
        {
            itemTable->dwVnum = dataArray[0];
            itemTable->dwVnumRange = 0;
        }
        else
        {
            std::string s_start_vnum(s.substr(0, pos));
            std::string s_end_vnum(s.substr(pos + 1));

            int start_vnum = atoi(s_start_vnum.c_str());
            int end_vnum = atoi(s_end_vnum.c_str());
            if (0 == start_vnum || (0 != end_vnum && end_vnum < start_vnum))
            {
                sys_err("INVALID VNUM %s", s.c_str());
                return false;
            }
            itemTable->dwVnum = start_vnum;
            itemTable->dwVnumRange = end_vnum - start_vnum;
        }
    }

    strlcpy(itemTable->szName, csvTable.AsStringByIndex(1), sizeof(itemTable->szName));
    // Overwrite name with localized name if found
    if (auto it = nameMap.find(itemTable->dwVnum); it != nameMap.end())
    {
        strlcpy(itemTable->szName, it->second, sizeof(itemTable->szName));
    }

    itemTable->bType = dataArray[2];
    itemTable->bSubType = dataArray[3];
    itemTable->bSize = dataArray[4];
    itemTable->dwAntiFlags = dataArray[5];
    itemTable->dwFlags = dataArray[6];
    itemTable->dwWearFlags = dataArray[7];
    itemTable->dwImmuneFlag = dataArray[8];
    itemTable->dwGold = dataArray[9];
    itemTable->dwShopBuyPrice = dataArray[10];
    itemTable->dwRefinedVnum = dataArray[11];
    itemTable->wRefineSet = dataArray[12];
    itemTable->bAlterToMagicItemPct = dataArray[13];
    itemTable->cLimitRealTimeFirstUseIndex = -1;
    itemTable->cLimitTimerBasedOnWearIndex = -1;

    int i;

    for (i = 0; i < ITEM_LIMIT_MAX_NUM; ++i)
    {
        itemTable->aLimits[i].bType = dataArray[14 + i * 2];
        itemTable->aLimits[i].lValue = dataArray[15 + i * 2];

        if (LIMIT_REAL_TIME_START_FIRST_USE == itemTable->aLimits[i].bType)
        {
            itemTable->cLimitRealTimeFirstUseIndex = (char)i;
        }

        if (LIMIT_TIMER_BASED_ON_WEAR == itemTable->aLimits[i].bType)
        {
            itemTable->cLimitTimerBasedOnWearIndex = (char)i;
        }

    }

    for (i = 0; i < ITEM_APPLY_MAX_NUM; ++i)
    {
        itemTable->aApplies[i].bType = dataArray[18 + i * 2];
        itemTable->aApplies[i].lValue = dataArray[19 + i * 2];
    }

    for (i = 0; i < ITEM_VALUES_MAX_NUM; ++i)
    {
        itemTable->alValues[i] = dataArray[24 + i];
    }

    //column for 'Specular'
    itemTable->bGainSocketPct = dataArray[31];
    itemTable->sAddonType = dataArray[32];

    //test
    str_to_number(itemTable->bWeight, "0");

    return true;
}

#endif
