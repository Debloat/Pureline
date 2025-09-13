/*
* blackdragonx61 / Mali
* 24.10.2022
*/

#pragma once

class CPythonLocale : public CSingleton<CPythonLocale>
{
    public:
        CPythonLocale();
        virtual ~CPythonLocale();

        enum ELOCALE_STRING_TYPE
        {
            LOCALE_STRING,
            LOCALE_QUEST_STRING,
            LOCALE_OXQUIZ_STRING,

            LOCALE_STRING_MAX
        };

        bool        LoadLocaleString (const char* c_szFileName);
        bool        LoadQuestLocaleString (const char* c_szFileName);
        bool        LoadOXQuizLocaleString (const char* c_szFileName);

        void        FormatString (std::string& sMessage) const;
        void        FormatString (char* c, size_t size) const;

        void        MultiLineSplit (const std::string& sMessage, TTokenVector& vec) const;

    private:
        void        ReplaceSkillName (std::string& sMessage) const;
        void        ReplacePetSkillName (std::string& sMessage) const;
        void        ReplaceMobName (std::string& sMessage) const;
        void        ReplaceItemName (std::string& sMessage) const;
        void        ReplaceLocaleString (std::string& sMessage) const;
        void        ReplaceQuestLocaleString (std::string& sMessage) const;
        void        ReplaceOXQuizLocaleString (std::string& sMessage) const;

        std::unordered_map<std::string, std::string> m_LocaleStringMap[LOCALE_STRING_MAX];
};