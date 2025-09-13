#include "StdAfx.h"
#include "../EterBase/Error.h"
#include "../EterLib/Camera.h"
#include "../EterLib/AttributeInstance.h"
#include "../GameLib/AreaTerrain.h"
#include "../EterGrnLib/Material.h"
#include "../CWebBrowser/CWebBrowser.h"

#include "resource.h"
#include "PythonApplication.h"
#include "PythonCharacterManager.h"

#include "ProcessScanner.h"

#include "CheckLatestFiles.h"

/* - IMGUI --------------------------------------------- */
#ifdef _DEBUG
    #include "ImguiManager.h"
    #include "YosunAdminPanel.h"
    #include "../EterLib/ImGui/imgui.h"
#endif
/* - YOSUN_ADMIN_PANEL --------------------------------- */
#include "../SphereLib/YosunControlCenter.h"
/* ----------------------------------------------------- */
/* ----------------------------------------------------- */

extern void GrannyCreateSharedDeformBuffer();
extern void GrannyDestroySharedDeformBuffer();

float MIN_FOG = 2400.0f;
double g_specularSpd = 0.007f;

CPythonApplication* CPythonApplication::ms_pInstance;

float c_fDefaultCameraRotateSpeed = 1.5f;
float c_fDefaultCameraPitchSpeed = 1.5f;
float c_fDefaultCameraZoomSpeed = 0.05f;

CPythonApplication::CPythonApplication() :
    m_poMouseHandler(nullptr),
    m_fAveRenderTime(0.0f),
    m_dwLastIdleTime(0),
    m_fGlobalTime(0.0f),
    m_fGlobalElapsedTime(0.0f),
    m_dwUpdateFPS(0),
    m_dwRenderFPS(0),
    m_dwFaceCount(0),
    m_dwLButtonDownTime(0),
    m_bCursorVisible(TRUE),
    m_bLiarCursorOn(false),
    m_iCursorMode(CURSOR_MODE_HARDWARE),
    m_isWindowed(false),
    m_isFrameSkipDisable(false)
{
    #ifndef _DEBUG
    SetEterExceptionHandler();
    #endif

    CTimer::Instance().UseCustomTime();
    m_dwWidth = 800;
    m_dwHeight = 600;

    ms_pInstance = this;
    m_isWindowFullScreenEnable = FALSE;

    m_v3CenterPosition = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_dwStartLocalTime = ELTimer_GetMSec();
    m_tServerTime = 0;
    m_tLocalStartTime = 0;

    m_iPort = 0;
    m_iFPS = 60;

    m_isActivateWnd = false;
    m_isMinimizedWnd = true;

    m_fRotationSpeed = 0.0f;
    m_fPitchSpeed = 0.0f;
    m_fZoomSpeed = 0.0f;

    m_fFaceSpd = 0.0f;

    m_dwFaceAccCount = 0;
    m_dwFaceAccTime = 0;

    m_dwFaceSpdSum = 0;
    m_dwFaceSpdCount = 0;

    m_FlyingManager.SetMapManagerPtr(&m_pyBackground);

    m_iCursorNum = CURSOR_SHAPE_NORMAL;
    m_iContinuousCursorNum = CURSOR_SHAPE_NORMAL;

    m_isSpecialCameraMode = FALSE;
    m_fCameraRotateSpeed = c_fDefaultCameraRotateSpeed;
    m_fCameraPitchSpeed = c_fDefaultCameraPitchSpeed;
    m_fCameraZoomSpeed = c_fDefaultCameraZoomSpeed;

    m_iCameraMode = CAMERA_MODE_NORMAL;
    m_fBlendCameraStartTime = 0.0f;
    m_fBlendCameraBlendTime = 0.0f;

    m_iForceSightRange = -1;

    CCameraManager::Instance().AddCamera(EVENT_CAMERA_NUMBER);
}

CPythonApplication::~CPythonApplication()
{
}

void CPythonApplication::GetMousePosition(POINT* ppt)
{
    CMSApplication::GetMousePosition(ppt);
}

void CPythonApplication::SetMinFog(float fMinFog)
{
    MIN_FOG = fMinFog;
}

void CPythonApplication::SetFrameSkip(bool isEnable)
{
    if (isEnable)
    {
        m_isFrameSkipDisable = false;
    }
    else
    {
        m_isFrameSkipDisable = true;
    }
}

void CPythonApplication::NotifyHack(const char* c_szFormat, ...)
{
    char szBuf[1024];

    va_list args;
    va_start(args, c_szFormat);
    _vsnprintf(szBuf, sizeof(szBuf), c_szFormat, args);
    va_end(args);
    m_pyNetworkStream.NotifyHack(szBuf);
}

void CPythonApplication::GetInfo(UINT eInfo, std::string* pstInfo)
{
    switch (eInfo)
    {
        case INFO_ACTOR:
            m_kChrMgr.GetInfo(pstInfo);
            break;
        case INFO_EFFECT:
            m_kEftMgr.GetInfo(pstInfo);
            break;
        case INFO_ITEM:
            m_pyItem.GetInfo(pstInfo);
            break;
        case INFO_TEXTTAIL:
            m_pyTextTail.GetInfo(pstInfo);
            break;
    }
}

/* - ABORT_TRACEBACK_UPDATE ---------------------------- */
void CPythonApplication::Abort()
{
    TraceError("============================================================================================================");
    TraceError("Abort!!!!\n");

    if (PyThreadState* tstate = PyThreadState_GET())
    {
        for (PyFrameObject* frame = tstate->frame; frame; frame = frame->f_back)
        {
            PyCodeObject* f_code = frame->f_code;
            if (!f_code || !f_code->co_filename || !f_code->co_name)
            {
                continue;
            }

            const char* filename = PyString_AsString(f_code->co_filename);
            const char* funcname = PyString_AsString(f_code->co_name);
            int line = PyFrame_GetLineNumber(frame);
            TraceError("Filename = [%s] - Name = [%s] - Line = [%d]", filename, funcname, line);
        }
    }

    TraceError("============================================================================================================");

    PostQuitMessage(0);
}
/* ----------------------------------------------------- */

void CPythonApplication::Exit()
{
    PostQuitMessage(0);
}

bool PERF_CHECKER_RENDER_GAME = false;

