#include "Stdafx.h"
#include "../EterPack/EterPackManager.h"

#include "terrain.h"
#include <math.h>

//////////////////////////////////////////////////////////////////////////
// Texture Set
//////////////////////////////////////////////////////////////////////////
CTextureSet* CTerrainImpl::ms_pTextureSet = nullptr;

void CTerrainImpl::SetTextureSet (CTextureSet * pTextureSet)
{
    static CTextureSet s_EmptyTextureSet;

    if (!pTextureSet)
    {
        ms_pTextureSet = &s_EmptyTextureSet;
    }
    else
    {
        ms_pTextureSet = pTextureSet;
    }
}

CTextureSet* CTerrainImpl::GetTextureSet()
{
    if (!ms_pTextureSet)
    {
        SetTextureSet (nullptr);
    }

    return ms_pTextureSet;
}

CTerrainImpl::CTerrainImpl()
{
    Initialize();
}

CTerrainImpl::~CTerrainImpl()
{
    Clear();
}

void CTerrainImpl::Initialize()
{
    memset (m_lWaterHeight, -1, sizeof (m_lWaterHeight));

    m_byNumWater = 0;
    memset (&m_HeightMapHeader, 0, sizeof (TGA_HEADER));
    memset (&m_lpAlphaTexture, NULL, sizeof (m_lpAlphaTexture));

    m_lViewRadius = 0;

    m_wTileMapVersion = 8976;

    m_fHeightScale = 0.0f;

    m_lSplatTilesX = 0;
    m_lSplatTilesY = 0;
}

void CTerrainImpl::Clear()
{
    for (DWORD i = 0; i < GetTextureSet()->GetTextureCount(); ++i)
    {
        if (m_lpAlphaTexture[i])
        {
            m_lpAlphaTexture[i]->Release();
            m_lpAlphaTexture[i] = nullptr;
        }
    }

    Initialize();
}

bool CTerrainImpl::LoadHeightMap (const char* c_szFileName)
{
    Tracef ("LoadRawHeightMapFile %s ", c_szFileName);

    CMappedFile kMappedFile;
    LPCVOID     lpcvFileData;

    if (!CEterPackManager::Instance().Get (kMappedFile, c_szFileName, &lpcvFileData))
    {
        Tracen ("Error");
        TraceError ("CTerrainImpl::LoadHeightMap - %s OPEN ERROR", c_szFileName);
        return false;
    }

    memcpy (m_awRawHeightMap, lpcvFileData, sizeof (WORD)*HEIGHTMAP_RAW_XSIZE * HEIGHTMAP_RAW_YSIZE);

    return true;
}

bool CTerrainImpl::LoadAttrMap (const char* c_szFileName)
{
    DWORD dwStart = ELTimer_GetMSec();
    Tracef ("LoadAttrMapFile %s ", c_szFileName);

    CMappedFile kMappedFile;
    LPCVOID     lpcvFileData;

    if (!CEterPackManager::Instance().Get (kMappedFile, c_szFileName, &lpcvFileData))
    {
        TraceError ("CTerrainImpl::LoadAttrMap - %s OPEN ERROR", c_szFileName);
        return false;
    }

    DWORD dwFileSize = kMappedFile.Size();
    BYTE * abFileData = (BYTE*) lpcvFileData;

    // LoadAttrMap
    {
#pragma pack(push)
#pragma pack(1)
        struct SAttrMapHeader
        {
            WORD m_wMagic;
            WORD m_wWidth;
            WORD m_wHeight;
        };
#pragma pack(pop)

        if (dwFileSize < sizeof (SAttrMapHeader))
        {
            TraceError (" CTerrainImpl::LoadAttrMap - %s FILE SIZE ERROR", c_szFileName);
            return false;
        }

        SAttrMapHeader kAttrMapHeader;
        memcpy (&kAttrMapHeader, abFileData, sizeof (kAttrMapHeader));

        if (const WORD c_wAttrMapMagic = 2634; c_wAttrMapMagic != kAttrMapHeader.m_wMagic)
        {
            TraceError ("CTerrainImpl::LoadAttrMap - %s MAGIC NUMBER(%d!=MAGIC[%d]) ERROR", c_szFileName, kAttrMapHeader.m_wMagic, kAttrMapHeader.m_wMagic);
            return false;
        }

        if (ATTRMAP_XSIZE != kAttrMapHeader.m_wWidth)
        {
            TraceError ("CTerrainImpl::LoadAttrMap - kAttrMapHeader(%s).m_width(%d)!=ATTRMAP_XSIZE(%d)", c_szFileName, kAttrMapHeader.m_wWidth, ATTRMAP_XSIZE);
            return false;
        }

        if (ATTRMAP_YSIZE != kAttrMapHeader.m_wHeight)
        {
            TraceError ("CTerrainImpl::LoadAttrMap - kAttrMapHeader(%s).m_height(%d)!=ATTRMAP_YSIZE(%d)", c_szFileName, kAttrMapHeader.m_wHeight, ATTRMAP_YSIZE);
            return false;
        }

        DWORD dwFileRestSize = dwFileSize - sizeof (kAttrMapHeader);
        if (DWORD dwFileNeedSize = sizeof (m_abyAttrMap); dwFileRestSize != dwFileNeedSize)
        {
            TraceError ("CTerrainImpl::LoadAttrMap - %s FILE DATA SIZE(rest %d != need %d) ERROR", c_szFileName, dwFileRestSize, dwFileNeedSize);
            return false;
        }

        BYTE* abSrcAttrData = abFileData + sizeof (kAttrMapHeader);
        memcpy (m_abyAttrMap, abSrcAttrData, sizeof (m_abyAttrMap));
    }

    Tracef ("%d\n", ELTimer_GetMSec() - dwStart);
    return true;
}

