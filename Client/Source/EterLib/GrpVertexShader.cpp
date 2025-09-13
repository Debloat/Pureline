#include "StdAfx.h"
#include "GrpVertexShader.h"
#include "GrpD3DXBuffer.h"
#include "StateManager.h"

CVertexShader::CVertexShader()
{
    Initialize();
}

CVertexShader::~CVertexShader()
{
    Destroy();
}

void CVertexShader::Initialize()
{
    m_pShader = nullptr;
    m_pVertexDecl = nullptr;
}

void CVertexShader::Destroy()
{
    if (m_pShader)
    {
        m_pShader->Release();
        m_pShader = nullptr;
    }
    if (m_pVertexDecl)
    {
        m_pVertexDecl->Release();
        m_pVertexDecl = nullptr;
    }
}

bool CVertexShader::CreateFromDiskFile(const char* c_szFileName, const D3DVERTEXELEMENT9* pVertexElements)
{
    Destroy(); // Release previous shader

    LPD3DXBUFFER pShaderBuffer = nullptr;
    LPD3DXBUFFER pErrorBuffer = nullptr;

    // Assemble shader from file (you can switch to CompileShaderFromFile if using HLSL)
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

    // Create the shader
    if (FAILED(ms_lpd3dDevice->CreateVertexShader(
                   (const DWORD*)pShaderBuffer->GetBufferPointer(),
                   &m_pShader)))
    {
        pShaderBuffer->Release();
        return false;
    }

    // Create the vertex declaration
    if (FAILED(ms_lpd3dDevice->CreateVertexDeclaration(
                   pVertexElements,
                   &m_pVertexDecl)))
    {
        m_pShader->Release();
        m_pShader = nullptr;
        pShaderBuffer->Release();
        return false;
    }

    pShaderBuffer->Release();
    return true;
}

void CVertexShader::Set()
{
    STATEMANAGER.SetVertexShader(m_pShader);
}