void CPythonApplication::RenderGame()
{
    if (!PERF_CHECKER_RENDER_GAME)
    {
        float fAspect = m_kWndMgr.GetAspect();
        float fFarClip = m_pyBackground.GetFarClip();

        m_pyGraphic.SetPerspective(30.0f, fAspect, 100.0, fFarClip);

        CCullingManager::Instance().Process();

        m_kChrMgr.Deform();
        m_kEftMgr.Update();

        m_pyBackground.RenderCharacterShadowToTexture();

        m_pyGraphic.SetGameRenderState();
        m_pyGraphic.PushState();

        {
            long lx;
            long ly;
            m_kWndMgr.GetMousePosition(lx, ly);
            m_pyGraphic.SetCursorPosition(lx, ly);
        }

        m_pyBackground.RenderSky();

        m_pyBackground.RenderBeforeLensFlare();

        m_pyBackground.RenderCloud();

        m_pyBackground.BeginEnvironment();
        m_pyBackground.Render();

        m_pyBackground.SetCharacterDirLight();
        m_kChrMgr.Render();

        m_pyBackground.SetBackgroundDirLight();
        m_pyBackground.RenderWater();
        m_pyBackground.RenderSnow();
        m_pyBackground.RenderEffect();

        m_pyBackground.EndEnvironment();

        m_kEftMgr.Render();
        m_pyItem.Render();
        m_FlyingManager.Render();

        m_pyBackground.BeginEnvironment();
        m_pyBackground.RenderPCBlocker();
        m_pyBackground.EndEnvironment();

        m_pyBackground.RenderAfterLensFlare();

        return;
    }

    //if (GetAsyncKeyState(VK_Z))
    //  STATEMANAGER.SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

    DWORD t1 = ELTimer_GetMSec();
    m_kChrMgr.Deform();
    DWORD t2 = ELTimer_GetMSec();
    m_kEftMgr.Update();
    DWORD t3 = ELTimer_GetMSec();
    m_pyBackground.RenderCharacterShadowToTexture();
    DWORD t4 = ELTimer_GetMSec();

    m_pyGraphic.SetGameRenderState();
    m_pyGraphic.PushState();

    float fAspect = m_kWndMgr.GetAspect();
    float fFarClip = m_pyBackground.GetFarClip();

    m_pyGraphic.SetPerspective(30.0f, fAspect, 100.0, fFarClip);

    DWORD t5 = ELTimer_GetMSec();

    CCullingManager::Instance().Process();

    DWORD t6 = ELTimer_GetMSec();

    {
        long lx;
        long ly;
        m_kWndMgr.GetMousePosition(lx, ly);
        m_pyGraphic.SetCursorPosition(lx, ly);
    }

    m_pyBackground.RenderSky();
    DWORD t7 = ELTimer_GetMSec();
    m_pyBackground.RenderBeforeLensFlare();
    DWORD t8 = ELTimer_GetMSec();
    m_pyBackground.RenderCloud();
    DWORD t9 = ELTimer_GetMSec();
    m_pyBackground.BeginEnvironment();
    m_pyBackground.Render();

    m_pyBackground.SetCharacterDirLight();
    DWORD t10 = ELTimer_GetMSec();
    m_kChrMgr.Render();
    DWORD t11 = ELTimer_GetMSec();

    m_pyBackground.SetBackgroundDirLight();
    m_pyBackground.RenderWater();
    DWORD t12 = ELTimer_GetMSec();
    m_pyBackground.RenderEffect();
    DWORD t13 = ELTimer_GetMSec();
    m_pyBackground.EndEnvironment();
    m_kEftMgr.Render();
    DWORD t14 = ELTimer_GetMSec();
    m_pyItem.Render();
    DWORD t15 = ELTimer_GetMSec();
    m_FlyingManager.Render();
    DWORD t16 = ELTimer_GetMSec();
    m_pyBackground.BeginEnvironment();
    m_pyBackground.RenderPCBlocker();
    m_pyBackground.EndEnvironment();
    DWORD t17 = ELTimer_GetMSec();
    m_pyBackground.RenderAfterLensFlare();
    DWORD t18 = ELTimer_GetMSec();
    DWORD tEnd = ELTimer_GetMSec();

    if (GetAsyncKeyState(VK_Z))
    {
        STATEMANAGER.SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
    }

    if (tEnd - t1 < 3)
    {
        return;
    }

    static FILE* fp = fopen("perf_game_render.txt", "w");

    fprintf(fp, "GR.Total %d (Time %d)\n", tEnd - t1, ELTimer_GetMSec());
    fprintf(fp, "GR.DFM %d\n", t2 - t1);
    fprintf(fp, "GR.EFT.UP %d\n", t3 - t2);
    fprintf(fp, "GR.SHW %d\n", t4 - t3);
    fprintf(fp, "GR.STT %d\n", t5 - t4);
    fprintf(fp, "GR.CLL %d\n", t6 - t5);
    fprintf(fp, "GR.BG.SKY %d\n", t7 - t6);
    fprintf(fp, "GR.BG.LEN %d\n", t8 - t7);
    fprintf(fp, "GR.BG.CLD %d\n", t9 - t8);
    fprintf(fp, "GR.BG.MAIN %d\n", t10 - t9);
    fprintf(fp, "GR.CHR %d\n", t11 - t10);
    fprintf(fp, "GR.BG.WTR %d\n", t12 - t11);
    fprintf(fp, "GR.BG.EFT %d\n", t13 - t12);
    fprintf(fp, "GR.EFT %d\n", t14 - t13);
    fprintf(fp, "GR.ITM %d\n", t15 - t14);
    fprintf(fp, "GR.FLY %d\n", t16 - t15);
    fprintf(fp, "GR.BG.BLK %d\n", t17 - t16);
    fprintf(fp, "GR.BG.LEN %d\n", t18 - t17);


    fflush(fp);
}

