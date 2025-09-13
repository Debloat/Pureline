/*
* blackdragonx61 / Mali
* 24.10.2022
*/

#include "StdAfx.h"
#include "PythonLocale.h"
#include "PythonNonPlayer.h"
#include "PythonSkill.h"
#include "../eterPack/EterPackManager.h"
#include "../GameLib/ItemManager.h"

#undef snprintf
#include <boost/format.hpp>
#define snprintf _snprintf

CPythonLocale::CPythonLocale() = default;

CPythonLocale::~CPythonLocale() = default;

bool CPythonLocale::LoadLocaleString(const char* c_szFileName)
{
    if (m_LocaleStringMap[LOCALE_STRING].empty() == false)
    {
        return true;
    }

    const VOID* pvData;
    CMappedFile kFile;
    if (!CEterPackManager::Instance().Get(kFile, c_szFileName, &pvData))
    {
        TraceError("CPythonLocale::LoadLocaleString(c_szFileName: %s) - Load Error", c_szFileName);
        return false;
    }

    CMemoryTextFileLoader kTextFileLoader;
    kTextFileLoader.Bind(kFile.Size(), pvData);

    CTokenVector kTokenVector;
    for (DWORD i = 0; i < kTextFileLoader.GetLineCount(); ++i)
    {
        const std::string& c_rstLine = kTextFileLoader.GetLineString(i);
        if (c_rstLine.empty())
        {
            continue;
        }

        if (c_rstLine[0] == '#')
        {
            continue;
        }

        if (!kTextFileLoader.SplitLineByTab(i, &kTokenVector))
        {
            continue;
        }

        if (kTokenVector.size() != 2)
        {
            continue;
        }

        m_LocaleStringMap[LOCALE_STRING][kTokenVector[0]] = kTokenVector[1];
    }

    return true;
}

bool CPythonLocale::LoadQuestLocaleString(const char* c_szFileName)
{
    if (m_LocaleStringMap[LOCALE_QUEST_STRING].empty() == false)
    {
        return true;
    }

    const VOID* pvData;
    CMappedFile kFile;
    if (!CEterPackManager::Instance().Get(kFile, c_szFileName, &pvData))
    {
        TraceError("CPythonLocale::LoadQuestLocaleString(c_szFileName: %s) - Load Error", c_szFileName);
        return false;
    }

    CMemoryTextFileLoader kTextFileLoader;
    kTextFileLoader.Bind(kFile.Size(), pvData);

    CTokenVector kTokenVector;
    for (DWORD i = 0; i < kTextFileLoader.GetLineCount(); ++i)
    {
        const std::string& c_rstLine = kTextFileLoader.GetLineString(i);
        if (c_rstLine.empty())
        {
            continue;
        }

        if (c_rstLine[0] == '#')
        {
            continue;
        }

        if (!kTextFileLoader.SplitLineByTab(i, &kTokenVector))
        {
            continue;
        }

        if (kTokenVector.size() != 2)
        {
            continue;
        }

        m_LocaleStringMap[LOCALE_QUEST_STRING][kTokenVector[0]] = kTokenVector[1];
    }

    return true;
}

bool CPythonLocale::LoadOXQuizLocaleString(const char* c_szFileName)
{
    if (m_LocaleStringMap[LOCALE_OXQUIZ_STRING].empty() == false)
    {
        return true;
    }

    const VOID* pvData;
    CMappedFile kFile;
    if (!CEterPackManager::Instance().Get(kFile, c_szFileName, &pvData))
    {
        TraceError("CPythonLocale::LoadOXQuizLocaleString(c_szFileName: %s) - Load Error", c_szFileName);
        return false;
    }

    CMemoryTextFileLoader kTextFileLoader;
    kTextFileLoader.Bind(kFile.Size(), pvData);

    CTokenVector kTokenVector;
    for (DWORD i = 0; i < kTextFileLoader.GetLineCount(); ++i)
    {
        const std::string& c_rstLine = kTextFileLoader.GetLineString(i);
        if (c_rstLine.empty())
        {
            continue;
        }

        if (c_rstLine[0] == '#')
        {
            continue;
        }

        if (!kTextFileLoader.SplitLineByTab(i, &kTokenVector))
        {
            continue;
        }

        if (kTokenVector.size() != 3)
        {
            continue;
        }

        m_LocaleStringMap[LOCALE_OXQUIZ_STRING][kTokenVector[1]] = kTokenVector[2];
    }

    return true;
}

void CPythonLocale::FormatString(std::string& sMessage) const
{
    ReplaceSkillName(sMessage);
    ReplacePetSkillName(sMessage);
    ReplaceMobName(sMessage);
    ReplaceItemName(sMessage);
    ReplaceLocaleString(sMessage);
    ReplaceQuestLocaleString(sMessage);
    ReplaceOXQuizLocaleString(sMessage);
}

void CPythonLocale::FormatString(char* c, size_t size) const
{
    std::string sFormat{ c };
    FormatString(sFormat);

    strncpy(c, sFormat.c_str(), size);
    c[size - 1] = '\0';
}

