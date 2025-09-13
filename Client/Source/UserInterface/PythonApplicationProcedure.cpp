#include "StdAfx.h"
#include "PythonApplication.h"
#include "../EterLib/Camera.h"
#include "../CWebBrowser/CWebBrowser.h"

#include <winuser.h>

/* - IMGUI --------------------------------------------- */
#ifdef _DEBUG
    #include "ImguiManager.h"
    #include "../EterLib/ImGui/imgui.h"
#endif
/* ----------------------------------------------------- */

static int gs_nMouseCaptureRef = 0;

void CPythonApplication::SafeSetCapture()
{
    SetCapture(m_hWnd);
    gs_nMouseCaptureRef++;
}

void CPythonApplication::SafeReleaseCapture()
{
    gs_nMouseCaptureRef--;
    if (gs_nMouseCaptureRef == 0)
    {
        ReleaseCapture();
    }
}

void CPythonApplication::__SetFullScreenWindow(HWND hWnd, DWORD dwWidth, DWORD dwHeight)
{
    DEVMODE DevMode;
    DevMode.dmSize = sizeof(DevMode);
    DevMode.dmPelsWidth = dwWidth;
    DevMode.dmPelsHeight = dwHeight;
    DevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;

    LONG Error = ChangeDisplaySettings(&DevMode, CDS_FULLSCREEN);
    if (Error == DISP_CHANGE_RESTART)
    {
        ChangeDisplaySettings(nullptr, 0);
    }
}

void CPythonApplication::__MinimizeFullScreenWindow(HWND hWnd, DWORD dwWidth, DWORD dwHeight)
{
    ChangeDisplaySettings(nullptr, 0);
    SetWindowPos(hWnd, nullptr, 0, 0,
                 dwWidth,
                 dwHeight,
                 SWP_SHOWWINDOW);
    ShowWindow(hWnd, SW_MINIMIZE);
}