void CPythonApplication::UpdateGame()
{
    DWORD t1 = ELTimer_GetMSec();
    POINT ptMouse;
    GetMousePosition(&ptMouse);

    CGraphicTextInstance::Hyperlink_UpdateMousePos(ptMouse.x, ptMouse.y);

    DWORD t2 = ELTimer_GetMSec();

    //!@# Alt+Tab 중 SetTransfor 에서 튕김 현상 해결을 위해 - [levites]
    //if (m_isActivateWnd)
    {
        CScreen s;
        float fAspect = UI::CWindowManager::Instance().GetAspect();
        float fFarClip = CPythonBackground::Instance().GetFarClip();

        s.SetPerspective(30.0f, fAspect, 100.0f, fFarClip);
        s.BuildViewFrustum();
    }

    DWORD t3 = ELTimer_GetMSec();
    TPixelPosition kPPosMainActor;
    m_pyPlayer.NEW_GetMainActorPosition(&kPPosMainActor);

    DWORD t4 = ELTimer_GetMSec();
    m_pyBackground.Update(kPPosMainActor.x, kPPosMainActor.y, kPPosMainActor.z);

    DWORD t5 = ELTimer_GetMSec();
    m_GameEventManager.SetCenterPosition(kPPosMainActor.x, kPPosMainActor.y, kPPosMainActor.z);
    m_GameEventManager.Update();

    DWORD t6 = ELTimer_GetMSec();
    m_kChrMgr.Update();
    DWORD t7 = ELTimer_GetMSec();
    m_kEftMgr.UpdateSound();
    DWORD t8 = ELTimer_GetMSec();
    m_FlyingManager.Update();
    DWORD t9 = ELTimer_GetMSec();
    m_pyItem.Update(ptMouse);
    DWORD t10 = ELTimer_GetMSec();
    m_pyPlayer.Update();
    DWORD t11 = ELTimer_GetMSec();

    // NOTE : Update 동안 위치 값이 바뀌므로 다시 얻어 옵니다 - [levites]
    //        이 부분 때문에 메인 케릭터의 Sound가 이전 위치에서 플레이 되는 현상이 있었음.
    m_pyPlayer.NEW_GetMainActorPosition(&kPPosMainActor);
    SetCenterPosition(kPPosMainActor.x, kPPosMainActor.y, kPPosMainActor.z);
    DWORD t12 = ELTimer_GetMSec();

    if (PERF_CHECKER_RENDER_GAME)
    {
        if (t12 - t1 > 5)
        {
            static FILE* fp = fopen("perf_game_update.txt", "w");

            fprintf(fp, "GU.Total %d (Time %d)\n", t12 - t1, ELTimer_GetMSec());
            fprintf(fp, "GU.GMP %d\n", t2 - t1);
            fprintf(fp, "GU.SCR %d\n", t3 - t2);
            fprintf(fp, "GU.MPS %d\n", t4 - t3);
            fprintf(fp, "GU.BG %d\n", t5 - t4);
            fprintf(fp, "GU.GEM %d\n", t6 - t5);
            fprintf(fp, "GU.CHR %d\n", t7 - t6);
            fprintf(fp, "GU.EFT %d\n", t8 - t7);
            fprintf(fp, "GU.FLY %d\n", t9 - t8);
            fprintf(fp, "GU.ITM %d\n", t10 - t9);
            fprintf(fp, "GU.PLR %d\n", t11 - t10);
            fprintf(fp, "GU.POS %d\n", t12 - t11);
            fflush(fp);
        }
    }
}

void CPythonApplication::SkipRenderBuffering(DWORD dwSleepMSec)
{
    m_dwBufSleepSkipTime = ELTimer_GetMSec() + dwSleepMSec;
}

