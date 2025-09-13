#include "stdafx.h"
#include "locale_service.h"
#include "constants.h"
#include "banword.h"
#include "utils.h"
#include "mob_manager.h"
#include "empire_text_convert.h"
#include "config.h"
#include "skill_power.h"

using namespace std;

extern string       g_stQuestDir;
extern set<string>  g_setQuestObjectDir;

string g_stServiceName;
string g_stServiceBasePath = ".";
string g_stServiceMapPath = "data/map";

string g_stLocale = "euckr";
string g_stLocaleFilename;

BYTE PK_PROTECT_LEVEL = 30;

string          g_stLocal = "";
eLocalization   g_eLocalType = LC_NOSET;

int (*check_name)(const char* str) = nullptr;

bool LC_InitLocalization(const std::string& szLocal);

int check_name_independent(const char* str)
{
    if (CBanwordManager::instance().CheckString(str, strlen(str)))
    {
        return 0;
    }

    // 몬스터 이름으로는 만들 수 없다.
    char szTmp[256];
    str_lower(str, szTmp, sizeof(szTmp));

    if (CMobManager::instance().Get(szTmp, false))
    {
        return 0;
    }

    return 1;
}

int check_name_alphabet(const char* str)
{
    const char* tmp;

    if (!str || !*str)
    {
        return 0;
    }

    if (strlen(str) < 2)
    {
        return 0;
    }

    for (tmp = str; *tmp; ++tmp)
    {
        // 알파벳과 수자만 허용
        if (isdigit(*tmp) || isalpha(*tmp))
        {
            continue;
        }
        else
        {
            return 0;
        }
    }

    return check_name_independent(str);
}

void LocaleService_LoadLocaleStringFile()
{
    if (g_stLocaleFilename.empty())
    {
        return;
    }

    if (g_bAuthServer)
    {
        return;
    }

    fprintf(stderr, "LocaleService %s\n", g_stLocaleFilename.c_str());

    locale_init(g_stLocaleFilename.c_str());
}

void LocaleService_LoadEmpireTextConvertTables()
{
    char szFileName[256];

    for (int iEmpire = 1; iEmpire <= 3; ++iEmpire)
    {
        snprintf(szFileName, sizeof(szFileName), "%s/lang%d.cvt", LocaleService_GetBasePath().c_str(), iEmpire);
        sys_log(0, "Load %s", szFileName);

        LoadEmpireTextConvertTable(iEmpire, szFileName);
    }
}

static void __LocaleService_Init_DEFAULT()
{
    g_stLocaleFilename = "";

    g_stServiceBasePath = "locale/" + g_stServiceName;
    g_stServiceMapPath = g_stServiceBasePath + "/map";
    g_stQuestDir = g_stServiceBasePath + "/quest";

    g_setQuestObjectDir.clear();
    g_setQuestObjectDir.insert(g_stQuestDir + "/object");
}

static void __LocaleService_Init_Korea()
{
    g_stLocale = "euckr";
    g_stServiceBasePath = "locale/korea";
    g_stQuestDir = "locale/korea/quest";
    g_stServiceMapPath = "locale/korea/map";

    g_setQuestObjectDir.clear();
    g_setQuestObjectDir.emplace("locale/korea/quest/object");

    g_iUseLocale = TRUE;
    exp_table = exp_table_euckr;
}

static void __LocaleService_Init_UK()
{
    g_stLocale = "latin1";
    g_stServiceBasePath = "locale/uk";
    g_stQuestDir = "locale/uk/quest";
    g_stServiceMapPath = "locale/uk/map";

    g_setQuestObjectDir.clear();
    g_setQuestObjectDir.emplace("locale/uk/quest/object");
    g_stLocaleFilename = "locale/uk/locale_string.txt";

    g_iUseLocale = TRUE;

    check_name = check_name_alphabet;

    PK_PROTECT_LEVEL = 15;
}