LRESULT CPythonApplication::WindowProcedure(HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
    /* - IMGUI --------------------------------------------- */
    #ifdef _DEBUG
    if (M2ImguiManager::WndProcHandler(hWnd, uiMsg, wParam, lParam))
    {
        return true;
    }
    #endif
    /* ----------------------------------------------------- */

    const int c_DoubleClickTime = 300;
    const int c_DoubleClickBox = 5;
    static int s_xDownPosition = 0;
    static int s_yDownPosition = 0;

    switch (uiMsg)
    {
        case WM_ACTIVATEAPP:
        {
            m_isActivateWnd = (wParam == WA_ACTIVE) || (wParam == WA_CLICKACTIVE);

            if (m_isActivateWnd)
            {
                m_SoundManager.RestoreVolume();

                //////////////////

                if (m_isWindowFullScreenEnable)
                {
                    __SetFullScreenWindow(hWnd, m_dwWidth, m_dwHeight);
                }
            }
            else
            {
                m_SoundManager.SaveVolume();

                //////////////////

                if (m_isWindowFullScreenEnable)
                {
                    __MinimizeFullScreenWindow(hWnd, m_dwWidth, m_dwHeight);
                }
            }
        }
        break;

        case WM_INPUTLANGCHANGE:
            return CPythonIME::Instance().WMInputLanguage(hWnd, uiMsg, wParam, lParam);
            break;

        case WM_IME_STARTCOMPOSITION:
            return CPythonIME::Instance().WMStartComposition(hWnd, uiMsg, wParam, lParam);
            break;

        case WM_IME_COMPOSITION:
            return CPythonIME::Instance().WMComposition(hWnd, uiMsg, wParam, lParam);
            break;

        case WM_IME_ENDCOMPOSITION:
            return CPythonIME::Instance().WMEndComposition(hWnd, uiMsg, wParam, lParam);
            break;

        case WM_IME_NOTIFY:
            return CPythonIME::Instance().WMNotify(hWnd, uiMsg, wParam, lParam);
            break;

        case WM_IME_SETCONTEXT:
            lParam &= ~(ISC_SHOWUICOMPOSITIONWINDOW | ISC_SHOWUIALLCANDIDATEWINDOW);
            break;

        case WM_CHAR:
            /* - IMGUI --------------------------------------------- */
            #ifdef _DEBUG
            if (ImGui::GetIO().WantCaptureKeyboard)
            {
                return 0;
            }
            #endif
            /* ----------------------------------------------------- */

            return CPythonIME::Instance().WMChar(hWnd, uiMsg, wParam, lParam);
            break;

        case WM_KEYDOWN:
            /* - IMGUI --------------------------------------------- */
            #ifdef _DEBUG
            if (ImGui::GetIO().WantCaptureKeyboard)
            {
                return 0;
            }
            #endif
            /* ----------------------------------------------------- */

            OnIMEKeyDown(LOWORD(wParam));
            break;

        case WM_LBUTTONDOWN:
            /* - IMGUI --------------------------------------------- */
            #ifdef _DEBUG
            if (GetCapture() != hWnd)
            {
                SafeSetCapture();
            }
            if (ImGui::GetIO().WantCaptureMouse)
            {
                return 0;
            }
            #else
            SafeSetCapture();
            #endif
            /* ----------------------------------------------------- */

            if (ELTimer_GetMSec() - m_dwLButtonDownTime < c_DoubleClickTime &&
                abs(LOWORD(lParam) - s_xDownPosition) < c_DoubleClickBox &&
                abs(HIWORD(lParam) - s_yDownPosition) < c_DoubleClickBox)
            {
                m_dwLButtonDownTime = 0;

                OnMouseLeftButtonDoubleClick(short (LOWORD(lParam)), short (HIWORD(lParam)));
            }
            else
            {
                m_dwLButtonDownTime = ELTimer_GetMSec();

                OnMouseLeftButtonDown(short (LOWORD(lParam)), short (HIWORD(lParam)));
            }

            s_xDownPosition = LOWORD(lParam);
            s_yDownPosition = HIWORD(lParam);
            return 0;

        case WM_LBUTTONUP:
            /* - IMGUI --------------------------------------------- */
            #ifdef _DEBUG
            if (GetCapture() != hWnd)
            {
                SafeSetCapture();
            }
            if (ImGui::GetIO().WantCaptureMouse)
            {
                return 0;
            }
            #endif
            /* ----------------------------------------------------- */

            m_dwLButtonUpTime = ELTimer_GetMSec();

            if (hWnd == GetCapture())
            {
                SafeReleaseCapture();
                OnMouseLeftButtonUp(short (LOWORD(lParam)), short (HIWORD(lParam)));
            }
            return 0;

        case WM_MBUTTONDOWN:
            /* - IMGUI --------------------------------------------- */
            #ifdef _DEBUG
            if (GetCapture() != hWnd)
            {
                SafeSetCapture();
            }
            if (ImGui::GetIO().WantCaptureMouse)
            {
                return 0;
            }
            #else
            SafeSetCapture();
            #endif
            /* ----------------------------------------------------- */

            UI::CWindowManager::Instance().RunMouseMiddleButtonDown(short (LOWORD(lParam)), short (HIWORD(lParam)));
            //          OnMouseMiddleButtonDown(short(LOWORD(lParam)), short(HIWORD(lParam)));
            break;

        case WM_MBUTTONUP:
            /* - IMGUI --------------------------------------------- */
            #ifdef _DEBUG
            if (GetCapture() != hWnd)
            {
                SafeSetCapture();
            }
            if (ImGui::GetIO().WantCaptureMouse)
            {
                return 0;
            }
            #endif
            /* ----------------------------------------------------- */

            if (GetCapture() == hWnd)
            {
                SafeReleaseCapture();

                UI::CWindowManager::Instance().RunMouseMiddleButtonUp(short (LOWORD(lParam)), short (HIWORD(lParam)));
                //              OnMouseMiddleButtonUp(short(LOWORD(lParam)), short(HIWORD(lParam)));
            }
            break;

        case WM_RBUTTONDOWN:
            /* - IMGUI --------------------------------------------- */
            #ifdef _DEBUG
            if (GetCapture() != hWnd)
            {
                SafeSetCapture();
            }
            if (ImGui::GetIO().WantCaptureMouse)
            {
                return 0;
            }
            #else
            SafeSetCapture();
            #endif
            /* ----------------------------------------------------- */

            OnMouseRightButtonDown(short (LOWORD(lParam)), short (HIWORD(lParam)));
            return 0;

        case WM_RBUTTONUP:
            /* - IMGUI --------------------------------------------- */
            #ifdef _DEBUG
            if (GetCapture() != hWnd)
            {
                SafeSetCapture();
            }
            if (ImGui::GetIO().WantCaptureMouse)
            {
                return 0;
            }
            #endif
            /* ----------------------------------------------------- */

            if (hWnd == GetCapture())
            {
                SafeReleaseCapture();

                OnMouseRightButtonUp(short (LOWORD(lParam)), short (HIWORD(lParam)));
            }
            return 0;

        case 0x20a:
            if (WebBrowser_IsVisible())
            {
                // 웹브라우저 상태일때는 휠 작동 안되도록 처리
            }
            else
            {
                /* - IMGUI --------------------------------------------- */
                #ifdef _DEBUG
                if (!ImGui::GetIO().WantCaptureMouse)
                {
                    OnMouseWheel(short (HIWORD(wParam)));
                }
                #else
                OnMouseWheel(short (HIWORD(wParam)));
                #endif
                /* ----------------------------------------------------- */
            }
            break;

        case WM_SIZE:
            switch (wParam)
            {
                case SIZE_RESTORED:
                case SIZE_MAXIMIZED:
                {
                    RECT rcWnd;
                    GetClientRect(&rcWnd);

                    UINT uWidth = rcWnd.right - rcWnd.left;
                    UINT uHeight = rcWnd.bottom - rcWnd.left;
                    m_grpDevice.ResizeBackBuffer(uWidth, uHeight);
                }
                break;
            }

            if (wParam == SIZE_MINIMIZED)
            {
                m_isMinimizedWnd = true;
            }
            else
            {
                m_isMinimizedWnd = false;
            }

            OnSizeChange(short (LOWORD(lParam)), short (HIWORD(lParam)));

            break;

        case WM_EXITSIZEMOVE:
        {
            RECT rcWnd;
            GetClientRect(&rcWnd);

            UINT uWidth = rcWnd.right - rcWnd.left;
            UINT uHeight = rcWnd.bottom - rcWnd.left;
            m_grpDevice.ResizeBackBuffer(uWidth, uHeight);
            OnSizeChange(short (LOWORD(lParam)), short (HIWORD(lParam)));
        }
        break;

        case WM_SYSKEYDOWN:
            switch (LOWORD(wParam))
            {
                case VK_F10:
                    break;
            }
            break;

        case WM_SYSKEYUP:
            switch (LOWORD(wParam))
            {
                case 18:
                    return FALSE;
                    break;
                case VK_F10:
                    break;
            }
            break;

        case WM_SETCURSOR:
            if (IsActive())
            {
                if (m_bCursorVisible && CURSOR_MODE_HARDWARE == m_iCursorMode)
                {
                    SetCursor((HCURSOR) m_hCurrentCursor);
                    return 0;
                }
                else
                {
                    SetCursor(nullptr);
                    return 0;
                }
            }
            break;

        case WM_CLOSE:
            #ifdef _DEBUG
            PostQuitMessage(0);
            #else
            RunPressExitKey();
            #endif
            return 0;

        case WM_DESTROY:
            return 0;
        default:
            //Tracenf("%x msg %x", timeGetTime(), uiMsg);
            break;
    }

    return CMSApplication::WindowProcedure(hWnd, uiMsg, wParam, lParam);
}