bool CPythonApplication::Process()
{
    #if defined(CHECK_LATEST_DATA_FILES)
    if (CheckLatestFiles_PollEvent())
    {
        return false;
    }
    #endif
    ELTimer_SetFrameMSec();

    //  m_Profiler.Clear();
    DWORD dwStart = ELTimer_GetMSec();

    ///////////////////////////////////////////////////////////////////////////////////////////////////
    static DWORD    s_dwUpdateFrameCount = 0;
    static DWORD    s_dwRenderFrameCount = 0;
    static DWORD    s_dwFaceCount = 0;
    static UINT     s_uiLoad = 0;

    if (static DWORD    s_dwCheckTime = ELTimer_GetMSec(); ELTimer_GetMSec() - s_dwCheckTime > 1000)
    {
        m_dwUpdateFPS       = s_dwUpdateFrameCount;
        m_dwRenderFPS       = s_dwRenderFrameCount;
        m_dwLoad            = s_uiLoad;

        m_dwFaceCount       = s_dwFaceCount / max(1, s_dwRenderFrameCount);

        s_dwCheckTime       = ELTimer_GetMSec();

        s_uiLoad = s_dwFaceCount = s_dwUpdateFrameCount = s_dwRenderFrameCount = 0;
    }

    // Update Time
    static BOOL s_bFrameSkip = false;
    static UINT s_uiNextFrameTime = ELTimer_GetMSec();

    #ifdef __PERFORMANCE_CHECK__
    DWORD dwUpdateTime1 = ELTimer_GetMSec();
    #endif
    CTimer& rkTimer = CTimer::Instance();
    rkTimer.Advance();

    m_fGlobalTime = rkTimer.GetCurrentSecond();
    m_fGlobalElapsedTime = rkTimer.GetElapsedSecond();

    UINT uiFrameTime = rkTimer.GetElapsedMilliecond();
    s_uiNextFrameTime += uiFrameTime;   //17 - 1초당 60fps기준.

    DWORD updatestart = ELTimer_GetMSec();
    #ifdef __PERFORMANCE_CHECK__
    DWORD dwUpdateTime2 = ELTimer_GetMSec();
    #endif
    // Network I/O
    m_pyNetworkStream.Process();
    //m_pyNetworkDatagram.Process();

    m_kGuildMarkUploader.Process();
    m_kGuildMarkDownloader.Process();
    m_kAccountConnector.Process();

    #ifdef __PERFORMANCE_CHECK__
    DWORD dwUpdateTime3 = ELTimer_GetMSec();
    #endif
    //////////////////////
    // Input Process
    // Keyboard
    /* - IMGUI --------------------------------------------- */
    #ifdef _DEBUG
    if (!ImGui::GetIO().WantCaptureKeyboard)
    {
        UpdateKeyboard();
    }
    #else
    UpdateKeyboard();
    #endif
    /* ----------------------------------------------------- */

    #ifdef __PERFORMANCE_CHECK__
    DWORD dwUpdateTime4 = ELTimer_GetMSec();
    #endif
    // Mouse
    if (POINT Point; GetCursorPos(&Point))
    {
        ScreenToClient(m_hWnd, &Point);
        OnMouseMove(Point.x, Point.y);
    }
    //////////////////////
    #ifdef __PERFORMANCE_CHECK__
    DWORD dwUpdateTime5 = ELTimer_GetMSec();
    #endif
    //!@# Alt+Tab 중 SetTransfor 에서 튕김 현상 해결을 위해 - [levites]
    //if (m_isActivateWnd)
    __UpdateCamera();
    #ifdef __PERFORMANCE_CHECK__
    DWORD dwUpdateTime6 = ELTimer_GetMSec();
    #endif
    // Update Game Playing
    CResourceManager::Instance().Update();
    #ifdef __PERFORMANCE_CHECK__
    DWORD dwUpdateTime7 = ELTimer_GetMSec();
    #endif
    OnCameraUpdate();
    #ifdef __PERFORMANCE_CHECK__
    DWORD dwUpdateTime8 = ELTimer_GetMSec();
    #endif
    OnMouseUpdate();
    #ifdef __PERFORMANCE_CHECK__
    DWORD dwUpdateTime9 = ELTimer_GetMSec();
    #endif
    OnUIUpdate();

    #ifdef __PERFORMANCE_CHECK__
    DWORD dwUpdateTime10 = ELTimer_GetMSec();

    if (dwUpdateTime10 - dwUpdateTime1 > 10)
    {
        static FILE* fp = fopen("perf_app_update.txt", "w");

        fprintf(fp, "AU.Total %d (Time %d)\n", dwUpdateTime9 - dwUpdateTime1, ELTimer_GetMSec());
        fprintf(fp, "AU.TU %d\n", dwUpdateTime2 - dwUpdateTime1);
        fprintf(fp, "AU.NU %d\n", dwUpdateTime3 - dwUpdateTime2);
        fprintf(fp, "AU.KU %d\n", dwUpdateTime4 - dwUpdateTime3);
        fprintf(fp, "AU.MP %d\n", dwUpdateTime5 - dwUpdateTime4);
        fprintf(fp, "AU.CP %d\n", dwUpdateTime6 - dwUpdateTime5);
        fprintf(fp, "AU.RU %d\n", dwUpdateTime7 - dwUpdateTime6);
        fprintf(fp, "AU.CU %d\n", dwUpdateTime8 - dwUpdateTime7);
        fprintf(fp, "AU.MU %d\n", dwUpdateTime9 - dwUpdateTime8);
        fprintf(fp, "AU.UU %d\n", dwUpdateTime10 - dwUpdateTime9);
        fprintf(fp, "----------------------------------\n");
        fflush(fp);
    }
    #endif

    //Update하는데 걸린시간.delta값
    m_dwCurUpdateTime = ELTimer_GetMSec() - updatestart;

    DWORD dwCurrentTime = ELTimer_GetMSec();
    BOOL  bCurrentLateUpdate = FALSE;

    s_bFrameSkip = false;

    if (dwCurrentTime > s_uiNextFrameTime)
    {
        int dt = dwCurrentTime - s_uiNextFrameTime;
        int nAdjustTime = ((float)dt / (float)uiFrameTime) * uiFrameTime;

        if (dt >= 500)
        {
            s_uiNextFrameTime += nAdjustTime;
            printf("FrameSkip 보정 %d\n", nAdjustTime);
            CTimer::Instance().Adjust(nAdjustTime);
        }

        s_bFrameSkip = true;
        bCurrentLateUpdate = TRUE;
    }

    if (m_isFrameSkipDisable)
    {
        s_bFrameSkip = false;
    }

    #ifdef __VTUNE__
    s_bFrameSkip = false;
    #endif

    if (!s_bFrameSkip)
    {
        CGrannyMaterial::TranslateSpecularMatrix(g_specularSpd, g_specularSpd, 0.0f);

        DWORD dwRenderStartTime = ELTimer_GetMSec();

        bool canRender = true;

        if (m_isMinimizedWnd)
        {
            canRender = false;
        }
        else
        {
            if (m_pyGraphic.IsLostDevice())
            {
                CPythonBackground& rkBG = CPythonBackground::Instance();
                rkBG.ReleaseCharacterShadowTexture();

                /* - SHADERS ------------------------------------------- */
                m_ShaderManager.LostDevice();
                /* ----------------------------------------------------- */

                if (m_pyGraphic.RestoreDevice())
                {
                    rkBG.CreateCharacterShadowTexture();

                    /* - SHADERS ------------------------------------------- */
                    m_ShaderManager.RestoreDevice();
                    /* ----------------------------------------------------- */
                }
                else
                {
                    canRender = false;
                }
            }
        }

        if (!IsActive())
        {
            SkipRenderBuffering(3000);
        }

        // 리스토어 처리때를 고려해 일정 시간동안은 버퍼링을 하지 않는다
        if (!canRender)
        {
            SkipRenderBuffering(3000);
        }
        else
        {
            // RestoreLostDevice
            CCullingManager::Instance().Update();
            if (m_pyGraphic.Begin())
            {

                m_pyGraphic.ClearDepthBuffer();

                #ifdef _DEBUG
                m_pyGraphic.SetClearColor(0.3f, 0.3f, 0.3f);
                m_pyGraphic.Clear();
                #endif

                /////////////////////
                // Interface
                m_pyGraphic.SetInterfaceRenderState();

                OnUIRender();
                OnMouseRender();

                /* - IMGUI --------------------------------------------- */
                #ifdef _DEBUG
                M2ImguiManager::Start();
                M2ImguiManager::Render();
                /* - YOSUN_ADMIN_PANEL --------------------------------- */
                static YosunAdminPanel admin_panel;
                admin_panel.Render();
                /* ----------------------------------------------------- */
                ImGui::ShowDemoWindow();
                M2ImguiManager::End();
                #endif
                /* ----------------------------------------------------- */

                /////////////////////

                m_pyGraphic.End();

                //DWORD t1 = ELTimer_GetMSec();
                m_pyGraphic.Show();
                //DWORD t2 = ELTimer_GetMSec();

                DWORD dwRenderEndTime = ELTimer_GetMSec();

                static DWORD s_dwRenderCheckTime = dwRenderEndTime;
                static DWORD s_dwRenderRangeTime = 0;
                static DWORD s_dwRenderRangeFrame = 0;

                m_dwCurRenderTime = dwRenderEndTime - dwRenderStartTime;
                s_dwRenderRangeTime += m_dwCurRenderTime;
                ++s_dwRenderRangeFrame;

                if (dwRenderEndTime - s_dwRenderCheckTime > 1000)
                {
                    m_fAveRenderTime = float (double (s_dwRenderRangeTime) / double (s_dwRenderRangeFrame));

                    s_dwRenderCheckTime = ELTimer_GetMSec();
                    s_dwRenderRangeTime = 0;
                    s_dwRenderRangeFrame = 0;
                }

                DWORD dwCurFaceCount = m_pyGraphic.GetFaceCount();
                m_pyGraphic.ResetFaceCount();
                s_dwFaceCount += dwCurFaceCount;

                if (dwCurFaceCount > 5000)
                {
                    // 프레임 완충 처리
                    if (dwRenderEndTime > m_dwBufSleepSkipTime)
                    {
                        static float s_fBufRenderTime = 0.0f;

                        if (float fCurRenderTime = m_dwCurRenderTime; fCurRenderTime > s_fBufRenderTime)
                        {
                            float fRatio = fMAX(0.5f, (fCurRenderTime - s_fBufRenderTime) / 30.0f);
                            s_fBufRenderTime = (s_fBufRenderTime * (100.0f - fRatio) + (fCurRenderTime + 5) * fRatio) / 100.0f;
                        }
                        else
                        {
                            float fRatio = 0.5f;
                            s_fBufRenderTime = (s_fBufRenderTime * (100.0f - fRatio) + fCurRenderTime * fRatio) / 100.0f;
                        }

                        // 한계치를 정한다
                        if (s_fBufRenderTime > 100.0f)
                        {
                            s_fBufRenderTime = 100.0f;
                        }

                        DWORD dwBufRenderTime = s_fBufRenderTime;

                        if (m_isWindowed)
                        {
                            if (dwBufRenderTime > 58)
                            {
                                dwBufRenderTime = 64;
                            }
                            else if (dwBufRenderTime > 42)
                            {
                                dwBufRenderTime = 48;
                            }
                            else if (dwBufRenderTime > 26)
                            {
                                dwBufRenderTime = 32;
                            }
                            else if (dwBufRenderTime > 10)
                            {
                                dwBufRenderTime = 16;
                            }
                            else
                            {
                                dwBufRenderTime = 8;
                            }
                        }

                        // 일정 프레임 속도에 맞추어주는쪽에 눈에 편하다
                        // 아래에서 한번 하면 됬�?
                        //if (m_dwCurRenderTime<dwBufRenderTime)
                        //  Sleep(dwBufRenderTime-m_dwCurRenderTime);

                        m_fAveRenderTime = s_fBufRenderTime;
                    }

                    m_dwFaceAccCount += dwCurFaceCount;
                    m_dwFaceAccTime += m_dwCurRenderTime;

                    m_fFaceSpd = (m_dwFaceAccCount / m_dwFaceAccTime);

                    // 거리 자동 조절
                    if (-1 == m_iForceSightRange)
                    {
                        static float s_fAveRenderTime = 16.0f;
                        float fRatio = 0.3f;
                        s_fAveRenderTime = (s_fAveRenderTime * (100.0f-fRatio) + max(16.0f, m_dwCurRenderTime) * fRatio) / 100.0f;


                        float fFar = 25600.0f;
                        float fNear = MIN_FOG;
                        double dbAvePow = double (1000.0f / s_fAveRenderTime);
                        double dbMaxPow = 60.0;
                        float fDistance = max(fNear + (fFar - fNear) * (dbAvePow) / dbMaxPow, fNear);
                        m_pyBackground.SetViewDistanceSet(0, fDistance);
                    }
                    // 거리 강제 설정시
                    else
                    {
                        m_pyBackground.SetViewDistanceSet(0, float (m_iForceSightRange));
                    }
                }
                else
                {
                    // 10000 폴리곤 보다 적을때는 가장 멀리 보이게 한다
                    m_pyBackground.SetViewDistanceSet(0, 25600.0f);
                }

                ++s_dwRenderFrameCount;
            }
        }
    }

    if (int rest = s_uiNextFrameTime - ELTimer_GetMSec(); rest > 0 && !bCurrentLateUpdate)
    {
        s_uiLoad -= rest;   // 쉰 시간은 로드에서 뺀다..
        Sleep(rest);
    }

    ++s_dwUpdateFrameCount;

    s_uiLoad += ELTimer_GetMSec() - dwStart;
    //m_Profiler.ProfileByScreen();
    return true;
}

