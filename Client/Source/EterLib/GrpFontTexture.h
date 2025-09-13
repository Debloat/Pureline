#pragma once

#include "GrpTexture.h"
#include "GrpImageTexture.h"
#include "GrpDIB.h"

#include <vector>
#include <map>

class CGraphicFontTexture : public CGraphicTexture
{
    public:
        using TCharacterKey = std::pair<WORD, wchar_t>;

        using TCharacterInfomation = struct SCharacterInfomation
        {
            short index;
            short width;
            short height;
            float left;
            float top;
            float right;
            float bottom;
            float advance;
        };

        using TPCharacterInfomationVector = std::vector<TCharacterInfomation*>;

    public:
        CGraphicFontTexture();
        virtual ~CGraphicFontTexture();

        void Destroy();
        bool Create(const char* c_szFontName, int fontSize, bool bItalic);

        bool CreateDeviceObjects();
        void DestroyDeviceObjects();

        bool CheckTextureIndex(DWORD dwTexture);
        void SelectTexture(DWORD dwTexture);

        bool UpdateTexture();

        TCharacterInfomation* GetCharacterInfomation(WORD codePage, wchar_t keyValue);
        TCharacterInfomation* UpdateCharacterInfomation(TCharacterKey code);

        bool IsEmpty() const;

    protected:
        void Initialize();

        bool AppendTexture();

        HFONT GetFont(WORD codePage);

    protected:
        using TGraphicImageTexturePointerVector = std::vector<CGraphicImageTexture*>;
        using TCharacterInfomationMap = std::map<TCharacterKey, TCharacterInfomation>;
        using TFontMap = std::map<WORD, HFONT>;

    protected:
        CGraphicDib m_dib;

        HFONT   m_hFontOld;
        HFONT   m_hFont;

        TGraphicImageTexturePointerVector m_pFontTextureVector;

        TCharacterInfomationMap m_charInfoMap;

        TFontMap m_fontMap;

        int m_x;
        int m_y;
        int m_step;
        bool m_isDirty;

        TCHAR   m_fontName[LF_FACESIZE];
        LONG    m_fontSize;
        bool    m_bItalic;
};