bool CTerrainImpl::RAW_LoadTileMap (const char* c_szFileName)
{
    Tracef ("LoadSplatFile %s ", c_szFileName);

    CMappedFile kMappedFile;
    LPCVOID     lpcvFileData;

    if (!CEterPackManager::Instance().Get (kMappedFile, c_szFileName, &lpcvFileData))
    {
        Tracen ("Error");
        TraceError ("CTerrainImpl::RAW_LoadTileMap - %s OPEN ERROR", c_szFileName);
        return false;
    }

    memcpy (m_abyTileMap, lpcvFileData, sizeof (BYTE) * (TILEMAP_RAW_XSIZE) * (TILEMAP_RAW_YSIZE));

    return true;

}

bool CTerrainImpl::LoadWaterMap (const char* c_szFileName)
{
    DWORD dwStart = ELTimer_GetMSec();

    if (!LoadWaterMapFile (c_szFileName))
    {
        memset (m_abyWaterMap, 0xFF, sizeof (m_abyWaterMap));

        m_byNumWater = 0;
        memset (m_lWaterHeight, -1, sizeof (m_lWaterHeight));

        TraceError ("CMapOutdoor::LoadWaterMap LoadWaterMapFile(%s) Failed", c_szFileName);

        return false;
    }

    Tracef ("LoadWaterMapFile %s %d\n", c_szFileName, ELTimer_GetMSec() - dwStart);
    return true;
}

bool CTerrainImpl::LoadWaterMapFile (const char* c_szFileName)
{
    CMappedFile kMappedFile;
    LPCVOID     lpcvFileData;

    if (!CEterPackManager::Instance().Get (kMappedFile, c_szFileName, &lpcvFileData))
    {
        Tracen ("Error");
        TraceError ("CTerrainImpl::LoadWaterMap - %s OPEN ERROR", c_szFileName);
        return false;
    }

    DWORD   dwFileSize = kMappedFile.Size();
    BYTE*   abFileData = (BYTE*)lpcvFileData;

    {
#pragma pack(push)
#pragma pack(1)
        struct SWaterMapHeader
        {
            WORD m_wMagic;
            WORD m_wWidth;
            WORD m_wHeight;
            BYTE m_byLayerCount;
        };
#pragma pack(pop)

        if (dwFileSize < sizeof (SWaterMapHeader))
        {
            TraceError ("CTerrainImpl::LoadWaterMap - %s FILE SIZE ERROR", c_szFileName);
            return false;
        }

        SWaterMapHeader kWaterMapHeader;
        memcpy (&kWaterMapHeader, abFileData, sizeof (kWaterMapHeader));

        if (const WORD c_wWaterMapMagic = 5426; c_wWaterMapMagic != kWaterMapHeader.m_wMagic)
        {
            TraceError ("CTerrainImpl::LoadWaterMap - %s MAGIC NUMBER(%d!=MAGIC[%d]) ERROR", c_szFileName, kWaterMapHeader.m_wMagic, c_wWaterMapMagic);
            return false;
        }

        if (WATERMAP_XSIZE != kWaterMapHeader.m_wWidth)
        {
            TraceError ("CTerrainImpl::LoadWaterMap - kWaterMapHeader(%s).m_width(%d)!=WATERMAP_XSIZE(%d)", c_szFileName, kWaterMapHeader.m_wWidth, WATERMAP_XSIZE);
            return false;
        }

        if (WATERMAP_YSIZE != kWaterMapHeader.m_wHeight)
        {
            TraceError ("CTerrainImpl::LoadWaterMap - kWaterMapHeader(%s).m_height(%d)!=WATERMAP_YSIZE(%d)", c_szFileName, kWaterMapHeader.m_wHeight, WATERMAP_YSIZE);
            return false;
        }

        m_byNumWater = kWaterMapHeader.m_byLayerCount;

        DWORD dwFileRestSize = dwFileSize - sizeof (kWaterMapHeader);
        DWORD dwFileNeedSize = sizeof (m_abyWaterMap) + sizeof (long) * m_byNumWater;
        DWORD dwFileNeedSize2 = sizeof (m_abyWaterMap) + sizeof (WORD) * m_byNumWater;
        if (dwFileRestSize == dwFileNeedSize2)
        {
            WORD wWaterHeight[MAX_WATER_NUM + 1];

            BYTE * abSrcWaterData = abFileData + sizeof (kWaterMapHeader);
            memcpy (m_abyWaterMap, abSrcWaterData, sizeof (m_abyWaterMap));

            BYTE * abSrcWaterHeight = abSrcWaterData + sizeof (m_abyWaterMap);

            m_byNumWater = MIN (MAX_WATER_NUM, m_byNumWater);
            if (m_byNumWater)
            {
                memcpy (wWaterHeight, abSrcWaterHeight, sizeof (WORD) * m_byNumWater);

                for (int i = 0; i < m_byNumWater; ++i)
                {
                    m_lWaterHeight[i] = wWaterHeight[i];
                }
            }
        }
        else if (dwFileRestSize != dwFileNeedSize)
        {
            TraceError ("CTerrainImpl::LoadWaterMap - %s FILE DATA SIZE(rest %d != need %d) ERROR", c_szFileName, dwFileRestSize, dwFileNeedSize);
            return false;
        }

        BYTE * abSrcWaterData = abFileData + sizeof (kWaterMapHeader);
        memcpy (m_abyWaterMap, abSrcWaterData, sizeof (m_abyWaterMap));

        BYTE * abSrcWaterHeight = abSrcWaterData + sizeof (m_abyWaterMap);

        if (m_byNumWater)
        {
            memcpy (m_lWaterHeight, abSrcWaterHeight, sizeof (long) * m_byNumWater);
        }
    }

    return true;
}