void CPythonApplication::UpdateClientRect()
{
    RECT rcApp;
    GetClientRect(&rcApp);
    OnSizeChange(rcApp.right - rcApp.left, rcApp.bottom - rcApp.top);
}

void CPythonApplication::SetMouseHandler(PyObject* poMouseHandler)
{
    m_poMouseHandler = poMouseHandler;
}

int CPythonApplication::CheckDeviceState()
{
    switch (CGraphicDevice::EDeviceState e_deviceState = m_grpDevice.GetDeviceState())
    {
        // 디바이스가 없으면 프로그램이 종료 되어야 한다.
        case CGraphicDevice::DEVICESTATE_NULL:
            return DEVICE_STATE_FALSE;

        // DEVICESTATE_BROKEN일 때는 다음 루프에서 복구 될 수 있도록 리턴 한다.
        // 그냥 진행할 경우 DrawPrimitive 같은 것을 하면 프로그램이 터진다.
        case CGraphicDevice::DEVICESTATE_BROKEN:
            return DEVICE_STATE_SKIP;

        case CGraphicDevice::DEVICESTATE_NEEDS_RESET:
            if (!m_grpDevice.Reset())
            {
                return DEVICE_STATE_SKIP;
            }

            break;
    }

    return DEVICE_STATE_OK;
}

