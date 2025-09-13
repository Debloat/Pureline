#include "StdAfx.h"
#include "../EterBase/MappedFile.h"
#include "../EterPack/EterPackManager.h"
#include "GrpImageTexture.h"

bool CGraphicImageTexture::Lock (int* pRetPitch, void** ppRetPixels, int level)
{
    D3DLOCKED_RECT lockedRect;
    if (FAILED (m_lpd3dTexture->LockRect (level, &lockedRect, NULL, 0)))
    {
        return false;
    }

    *pRetPitch = lockedRect.Pitch;
    *ppRetPixels = lockedRect.pBits;
    return true;
}

void CGraphicImageTexture::Unlock (int level)
{
    assert (m_lpd3dTexture != nullptr);
    m_lpd3dTexture->UnlockRect (level);
}

void CGraphicImageTexture::Initialize()
{
    CGraphicTexture::Initialize();

    m_stFileName = "";

    m_d3dFmt = D3DFMT_UNKNOWN;
    m_dwFilter = 0;
}

void CGraphicImageTexture::Destroy()
{
    CGraphicTexture::Destroy();

    Initialize();
}

bool CGraphicImageTexture::CreateDeviceObjects()
{
    assert (ms_lpd3dDevice != nullptr);
    assert (m_lpd3dTexture == nullptr);

    if (m_stFileName.empty())
    {
        DWORD usage = 0;
        if (m_d3dFmt == D3DFMT_A8R8G8B8 || m_d3dFmt == D3DFMT_A4R4G4B4)
            usage = D3DUSAGE_DYNAMIC;

        // 폰트 텍스쳐
        if (FAILED (ms_lpd3dDevice->CreateTexture (m_width, m_height, 1, usage, m_d3dFmt, D3DPOOL_DEFAULT, &m_lpd3dTexture, nullptr)))
        {
            return false;
        }
    }
    else
    {
        CMappedFile mappedFile;
        LPCVOID     c_pvMap;

        if (!CEterPackManager::Instance().Get (mappedFile, m_stFileName.c_str(), &c_pvMap))
        {
            return false;
        }

        return CreateFromMemoryFile (mappedFile.Size(), c_pvMap, m_d3dFmt, m_dwFilter);
    }

    m_bEmpty = false;
    return true;
}

bool CGraphicImageTexture::Create (UINT width, UINT height, D3DFORMAT d3dFmt, DWORD dwFilter)
{
    assert (ms_lpd3dDevice != nullptr);
    Destroy();

    m_width = width;
    m_height = height;
    m_d3dFmt = d3dFmt;
    m_dwFilter = dwFilter;

    return CreateDeviceObjects();
}

void CGraphicImageTexture::CreateFromTexturePointer (const CGraphicTexture * c_pSrcTexture)
{
    if (m_lpd3dTexture)
    {
        m_lpd3dTexture->Release();
    }

    m_width = c_pSrcTexture->GetWidth();
    m_height = c_pSrcTexture->GetHeight();
    m_lpd3dTexture = c_pSrcTexture->GetD3DTexture();

    if (m_lpd3dTexture)
    {
        m_lpd3dTexture->AddRef();
    }

    m_bEmpty = false;
}

bool CGraphicImageTexture::CreateDDSTexture (CDXTCImage & image, const BYTE* /*c_pbBuf*/)
{
    int mipmapCount = image.m_dwMipMapCount == 0 ? 1 : image.m_dwMipMapCount;

    D3DFORMAT format;
    LPDIRECT3DTEXTURE9 lpd3dTexture;

    if (image.m_CompFormat == PF_DXT5)
    {
        format = D3DFMT_DXT5;
    }
    else if (image.m_CompFormat == PF_DXT3)
    {
        format = D3DFMT_DXT3;
    }
    else
    {
        format = D3DFMT_DXT1;
    }

    UINT uMinMipMapIndex = 0;

    if (FAILED (D3DXCreateTexture (ms_lpd3dDevice, image.m_nWidth, image.m_nHeight,
                                   mipmapCount, D3DUSAGE_DYNAMIC, format, D3DPOOL_DEFAULT, &lpd3dTexture)))
    {
        TraceError ("CreateDDSTexture: Cannot creatre texture");
        return false;
    }

    for (DWORD i = 0; i < mipmapCount; ++i)
    {
        D3DLOCKED_RECT lockedRect;

        if (FAILED (lpd3dTexture->LockRect (i, &lockedRect, NULL, 0)))
        {
            TraceError ("CreateDDSTexture: Cannot lock texture");
        }
        else
        {
            image.Copy (i + uMinMipMapIndex, (BYTE*)lockedRect.pBits, lockedRect.Pitch);
            lpd3dTexture->UnlockRect (i);
        }
    }

    m_lpd3dTexture = lpd3dTexture;

    m_width = image.m_nWidth;
    m_height = image.m_nHeight;
    m_bEmpty = false;

    return true;
}

bool CGraphicImageTexture::CreateFromMemoryFile (UINT bufSize, const void* c_pvBuf, D3DFORMAT d3dFmt, DWORD dwFilter)
{
    assert (ms_lpd3dDevice != nullptr);
    assert (m_lpd3dTexture == nullptr);

    if (static CDXTCImage image; image.LoadHeaderFromMemory ((const BYTE*) c_pvBuf))    // DDS인가 확인
    {
        return (CreateDDSTexture (image, (const BYTE*) c_pvBuf));
    }
    else
    {
        D3DXIMAGE_INFO imageInfo;
        if (FAILED (D3DXCreateTextureFromFileInMemoryEx (
                        ms_lpd3dDevice,
                        c_pvBuf,
                        bufSize,
                        D3DX_DEFAULT,
                        D3DX_DEFAULT,
                        D3DX_DEFAULT,
                        0,
                        d3dFmt,
                        D3DPOOL_DEFAULT,
                        dwFilter,
                        dwFilter,
                        0xffff00ff,
                        &imageInfo,
                        nullptr,
                        &m_lpd3dTexture)))
        {
            TraceError ("CreateFromMemoryFile: Cannot create texture");
            return false;
        }

        m_width = imageInfo.Width;
        m_height = imageInfo.Height;
    }

    m_bEmpty = false;
    return true;
}

void CGraphicImageTexture::SetFileName (const char* c_szFileName)
{
    m_stFileName = c_szFileName;
}

bool CGraphicImageTexture::CreateFromDiskFile (const char* c_szFileName, D3DFORMAT d3dFmt, DWORD dwFilter)
{
    Destroy();

    SetFileName (c_szFileName);

    m_d3dFmt = d3dFmt;
    m_dwFilter = dwFilter;
    return CreateDeviceObjects();
}

CGraphicImageTexture::CGraphicImageTexture()
{
    Initialize();
}

CGraphicImageTexture::~CGraphicImageTexture()
{
    Destroy();
}