void CPythonLocale::MultiLineSplit(const std::string& sMessage, TTokenVector& vec) const
{
    if (!sMessage.contains("[ENTER]"))
    {
        return;
    }

    size_t v15 = 0;

    while (true)
    {
        const size_t pos = sMessage.find("[ENTER]", v15);
        if (pos == std::string::npos)
        {
            break;
        }

        vec.push_back(sMessage.substr(v15, pos - v15));
        v15 = pos + 7;
    }

    if (v15 < sMessage.size())
    {
        vec.push_back(sMessage.substr(v15));
    }
}

void CPythonLocale::ReplaceSkillName(std::string& sMessage) const
{
    while (true)
    {
        size_t pos_begin = sMessage.find("[SN;");
        if (pos_begin == std::string::npos)
        {
            break;
        }

        size_t pos_mid = sMessage.find(';', pos_begin);
        if (pos_mid == std::string::npos)
        {
            break;
        }

        size_t pos_end = sMessage.find(']', ++pos_mid);
        if (pos_end == std::string::npos)
        {
            break;
        }

        DWORD dwVnum{};
        try
        {
            dwVnum = std::stoul(sMessage.substr(pos_mid, pos_end - pos_mid));
        }
        catch (const std::exception& ex)
        {
            TraceError("CPythonLocale::ReplaceSkillName: Error: %s", ex.what());
            break;
        }

        CPythonSkill::TSkillData* pSkillData;
        if (!CPythonSkill::Instance().GetSkillData(dwVnum, &pSkillData))
        {
            TraceError("CPythonLocale::ReplaceSkillName: can't find skill vnum: %lu", dwVnum);
            break;
        }

        sMessage.replace(pos_begin, (pos_end + 1) - pos_begin, pSkillData->strName);
    }
}

void CPythonLocale::ReplacePetSkillName(std::string& sMessage) const
{
}

void CPythonLocale::ReplaceMobName(std::string& sMessage) const
{
    while (true)
    {
        size_t pos_begin = sMessage.find("[MN;");
        if (pos_begin == std::string::npos)
        {
            break;
        }

        size_t pos_mid = sMessage.find(';', pos_begin);
        if (pos_mid == std::string::npos)
        {
            break;
        }

        size_t pos_end = sMessage.find(']', ++pos_mid);
        if (pos_end == std::string::npos)
        {
            break;
        }

        DWORD dwVnum{};
        try
        {
            dwVnum = std::stoul(sMessage.substr(pos_mid, pos_end - pos_mid));
        }
        catch (const std::exception& ex)
        {
            TraceError("CPythonLocale::ReplaceMobName: Error: %s", ex.what());
            break;
        }

        const char* c_szName;
        if (!CPythonNonPlayer::Instance().GetName(dwVnum, &c_szName))
        {
            TraceError("CPythonLocale::ReplaceMobName: can't find mob vnum: %lu", dwVnum);
            break;
        }

        sMessage.replace(pos_begin, (pos_end + 1) - pos_begin, c_szName);
    }
}

void CPythonLocale::ReplaceItemName(std::string& sMessage) const
{
    while (true)
    {
        size_t pos_begin = sMessage.find("[IN;");
        if (pos_begin == std::string::npos)
        {
            break;
        }

        size_t pos_mid = sMessage.find(';', pos_begin);
        if (pos_mid == std::string::npos)
        {
            break;
        }

        size_t pos_end = sMessage.find(']', ++pos_mid);
        if (pos_end == std::string::npos)
        {
            break;
        }

        DWORD dwVnum{};
        try
        {
            dwVnum = std::stoul(sMessage.substr(pos_mid, pos_end - pos_mid));
        }
        catch (const std::exception& ex)
        {
            TraceError("CPythonLocale::ReplaceItemName: Error: %s", ex.what());
            break;
        }

        CItemData* pItemData;
        if (!CItemManager::Instance().GetItemDataPointer(dwVnum, &pItemData))
        {
            TraceError("CPythonLocale::ReplaceItemName: can't find item vnum: %lu", dwVnum);
            break;
        }

        sMessage.replace(pos_begin, (pos_end + 1) - pos_begin, pItemData->GetName());
    }
}