bool CPythonApplication::CreateDevice(int width, int height, int Windowed, int frequency /* = 0*/)
{
    int iRet;

    m_grpDevice.InitBackBufferCount(2);
    m_grpDevice.RegisterWarningString(CGraphicDevice::CREATE_BAD_DRIVER, ApplicationStringTable_GetStringz(IDS_WARN_BAD_DRIVER, "WARN_BAD_DRIVER"));
    m_grpDevice.RegisterWarningString(CGraphicDevice::CREATE_NO_TNL, ApplicationStringTable_GetStringz(IDS_WARN_NO_TNL, "WARN_NO_TNL"));

    iRet = m_grpDevice.Create(GetWindowHandle(), width, height, Windowed ? true : false, frequency);

    switch (iRet)
    {
        case CGraphicDevice::CREATE_OK:
            return true;

        case CGraphicDevice::CREATE_REFRESHRATE:
            return true;

        case CGraphicDevice::CREATE_ENUM:
        case CGraphicDevice::CREATE_DETECT:
            SET_EXCEPTION(CREATE_NO_APPROPRIATE_DEVICE);
            TraceError("CreateDevice: Enum & Detect failed");
            return false;

        case CGraphicDevice::CREATE_NO_DIRECTX:
            //PyErr_SetString(PyExc_RuntimeError, "DirectX 9 or greater required to run game");
            SET_EXCEPTION(CREATE_NO_DIRECTX);
            TraceError("CreateDevice: DirectX 9 or greater required to run game");
            return false;

        case CGraphicDevice::CREATE_DEVICE:
            //PyErr_SetString(PyExc_RuntimeError, "GraphicDevice create failed");
            SET_EXCEPTION(CREATE_DEVICE);
            TraceError("CreateDevice: GraphicDevice create failed");
            return false;

        /*case CGraphicDevice::CREATE_GET_ADAPTER_DISPLAY_MODE:
        //PyErr_SetString(PyExc_RuntimeError, "GetAdapterDisplayMode failed");
        SET_EXCEPTION(CREATE_GET_ADAPTER_DISPLAY_MODE);
        TraceError("CreateDevice: GetAdapterDisplayMode failed");
        return false;*/

        case CGraphicDevice::CREATE_GET_DEVICE_CAPS:
            PyErr_SetString(PyExc_RuntimeError, "GetDevCaps failed");
            TraceError("CreateDevice: GetDevCaps failed");
            return false;

        case CGraphicDevice::CREATE_GET_DEVICE_CAPS2:
            PyErr_SetString(PyExc_RuntimeError, "GetDevCaps2 failed");
            TraceError("CreateDevice: GetDevCaps2 failed");
            return false;

        default:
            if (iRet & CGraphicDevice::CREATE_OK)
            {
                //if (iRet & CGraphicDevice::CREATE_BAD_DRIVER)
                //{
                //  LogBox(ApplicationStringTable_GetStringz(IDS_WARN_BAD_DRIVER), NULL, GetWindowHandle());
                //}
                if (iRet & CGraphicDevice::CREATE_NO_TNL)
                {
                    CGrannyLODController::SetMinLODMode(true);
                    //LogBox(ApplicationStringTable_GetStringz(IDS_WARN_NO_TNL), NULL, GetWindowHandle());
                }
                return true;
            }

            //PyErr_SetString(PyExc_RuntimeError, "Unknown Error!");
            SET_EXCEPTION(UNKNOWN_ERROR);
            TraceError("CreateDevice: Unknown Error!");
            return false;
    }
}

void CPythonApplication::Loop()
{
    while (1)
    {
        if (IsMessage())
        {
            if (!MessageProcess())
            {
                break;
            }
        }
        else
        {
            if (!Process())
            {
                break;
            }

            m_dwLastIdleTime = ELTimer_GetMSec();
        }
    }
}

// SUPPORT_NEW_KOREA_SERVER
bool LoadLocaleData(const char* localePath)
{
    NANOBEGIN
    CPythonNonPlayer&   rkNPCMgr    = CPythonNonPlayer::Instance();
    CItemManager&       rkItemMgr   = CItemManager::Instance();
    CPythonSkill&       rkSkillMgr  = CPythonSkill::Instance();
    CPythonNetworkStream& rkNetStream = CPythonNetworkStream::Instance();

    /* - CLIENT_LOCALE_STRING ------------------------------ */
    CPythonLocale& rkLocale = CPythonLocale::Instance();
    /* ----------------------------------------------------- */

    char szItemList[256];
    char szItemProto[256];
    char szItemDesc[256];

    /* - CLIENT_LOCALE_STRING ------------------------------ */
    char szLocaleTextString[256];
    char szLocaleQuestString[256];
    char szLocaleQuizString[256];
    /* ----------------------------------------------------- */

    char szMobProto[256];
    char szSkillDescFileName[256];
    char szSkillTableFileName[256];
    char szInsultList[256];
    snprintf(szItemList,   sizeof(szItemList),    "locale/common/item_list.txt");
    snprintf(szItemProto,  sizeof(szItemProto),   "%s/item_proto",    localePath);
    snprintf(szItemDesc,   sizeof(szItemDesc),    "%s/itemdesc.txt",  localePath);

    /* - CLIENT_LOCALE_STRING ------------------------------ */
    snprintf(szLocaleTextString, sizeof(szLocaleTextString), "%s/locale_string.txt", localePath);
    snprintf(szLocaleQuestString, sizeof(szLocaleQuestString), "%s/locale_quest.txt", localePath);
    snprintf(szLocaleQuizString, sizeof(szLocaleQuizString), "%s/locale_quiz.txt", localePath);
    /* ----------------------------------------------------- */

    snprintf(szMobProto,   sizeof(szMobProto),    "%s/mob_proto",     localePath);
    snprintf(szSkillDescFileName, sizeof(szSkillDescFileName),    "%s/SkillDesc.txt", localePath);
    snprintf(szSkillTableFileName, sizeof(szSkillTableFileName),  "locale/common/SkillTable.txt");
    snprintf(szInsultList, sizeof(szInsultList),  "%s/insult.txt", localePath);

    rkNPCMgr.Destroy();
    rkItemMgr.Destroy();
    rkSkillMgr.Destroy();

    if (!rkItemMgr.LoadItemList(szItemList))
    {
        TraceError("LoadLocaleData - LoadItemList(%s) Error", szItemList);
    }

    if (!rkItemMgr.LoadItemTable(szItemProto))
    {
        TraceError("LoadLocaleData - LoadItemProto(%s) Error", szItemProto);
        return false;
    }

    if (!rkItemMgr.LoadItemDesc(szItemDesc))
    {
        Tracenf("LoadLocaleData - LoadItemDesc(%s) Error", szItemDesc);
    }

    /* - CLIENT_LOCALE_STRING ------------------------------ */
    if (!rkLocale.LoadLocaleString(szLocaleTextString))
    {
        TraceError("LoadLocaleData - LoadLocaleString(%s) Error", szLocaleTextString);
        return false;
    }

    if (!rkLocale.LoadQuestLocaleString(szLocaleQuestString))
    {
        TraceError("LoadLocaleData - LoadQuestLocaleString(%s) Error", szLocaleQuestString);
        return false;
    }

    if (!rkLocale.LoadOXQuizLocaleString(szLocaleQuizString))
    {
        TraceError("LoadLocaleData - LoadOXQuizLocaleString(%s) Error", szLocaleQuizString);
        return false;
    }
    /* ----------------------------------------------------- */

    if (!rkNPCMgr.LoadNonPlayerData(szMobProto))
    {
        TraceError("LoadLocaleData - LoadMobProto(%s) Error", szMobProto);
        return false;
    }

    if (!rkSkillMgr.RegisterSkillDesc(szSkillDescFileName))
    {
        TraceError("LoadLocaleData - RegisterSkillDesc(%s) Error", szMobProto);
        return false;
    }

    if (!rkSkillMgr.RegisterSkillTable(szSkillTableFileName))
    {
        TraceError("LoadLocaleData - RegisterSkillTable(%s) Error", szMobProto);
        return false;
    }

    if (!rkNetStream.LoadInsultList(szInsultList))
    {
        Tracenf("CPythonApplication - CPythonNetworkStream::LoadInsultList(%s)", szInsultList);
    }

    if (LocaleService_IsYMIR())
    {
        char szEmpireTextConvFile[256];
        for (DWORD dwEmpireID = 1; dwEmpireID <= 3; ++dwEmpireID)
        {
            sprintf(szEmpireTextConvFile, "%s/lang%d.cvt", localePath, dwEmpireID);
            if (!rkNetStream.LoadConvertTable(dwEmpireID, szEmpireTextConvFile))
            {
                TraceError("LoadLocaleData - CPythonNetworkStream::LoadConvertTable(%d, %s) FAILURE", dwEmpireID, szEmpireTextConvFile);
            }
        }
    }

    NANOEND
    return true;
}
// END_OF_SUPPORT_NEW_KOREA_SERVER

