/**
 * @file   ImguiManager.h
 * @author blackdragonx61 / Mali
 * @date   22.08.2023
 * @brief  Manager of "Dear ImGui"
 * __BL_IMGUI__
 */

#pragma once

namespace M2ImguiManager
{
    void Create (HWND hwnd, LPDIRECT3DDEVICE9 device);
    void Destroy();
    LRESULT WndProcHandler (HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam);

    /*Render Stage*/
    void Start();
    void Render();
    void End();
}