void CPythonLocale::ReplaceLocaleString(std::string& sMessage) const
{
    while (true)
    {
        size_t pos_1 = sMessage.rfind("[LS;");
        if (pos_1 == std::string::npos)
        {
            break;
        }

        size_t pos_2 = sMessage.find(';', pos_1);
        if (pos_2 == std::string::npos)
        {
            break;
        }

        ++pos_2;

        size_t pos_3 = sMessage.find('[', pos_2);
        size_t pos_4 = sMessage.find(']', pos_2);
        if (pos_4 == std::string::npos)
        {
            break;
        }

        if (pos_3 != std::string::npos && pos_3 < pos_4)
        {
            pos_4 = sMessage.find(']', pos_4 + 1);
        }

        std::string sArgs = sMessage.substr(pos_2, pos_4 - pos_2);

        CTokenVector kTokenVector;
        SplitLine(sArgs.c_str(), ";", &kTokenVector);

        if (kTokenVector.empty())
        {
            break;
        }

        auto it = m_LocaleStringMap[LOCALE_STRING].find(kTokenVector[0]);
        if (it == m_LocaleStringMap[LOCALE_STRING].end())
        {
            TraceError("CPythonLocale::ReplaceLocaleString wrong LS vnum : %s", kTokenVector[0].c_str());
            break;
        }

        if (kTokenVector.size() > 1)
        {
            try
            {
                boost::format f(it->second);

                for (size_t i = 1; i < kTokenVector.size(); i++)
                {
                    f % kTokenVector[i];
                }

                sMessage.replace(pos_1, (pos_4 + 1) - pos_1, f.str());
            }
            catch (const std::exception& ex)
            {
                TraceError("CPythonLocale::ReplaceLocaleString: Error: %s", ex.what());
                break;
            }
        }
        else
        {
            sMessage.replace(pos_1, (pos_4 + 1) - pos_1, it->second);
        }
    }
}

void CPythonLocale::ReplaceQuestLocaleString(std::string& sMessage) const
{
    while (true)
    {
        size_t pos_1 = sMessage.rfind("[LC;");
        if (pos_1 == std::string::npos)
        {
            break;
        }

        size_t pos_2 = sMessage.find(';', pos_1);
        if (pos_2 == std::string::npos)
        {
            break;
        }

        ++pos_2;

        size_t pos_3 = sMessage.find('[', pos_2);
        size_t pos_4 = sMessage.find(']', pos_2);
        if (pos_4 == std::string::npos)
        {
            break;
        }

        if (pos_3 != std::string::npos && pos_3 < pos_4)
        {
            pos_4 = sMessage.find(']', pos_4 + 1);
        }

        std::string sArgs = sMessage.substr(pos_2, pos_4 - pos_2);

        CTokenVector kTokenVector;
        SplitLine(sArgs.c_str(), ";", &kTokenVector);

        if (kTokenVector.empty())
        {
            break;
        }

        auto it = m_LocaleStringMap[LOCALE_QUEST_STRING].find(kTokenVector[0]);
        if (it == m_LocaleStringMap[LOCALE_QUEST_STRING].end())
        {
            TraceError("CPythonLocale::ReplaceQuestLocaleString wrong LC vnum : %s", kTokenVector[0].c_str());
            break;
        }

        if (kTokenVector.size() > 1)
        {
            try
            {
                boost::format f(it->second);

                for (size_t i = 1; i < kTokenVector.size(); i++)
                {
                    f % kTokenVector[i];
                }

                sMessage.replace(pos_1, (pos_4 + 1) - pos_1, f.str());
            }
            catch (const std::exception& ex)
            {
                TraceError("CPythonLocale::ReplaceQuestLocaleString: Error: %s", ex.what());
                break;
            }
        }
        else
        {
            sMessage.replace(pos_1, (pos_4 + 1) - pos_1, it->second);
        }
    }
}

void CPythonLocale::ReplaceOXQuizLocaleString(std::string& sMessage) const
{
    while (true)
    {
        size_t pos_1 = sMessage.rfind("[LOX;");
        if (pos_1 == std::string::npos)
        {
            break;
        }

        size_t pos_2 = sMessage.find(';', pos_1);
        if (pos_2 == std::string::npos)
        {
            break;
        }

        ++pos_2;

        size_t pos_3 = sMessage.find('[', pos_2);
        size_t pos_4 = sMessage.find(']', pos_2);
        if (pos_4 == std::string::npos)
        {
            break;
        }

        if (pos_3 != std::string::npos && pos_3 < pos_4)
        {
            pos_4 = sMessage.find(']', pos_4 + 1);
        }

        std::string sArgs = sMessage.substr(pos_2, pos_4 - pos_2);

        CTokenVector kTokenVector;
        SplitLine(sArgs.c_str(), ";", &kTokenVector);

        if (kTokenVector.empty())
        {
            break;
        }

        auto it = m_LocaleStringMap[LOCALE_OXQUIZ_STRING].find(kTokenVector[0]);
        if (it == m_LocaleStringMap[LOCALE_OXQUIZ_STRING].end())
        {
            TraceError("CPythonLocale::ReplaceOXQuizLocaleString wrong LOX level-key : %s", kTokenVector[0].c_str());
            break;
        }

        if (kTokenVector.size() > 1)
        {
            try
            {
                boost::format f(it->second);

                for (size_t i = 1; i < kTokenVector.size(); i++)
                {
                    f % kTokenVector[i];
                }

                sMessage.replace(pos_1, (pos_4 + 1) - pos_1, f.str());
            }
            catch (const std::exception& ex)
            {
                TraceError("CPythonLocale::ReplaceOXQuizLocaleString: Error: %s", ex.what());
                break;
            }
        }
        else
        {
            sMessage.replace(pos_1, (pos_4 + 1) - pos_1, it->second);
        }
    }
}