unsigned __GetWindowMode(bool windowed)
{
    if (windowed)
    {
        return WS_OVERLAPPED | WS_CAPTION |   WS_SYSMENU | WS_MINIMIZEBOX;
    }

    return WS_POPUP;
}

bool CPythonApplication::Create(PyObject * poSelf, const char* c_szName, int width, int height, int Windowed)
{
    NANOBEGIN
    Windowed = CPythonSystem::Instance().IsWindowed() ? 1 : 0;

    bool bAnotherWindow = false;

    if (FindWindow(nullptr, c_szName))
    {
        bAnotherWindow = true;
    }

    m_dwWidth = width;
    m_dwHeight = height;

    // Window

    if (UINT WindowMode = __GetWindowMode(Windowed ? true : false);
        !CMSWindow::Create(c_szName, 4, 0, WindowMode, ::LoadIcon(GetInstance(), MAKEINTRESOURCE(IDI_METIN2)), IDC_CURSOR_NORMAL))
    {
        //PyErr_SetString(PyExc_RuntimeError, "CMSWindow::Create failed");
        TraceError("CMSWindow::Create failed");
        SET_EXCEPTION(CREATE_WINDOW);
        return false;
    }

    if (m_pySystem.IsUseDefaultIME())
    {
        CPythonIME::Instance().UseDefaultIME();
    }

    #if defined(ENABLE_DISCORD_RPC)
    m_pyNetworkStream.Discord_Start();
    #endif

    // 풀스크린 모드이고
    // 디폴트 IME 를 사용하거나 유럽 버전이면
    // 윈도우 풀스크린 모드를 사용한다
    if (!m_pySystem.IsWindowed() && (m_pySystem.IsUseDefaultIME() || LocaleService_IsEUROPE()))
    {
        m_isWindowed = false;
        m_isWindowFullScreenEnable = TRUE;
        __SetFullScreenWindow(GetWindowHandle(), width, height);

        Windowed = true;
    }
    else
    {
        AdjustSize(m_pySystem.GetWidth(), m_pySystem.GetHeight());

        if (Windowed)
        {
            m_isWindowed = true;

            if (bAnotherWindow)
            {
                RECT rc;

                GetClientRect(&rc);

                int windowWidth = rc.right - rc.left;
                int windowHeight = (rc.bottom - rc.top);

                CMSApplication::SetPosition(GetScreenWidth() - windowWidth, GetScreenHeight() - 60 - windowHeight);
            }
        }
        else
        {
            m_isWindowed = false;
            SetPosition(0, 0);
        }
    }

    NANOEND
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Cursor
    if (!CreateCursors())
    {
        //PyErr_SetString(PyExc_RuntimeError, "CMSWindow::Cursors Create Error");
        TraceError("CMSWindow::Cursors Create Error");
        SET_EXCEPTION("CREATE_CURSOR");
        return false;
    }

    if (!m_pySystem.IsNoSoundCard())
    {
        // Sound
        if (!m_SoundManager.Create())
        {
            // NOTE : 중국측의 요청으로 생략
            //      LogBox(ApplicationStringTable_GetStringz(IDS_WARN_NO_SOUND_DEVICE));
        }
    }

    // Device
    if (!CreateDevice(m_pySystem.GetWidth(), m_pySystem.GetHeight(), Windowed, m_pySystem.GetFrequency()))
    {
        return false;
    }

    GrannyCreateSharedDeformBuffer();

    SetVisibleMode(true);

    /* - IMGUI --------------------------------------------- */
    #ifdef _DEBUG
    M2ImguiManager::Create(m_hWnd, m_pyGraphic.GetD3DDevice());
    #endif
    /* ----------------------------------------------------- */
    /* - YOSUN_ADMIN_PANEL --------------------------------- */
    static YosunControlCenter YosunControlCenter; // Must exist in both debug and release builds
    /* ----------------------------------------------------- */

    if (m_isWindowFullScreenEnable) //m_pySystem.IsUseDefaultIME() && !m_pySystem.IsWindowed())
    {
        SetWindowPos(GetWindowHandle(), HWND_TOP, 0, 0, width, height, SWP_SHOWWINDOW);
    }

    if (!InitializeKeyboard(GetWindowHandle()))
    {
        return false;
    }

    m_pySystem.GetDisplaySettings();

    // Mouse
    if (m_pySystem.IsSoftwareCursor())
    {
        SetCursorMode(CURSOR_MODE_SOFTWARE);
    }
    else
    {
        SetCursorMode(CURSOR_MODE_HARDWARE);
    }

    // Network
    if (!m_netDevice.Create())
    {
        //PyErr_SetString(PyExc_RuntimeError, "NetDevice::Create failed");
        TraceError("NetDevice::Create failed");
        SET_EXCEPTION("CREATE_NETWORK");
        return false;
    }

    m_pyItem.Create();

    // Other Modules
    DefaultFont_Startup();

    CPythonIME::Instance().Create(GetWindowHandle());
    CPythonIME::Instance().SetText("", 0);
    CPythonTextTail::Instance().Initialize();

    // Light Manager
    m_LightManager.Initialize();

    CGraphicImageInstance::CreateSystem(32);

    /* - SHADERS ------------------------------------------- */
    if (!m_ShaderManager.Initialize())
    {
        return false;
    }
    /* ----------------------------------------------------- */

    // 백업
    STICKYKEYS sStickKeys;
    memset(&sStickKeys, 0, sizeof(sStickKeys));
    sStickKeys.cbSize = sizeof(sStickKeys);
    SystemParametersInfo(SPI_GETSTICKYKEYS, sizeof(sStickKeys), &sStickKeys, 0);
    m_dwStickyKeysFlag = sStickKeys.dwFlags;

    // 설정
    sStickKeys.dwFlags &= ~(SKF_AVAILABLE | SKF_HOTKEYACTIVE);
    SystemParametersInfo(SPI_SETSTICKYKEYS, sizeof(sStickKeys), &sStickKeys, 0);

    // SphereMap
    CGrannyMaterial::CreateSphereMap(0, "d:/ymir work/special/spheremap.jpg");
    CGrannyMaterial::CreateSphereMap(1, "d:/ymir work/special/spheremap01.jpg");
    return true;
}

