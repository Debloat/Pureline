#pragma once

#include "GrpDetector.h"
#include "Ray.h"
#include <vector>

void PixelPositionToD3DXVECTOR3(const D3DXVECTOR3& c_rkPPosSrc, D3DXVECTOR3* pv3Dst);
void D3DXVECTOR3ToPixelPosition(const D3DXVECTOR3& c_rv3Src, D3DXVECTOR3* pv3Dst);

class CGraphicTexture;

using TIndex = WORD;

using TFace = struct SFace
{
    TIndex indices[3];
};

using TPosition = D3DXVECTOR3;

using TNormal = D3DXVECTOR3;

using TTextureCoordinate = D3DXVECTOR2;

using TDiffuse = DWORD;
using TAmbient = DWORD;
using TSpecular = DWORD;

using TDepth = union UDepth
                   {
                       float    f;
                       long l;
                       DWORD    dw;
                   };

using TVertex = struct SVertex
{
    float x;
    float y;
    float z;
    DWORD color;
    float u;
    float v;
};

struct STVertex
{
    float x;
    float y;
    float z;
    float rhw;
};

struct SPVertex
{
    float x;
    float y;
    float z;
};

using TPDVertex = struct SPDVertex
{
    float x;
    float y;
    float z;
    DWORD color;
};

struct SPDTVertexRaw
{
    float px;
    float py;
    float pz;
    DWORD diffuse;
    float u;
    float v;
};

using TPTVertex = struct SPTVertex
{
    TPosition position;
    TTextureCoordinate texCoord;
};

using TPDTVertex = struct SPDTVertex
{
    TPosition   position;
    TDiffuse    diffuse;
    TTextureCoordinate texCoord;
};

using TPNTVertex = struct SPNTVertex
{
    TPosition           position;
    TNormal             normal;
    TTextureCoordinate  texCoord;
};

using TPNT2Vertex = struct SPNT2Vertex
{
    TPosition   position;
    TNormal     normal;
    TTextureCoordinate texCoord;
    TTextureCoordinate texCoord2;
};

using TPDT2Vertex = struct SPDT2Vertex
{
    TPosition   position;
    DWORD       diffuse;
    TTextureCoordinate texCoord;
    TTextureCoordinate texCoord2;
};

using TNameInfo = struct SNameInfo
{
    DWORD   name;
    TDepth  depth;
};

using TBoundBox = struct SBoundBox
{
    float sx;
    float sy;
    float sz;
    float ex;
    float ey;
    float ez;
    int meshIndex;
    int boneIndex;
};

const WORD c_FillRectIndices[6] = { 0, 2, 1, 2, 3, 1 };

/*
enum EIndexCount
{
    LINE_INDEX_COUNT = 2,
    TRIANGLE_INDEX_COUNT = 2*3,
    RECTANGLE_INDEX_COUNT = 2*4,
    CUBE_INDEX_COUNT = 2*4*3,
    FILLED_TRIANGLE_INDEX_COUNT = 3,
    FILLED_RECTANGLE_INDEX_COUNT = 3*2,
    FILLED_CUBE_INDEX_COUNT = 3*2*6,
};
*/

class CGraphicBase
{
    public:
        static DWORD GetAvailableTextureMemory();
        static const D3DXMATRIX& GetViewMatrix();
        static const D3DXMATRIX& GetIdentityMatrix();

        enum
        {
            DEFAULT_IB_LINE,
            DEFAULT_IB_LINE_TRI,
            DEFAULT_IB_LINE_RECT,
            DEFAULT_IB_LINE_CUBE,
            DEFAULT_IB_FILL_TRI,
            DEFAULT_IB_FILL_RECT,
            DEFAULT_IB_FILL_CUBE,
            DEFAULT_IB_NUM,
        };

    public:
        CGraphicBase();
        virtual ~CGraphicBase();

        void        SetSimpleCamera(float x, float y, float z, float pitch, float roll);
        void        SetEyeCamera(float xEye, float yEye, float zEye, float xCenter, float yCenter, float zCenter, float xUp, float yUp, float zUp);
        void        SetAroundCamera(float distance, float pitch, float roll, float lookAtZ = 0.0f);
        void        SetPositionCamera(float fx, float fy, float fz, float fDistance, float fPitch, float fRotation);
        void        MoveCamera(float fdeltax, float fdeltay, float fdeltaz);

        void        GetTargetPosition(float* px, float* py, float* pz);
        void        GetCameraPosition(float* px, float* py, float* pz);
        void        SetOrtho2D(float hres, float vres, float zres);
        void        SetOrtho3D(float hres, float vres, float zmin, float zmax);
        void        SetPerspective(float fov, float aspect, float nearz, float farz);
        float       GetFOV();
        void        GetClipPlane(float* fNearY, float* fFarY)
        {
            *fNearY = ms_fNearY;
            *fFarY = ms_fFarY;
        }

        ////////////////////////////////////////////////////////////////////////
        void        PushMatrix();

        void        MultMatrix(const D3DXMATRIX* pMat);
        void        MultMatrixLocal(const D3DXMATRIX* pMat);

        void        Translate(float x, float y, float z);
        void        Rotate(float degree, float x, float y, float z);
        void        RotateLocal(float degree, float x, float y, float z);
        void        RotateYawPitchRollLocal(float fYaw, float fPitch, float fRoll);
        void        Scale(float x, float y, float z);
        void        PopMatrix();
        void        LoadMatrix(const D3DXMATRIX & c_rSrcMatrix);
        void        GetMatrix(D3DXMATRIX * pRetMatrix) const;
        const       D3DXMATRIX* GetMatrixPointer() const;

