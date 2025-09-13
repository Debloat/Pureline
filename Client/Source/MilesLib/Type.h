#pragma once

#include <vector>

namespace NSound
{
    extern std::string strResult;

    using TSoundData = struct SSoundData
    {
        float fTime;
        std::string strSoundFileName;
    };
    using TSoundInstance = struct SSoundInstance
    {
        DWORD dwFrame;
        std::string strSoundFileName;
    };
    using TSoundDataVector = std::vector<TSoundData>;
    using TSoundInstanceVector = std::vector<TSoundInstance>;

    bool            LoadSoundInformationPiece (const char* c_szFileName, TSoundDataVector & rSoundDataVector, const char* c_szPathHeader = nullptr);
    bool            SaveSoundInformationPiece (const char* c_szFileName, TSoundDataVector & rSoundDataVector);
    void            DataToInstance (const TSoundDataVector & c_rSoundDataVector, TSoundInstanceVector * pSoundInstanceVector);

    const char*     GetResultString();
    void            SetResultString (const char* c_pszStr);
};
