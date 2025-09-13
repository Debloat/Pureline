#include "StdAfx.h"
#include "GrpPixelShader.h"
#include "GrpD3DXBuffer.h"
#include "StateManager.h"

CPixelShader::CPixelShader()
{
    Initialize();
}

CPixelShader::~CPixelShader()
{
    Destroy();
}

void CPixelShader::Initialize()
{
    m_pShader = nullptr;
}

void CPixelShader::Destroy()
{
    if (m_pShader)
    {
        m_pShader->Release();
        m_pShader = nullptr;
    }
}

bool CPixelShader::CreateFromDiskFile(const char* c_szFileName)
{
    Destroy(); // Release any existing shader

    LPD3DXBUFFER pShaderBuffer = nullptr;
    LPD3DXBUFFER pErrorBuffer = nullptr;

    // Assemble the shader from file (you can also use CompileShaderFromFile for HLSL)
    if (FAILED(D3DXAssembleShaderFromFile(
                   c_szFileName,
                   NULL,
                   NULL,
                   0,
                   &pShaderBuffer,
                   &pErrorBuffer)))
    {
        if (pErrorBuffer)
        {
            OutputDebugStringA((const char*)pErrorBuffer->GetBufferPointer());
            pErrorBuffer->Release();
        }
        return false;
    }

    // Create the pixel shader from the assembled shader buffer
    if (FAILED(ms_lpd3dDevice->CreatePixelShader(
                   (const DWORD*)pShaderBuffer->GetBufferPointer(),
                   &m_pShader)))
    {
        pShaderBuffer->Release();
        return false;
    }

    pShaderBuffer->Release();
    return true;
}

void CPixelShader::Set()
{
    STATEMANAGER.SetPixelShader(m_pShader);
}