static void __LocaleService_Init_Multilanguage()
{
    g_stLocale = "latin5";
    g_stServiceBasePath = "locale/multilanguage";
    g_stQuestDir = "locale/multilanguage/quest";
    g_stServiceMapPath = "locale/multilanguage/map";

    g_setQuestObjectDir.clear();
    g_setQuestObjectDir.emplace("locale/multilanguage/quest/object");
    g_stLocaleFilename = "locale/multilanguage/locale_string.txt";

    g_iUseLocale = TRUE;

    check_name = check_name_alphabet;

    exp_table = exp_table_common;

    PK_PROTECT_LEVEL = 15;
}

static void __LocaleService_Init_Canada()
{
    g_stLocale = "latin1";
    g_stServiceBasePath = "locale/canada";
    g_stQuestDir        = "locale/canada/quest";
    g_stServiceMapPath  = "locale/canada/map";

    g_setQuestObjectDir.clear();
    g_setQuestObjectDir.emplace("locale/canada/quest/object");
    g_stLocaleFilename = "locale/canada/locale_string.txt";

    check_name  = check_name_alphabet;

    g_iUseLocale = TRUE;
}

static void __LocaleService_Init_YMIR()
{
    g_stLocaleFilename = "";

    g_stServiceBasePath = "locale/" + g_stServiceName;
    g_stServiceMapPath = g_stServiceBasePath + "/map";
    g_stQuestDir = g_stServiceBasePath + "/quest";

    g_setQuestObjectDir.clear();
    g_setQuestObjectDir.insert(g_stQuestDir + "/object");

    PK_PROTECT_LEVEL = 30;

    exp_table = exp_table_euckr;
}

static void __LocaleService_Init_Arabia()
{
    g_stLocale = "cp1256";
    g_stServiceBasePath = "locale/arabia";
    g_stQuestDir = "locale/arabia/quest";
    g_stServiceMapPath = "locale/arabia/map";

    g_setQuestObjectDir.clear();
    g_setQuestObjectDir.emplace("locale/arabia/quest/object");
    g_stLocaleFilename = "locale/arabia/locale_string.txt";

    g_iUseLocale = TRUE;

    check_name = check_name_alphabet;

    PK_PROTECT_LEVEL = 15;
}

// World Edition version for korea
static void __LocaleService_Init_WE_Korea()
{
    g_stLocale = "euckr";

    //  g_stLocaleFilename = "locale/we_korea/locale_string.txt";

    g_stServiceBasePath = "locale/" + g_stServiceName;
    g_stServiceMapPath = g_stServiceBasePath + "/map";
    g_stQuestDir = g_stServiceBasePath + "/quest";

    g_setQuestObjectDir.clear();
    g_setQuestObjectDir.insert(g_stQuestDir + "/object");

    g_iUseLocale = TRUE;

    PK_PROTECT_LEVEL = 15;
}

static void __CheckPlayerSlot(const std::string& service_name)
{
    if (PLAYER_PER_ACCOUNT != 4)
    {
        printf("<ERROR> PLAYER_PER_ACCOUNT = %d\n", PLAYER_PER_ACCOUNT);
        exit(0);
    }
}

bool LocaleService_Init(const std::string& c_rstServiceName)
{
    if (!g_stServiceName.empty())
    {
        sys_err("ALREADY exist service");
        return false;
    }

    g_stServiceName = c_rstServiceName;

    if ("korea" == g_stServiceName)
    {
        __LocaleService_Init_Korea();
    }
    else if ("uk" == g_stServiceName)
    {
        __LocaleService_Init_UK();
    }
    else if ("multilanguage" == g_stServiceName)
    {
        __LocaleService_Init_Multilanguage();
    }
    else if ("canada" == g_stServiceName)
    {
        __LocaleService_Init_Canada();
    }
    else if ("ymir" == g_stServiceName)
    {
        __LocaleService_Init_YMIR();
    }
    else if ("arabia" == g_stServiceName)
    {
        __LocaleService_Init_Arabia();
    }
    else if ("we_korea" == g_stServiceName)
    {
        __LocaleService_Init_WE_Korea(); // ver.World Edition for korea
    }
    else
    {
        __LocaleService_Init_DEFAULT();
    }

    fprintf(stdout, "Setting Locale \"%s\" (Path: %s)\n", g_stServiceName.c_str(), g_stServiceBasePath.c_str());

    __CheckPlayerSlot(g_stServiceName);

    if (false == LC_InitLocalization(c_rstServiceName))
    {
        return false;
    }

    return true;
}

