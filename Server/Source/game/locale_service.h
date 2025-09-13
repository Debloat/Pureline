#ifndef __LOCALE_SERVCICE__
#define __LOCALE_SERVCICE__

bool LocaleService_Init(const std::string& c_rstServiceName);
void LocaleService_LoadLocaleStringFile();
void LocaleService_LoadEmpireTextConvertTables();
void LocaleService_TransferDefaultSetting();
const std::string& LocaleService_GetBasePath();
const std::string& LocaleService_GetMapPath();
const std::string& LocaleService_GetQuestPath();

enum eLocalization
{
    LC_NOSET = 0,

    LC_YMIR,
    LC_KOREA,
    LC_UK,
    LC_MULTILANGUAGE,
    LC_CANADA,
    LC_ARABIA,
    LC_USA,
    LC_WE_KOREA,            ///< World Edition version for korea

    LC_MAX_VALUE
};

eLocalization LC_GetLocalType();

bool LC_IsLocale(const eLocalization t);
bool LC_IsYMIR();
bool LC_IsKorea();
bool LC_IsEurope();
bool LC_IsCanada();
bool LC_IsWE_Korea();

#endif
