/**
 * @file   ImguiManager.cpp
 * @author blackdragonx61 / Mali
 * @date   22.08.2023
 * @brief  Manager of "Dear ImGui"
 * __BL_IMGUI__
 */

#include "StdAfx.h"
#include "ImguiManager.h"

#include "../EterLib/StateManager.h"
#include "../EterLib/ImGui/imgui.h"
#include "../EterLib/ImGui/imgui_impl_dx9.h"
#include "../EterLib/ImGui/imgui_impl_win32.h"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

void M2ImguiManager::Create(HWND hwnd, LPDIRECT3DDEVICE9 device)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;

    io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\seguisym.ttf", 16.0f, nullptr, io.Fonts->GetGlyphRangesDefault());

    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
    io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

    ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX9_Init(device);
}

void M2ImguiManager::Destroy()
{
    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
}

LRESULT M2ImguiManager::WndProcHandler(HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
    return ImGui_ImplWin32_WndProcHandler(hWnd, uiMsg, wParam, lParam);
}

void M2ImguiManager::Start()
{
    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
}

void M2ImguiManager::Render()
{

}

void M2ImguiManager::End()
{
    ImGui::EndFrame();

    const DWORD state_D3DRS_ZENABLE = STATEMANAGER.GetRenderState(D3DRS_ZENABLE);
    const DWORD state_D3DRS_ALPHABLENDENABLE = STATEMANAGER.GetRenderState(D3DRS_ALPHABLENDENABLE);
    const DWORD state_D3DRS_SCISSORTESTENABLE = STATEMANAGER.GetRenderState(D3DRS_SCISSORTESTENABLE);

    STATEMANAGER.SetRenderState(D3DRS_ZENABLE, FALSE);
    STATEMANAGER.SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
    STATEMANAGER.SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);

    ImGui::Render();
    ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

    if (const ImGuiIO& io = ImGui::GetIO(); io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
    }

    STATEMANAGER.SetRenderState(D3DRS_ZENABLE, state_D3DRS_ZENABLE);
    STATEMANAGER.SetRenderState(D3DRS_ALPHABLENDENABLE, state_D3DRS_ALPHABLENDENABLE);
    STATEMANAGER.SetRenderState(D3DRS_SCISSORTESTENABLE, state_D3DRS_SCISSORTESTENABLE);
}