void LocaleService_TransferDefaultSetting()
{
    if (!check_name)
    {
        check_name = check_name_independent;
    }

    if (!exp_table)
    {
        exp_table = exp_table_common;
    }

    if (!CTableBySkill::instance().Check())
    {
        exit(1);
    }

    if (!aiPercentByDeltaLevForBoss)
    {
        aiPercentByDeltaLevForBoss = aiPercentByDeltaLevForBoss_euckr;
    }

    if (!aiPercentByDeltaLev)
    {
        aiPercentByDeltaLev = aiPercentByDeltaLev_euckr;
    }

    if (!aiChainLightningCountBySkillLevel)
    {
        aiChainLightningCountBySkillLevel = aiChainLightningCountBySkillLevel_euckr;
    }
}

const std::string& LocaleService_GetBasePath()
{
    return g_stServiceBasePath;
}

const std::string& LocaleService_GetMapPath()
{
    return g_stServiceMapPath;
}

const std::string& LocaleService_GetQuestPath()
{
    return g_stQuestDir;
}

bool LC_InitLocalization(const std::string& szLocal)
{
    g_stLocal = szLocal;

    if (!g_stLocal.compare("ymir"))
    {
        g_eLocalType = LC_YMIR;
    }
    else if (!g_stLocal.compare("korea"))
    {
        g_eLocalType = LC_KOREA;
    }
    else if (!g_stLocal.compare("uk"))
    {
        g_eLocalType = LC_UK;
    }
    else if (!g_stLocal.compare("multilanguage"))
    {
        g_eLocalType = LC_MULTILANGUAGE;
    }
    else if (!g_stLocal.compare("canada"))
    {
        g_eLocalType = LC_CANADA;
    }
    else if (!g_stLocal.compare("arabia"))
    {
        g_eLocalType = LC_ARABIA;
    }
    else if (!g_stLocal.compare("we_korea"))   // ver.WorldEdition for korea
    {
        g_eLocalType = LC_WE_KOREA;
    }
    else
    {
        return false;
    }

    return true;
}

eLocalization LC_GetLocalType()
{
    return g_eLocalType;
}

bool LC_IsLocale(const eLocalization t)
{
    return LC_GetLocalType() == t ? true : false;
}

bool LC_IsYMIR()
{
    return LC_GetLocalType() == LC_YMIR ? true : false;
}
bool LC_IsKorea()
{
    return LC_GetLocalType() == LC_KOREA ? true : false;
}
bool LC_IsCanada()
{
    return LC_GetLocalType() == LC_CANADA ? true : false;
}
bool LC_IsWE_Korea()
{
    return LC_GetLocalType() == LC_WE_KOREA ? true : false;
}

bool LC_IsEurope()
{
    eLocalization val = LC_GetLocalType();

    switch ((int) val)
    {
        case LC_MULTILANGUAGE:
        case LC_UK:
        case LC_ARABIA: // 중동이지만 GF에서 서비스 하므로 여기 넣음
        case LC_USA:
        case LC_WE_KOREA:   // 한국이지만 UK 버전 기반이므로 여기 넣음
        case LC_CANADA: // 캐나다 GF에서 서비스 시작
            return true;
    }

    return false;
}

