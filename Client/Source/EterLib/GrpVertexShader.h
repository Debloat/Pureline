#pragma once

#include "GrpBase.h"

class CVertexShader : public CGraphicBase
{
    public:
        CVertexShader();
        virtual ~CVertexShader();

        void Destroy();
        bool CreateFromDiskFile (const char* c_szFileName, const D3DVERTEXELEMENT9* pVertexElements);

        void Set();

    protected:
        void Initialize();

    protected:
        IDirect3DVertexShader9* m_pShader;
        IDirect3DVertexDeclaration9* m_pVertexDecl;
};