void CPythonApplication::SetGlobalCenterPosition(LONG x, LONG y)
{
    CPythonBackground& rkBG = CPythonBackground::Instance();
    rkBG.GlobalPositionToLocalPosition(x, y);

    float z = CPythonBackground::Instance().GetHeight(x, y);

    CPythonApplication::Instance().SetCenterPosition(x, y, z);
}

void CPythonApplication::SetCenterPosition(float fx, float fy, float fz)
{
    m_v3CenterPosition.x = +fx;
    m_v3CenterPosition.y = -fy;
    m_v3CenterPosition.z = +fz;
}

void CPythonApplication::GetCenterPosition(TPixelPosition * pPixelPosition)
{
    pPixelPosition->x = +m_v3CenterPosition.x;
    pPixelPosition->y = -m_v3CenterPosition.y;
    pPixelPosition->z = +m_v3CenterPosition.z;
}


void CPythonApplication::SetServerTime(time_t tTime)
{
    m_dwStartLocalTime  = ELTimer_GetMSec();
    m_tServerTime       = tTime;
    m_tLocalStartTime   = time(nullptr);
}

time_t CPythonApplication::GetServerTime()
{
    return (ELTimer_GetMSec() - m_dwStartLocalTime) + m_tServerTime;
}

// 2005.03.28 - MALL 아이템에 들어있는 시간의 단위가 서버에서 time(0) 으로 만들어지는
//              값이기 때문에 단위를 맞추기 위해 시간 관련 처리를 별도로 추가
time_t CPythonApplication::GetServerTimeStamp()
{
    return (time(nullptr) - m_tLocalStartTime) + m_tServerTime;
}

float CPythonApplication::GetGlobalTime()
{
    return m_fGlobalTime;
}

float CPythonApplication::GetGlobalElapsedTime()
{
    return m_fGlobalElapsedTime;
}

void CPythonApplication::SetFPS(int iFPS)
{
    m_iFPS = iFPS;
}

int CPythonApplication::GetWidth() const
{
    return m_dwWidth;
}

int CPythonApplication::GetHeight() const
{
    return m_dwHeight;
}

void CPythonApplication::SetConnectData(const char* c_szIP, int iPort)
{
    m_strIP = c_szIP;
    m_iPort = iPort;
}

void CPythonApplication::GetConnectData(std::string & rstIP, int& riPort)
{
    rstIP   = m_strIP;
    riPort  = m_iPort;
}

void CPythonApplication::EnableSpecialCameraMode()
{
    m_isSpecialCameraMode = TRUE;
}

void CPythonApplication::SetCameraSpeed(int iPercentage)
{
    m_fCameraRotateSpeed = c_fDefaultCameraRotateSpeed * float (iPercentage) / 100.0f;
    m_fCameraPitchSpeed = c_fDefaultCameraPitchSpeed * float (iPercentage) / 100.0f;
    m_fCameraZoomSpeed = c_fDefaultCameraZoomSpeed * float (iPercentage) / 100.0f;
}

void CPythonApplication::SetForceSightRange(int iRange)
{
    m_iForceSightRange = iRange;
}

void CPythonApplication::Clear()
{
    m_pySystem.Clear();
}

void CPythonApplication::Destroy()
{
    WebBrowser_Destroy();

    // SphereMap
    CGrannyMaterial::DestroySphereMap();

    m_kWndMgr.Destroy();

    CPythonSystem::Instance().SaveConfig();

    DestroyCollisionInstanceSystem();

    /* - SHADERS ------------------------------------------- */
    m_ShaderManager.Destroy();
    /* ----------------------------------------------------- */

    m_pySystem.SaveInterfaceStatus();

    m_pyEventManager.Destroy();
    m_FlyingManager.Destroy();

    m_pyMiniMap.Destroy();

    m_pyTextTail.Destroy();
    m_pyChat.Destroy();
    m_kChrMgr.Destroy();
    m_RaceManager.Destroy();

    m_pyItem.Destroy();
    m_kItemMgr.Destroy();

    m_pyBackground.Destroy();

    m_kEftMgr.Destroy();
    m_LightManager.Destroy();

    // DEFAULT_FONT
    DefaultFont_Cleanup();
    // END_OF_DEFAULT_FONT

    GrannyDestroySharedDeformBuffer();

    m_pyGraphic.Destroy();

    #if defined(ENABLE_DISCORD_RPC)
    m_pyNetworkStream.Discord_Close();
    #endif

    //m_pyNetworkDatagram.Destroy();

    m_pyRes.Destroy();

    m_kGuildMarkDownloader.Disconnect();

    CGrannyModelInstance::DestroySystem();
    CGraphicImageInstance::DestroySystem();


    m_SoundManager.Destroy();
    m_grpDevice.Destroy();

    // FIXME : 만들어져 있지 않음 - [levites]
    //CSpeedTreeForestDirectX9::Instance().Clear();

    CAttributeInstance::DestroySystem();
    CTextFileLoader::DestroySystem();
    DestroyCursors();

    /* - IMGUI --------------------------------------------- */
    #ifdef _DEBUG
    M2ImguiManager::Destroy();
    #endif
    /* ----------------------------------------------------- */

    CMSApplication::Destroy();

    STICKYKEYS sStickKeys;
    memset(&sStickKeys, 0, sizeof(sStickKeys));
    sStickKeys.cbSize = sizeof(sStickKeys);
    sStickKeys.dwFlags = m_dwStickyKeysFlag;
    SystemParametersInfo(SPI_SETSTICKYKEYS, sizeof(sStickKeys), &sStickKeys, 0);
}