        // Special Routine
        void        GetSphereMatrix(D3DXMATRIX * pMatrix, float fValue = 0.1f);

        ////////////////////////////////////////////////////////////////////////
        void        InitScreenEffect();
        void        SetScreenEffectWaving(float fDuringTime, int iPower);
        void        SetScreenEffectFlashing(float fDuringTime, const D3DXCOLOR & c_rColor);

        ////////////////////////////////////////////////////////////////////////
        DWORD       GetColor(float r, float g, float b, float a = 1.0f);

        DWORD       GetFaceCount();
        void        ResetFaceCount();
        HRESULT     GetLastResult();

        void        UpdateProjMatrix();
        void        UpdateViewMatrix();

        void        SetViewport(DWORD dwX, DWORD dwY, DWORD dwWidth, DWORD dwHeight, float fMinZ, float fMaxZ);
        static void     GetBackBufferSize(UINT* puWidth, UINT* puHeight);
        static bool     IsTLVertexClipping();

        static void SetDefaultIndexBuffer(UINT eDefIB);
        static bool SetPDTStream(SPDTVertexRaw* pVertices, UINT uVtxCount);
        static bool SetPDTStream(SPDTVertex* pVertices, UINT uVtxCount);

    protected:
        static D3DXMATRIX               ms_matIdentity;

        static D3DXMATRIX               ms_matView;
        static D3DXMATRIX               ms_matProj;
        static D3DXMATRIX               ms_matInverseView;
        static D3DXMATRIX               ms_matInverseViewYAxis;

        static D3DXMATRIX               ms_matWorld;
        static D3DXMATRIX               ms_matWorldView;

    protected:
        //void      UpdatePrePipeLineMatrix();
        void        UpdatePipeLineMatrix();

    protected:
        // 각종 D3DX Mesh 들 (컬루젼 데이터 등을 표시활 때 쓴다)
        static LPD3DXMESH               ms_lpSphereMesh;
        static LPD3DXMESH               ms_lpCylinderMesh;

    protected:
        static HRESULT                  ms_hLastResult;

        static int                      ms_iWidth;
        static int                      ms_iHeight;

        static UINT                     ms_iD3DAdapterInfo;
        static UINT                     ms_iD3DDevInfo;
        static UINT                     ms_iD3DModeInfo;
        static D3D_CDisplayModeAutoDetector             ms_kD3DDetector;

        static HWND                     ms_hWnd;
        static HDC                      ms_hDC;
        static LPDIRECT3D9EX            ms_lpd3d;
        static LPDIRECT3DDEVICE9EX      ms_lpd3dDevice;
        static ID3DXMatrixStack*        ms_lpd3dMatStack;
        static D3DVIEWPORT9             ms_Viewport;

        static DWORD                    ms_faceCount;
        static D3DCAPS9                 ms_d3dCaps;
        static D3DPRESENT_PARAMETERS    ms_d3dPresentParameter;

        static DWORD                    ms_dwD3DBehavior;
        static LPDIRECT3DVERTEXDECLARATION9                 ms_ptVS;
        static LPDIRECT3DVERTEXDECLARATION9                 ms_pntVS;
        static LPDIRECT3DVERTEXDECLARATION9                 ms_pnt2VS;

        static D3DXMATRIX               ms_matScreen0;
        static D3DXMATRIX               ms_matScreen1;
        static D3DXMATRIX               ms_matScreen2;
        //static D3DXMATRIX             ms_matPrePipeLine;

        static D3DXVECTOR3              ms_vtPickRayOrig;
        static D3DXVECTOR3              ms_vtPickRayDir;

        static float                    ms_fFieldOfView;
        static float                    ms_fAspect;
        static float                    ms_fNearY;
        static float                    ms_fFarY;

        // 2004.11.18.myevan.DynamicVertexBuffer로 교체
        /*
        static std::vector<TIndex>      ms_lineIdxVector;
        static std::vector<TIndex>      ms_lineTriIdxVector;
        static std::vector<TIndex>      ms_lineRectIdxVector;
        static std::vector<TIndex>      ms_lineCubeIdxVector;

        static std::vector<TIndex>      ms_fillTriIdxVector;
        static std::vector<TIndex>      ms_fillRectIdxVector;
        static std::vector<TIndex>      ms_fillCubeIdxVector;
        */

        // Screen Effect - Waving, Flashing and so on..
        static DWORD                    ms_dwWavingEndTime;
        static int                      ms_iWavingPower;
        static DWORD                    ms_dwFlashingEndTime;
        static D3DXCOLOR                ms_FlashingColor;

        // Terrain picking용 Ray... CCamera 이용하는 버전.. 기존의 Ray와 통합 필요...
        static CRay                     ms_Ray;

        enum
        {
            PDT_VERTEX_NUM = 16,
            PDT_VERTEXBUFFER_NUM = 100,
        };


        static LPDIRECT3DVERTEXBUFFER9  ms_alpd3dPDTVB[PDT_VERTEXBUFFER_NUM];
        static LPDIRECT3DINDEXBUFFER9   ms_alpd3dDefIB[DEFAULT_IB_NUM];
};
