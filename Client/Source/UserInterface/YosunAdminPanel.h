#pragma once

#ifdef _DEBUG

#include "../EterLib/ImGui/imgui.h"

#include "PythonNetworkStream.h"
#include "PythonPlayer.h"
#include "PythonChat.h"
#include "../EterBase/Debug.h"

#include <array>
#include <string_view>

class YosunAdminPanel
{
    public:
        YosunAdminPanel();
        ~YosunAdminPanel();

        void Render();
    private:
        void RenderMenuBar();

        /* - WORLD_EDITOR_IMGUI -------------------------------- */
        void RenderWorldEditor (bool* p_open) const;
        bool show_world_editor = false;
        /* ----------------------------------------------------- */

        void RenderGMCommands (bool* p_open);
        bool show_gm_commands = false;
        void GMCommandsList() const;
        void Warp();

        void RenderDebugOverlay (bool* p_open);
        bool show_debug_overlay = true;
        void DebugOverlayChangePosition (bool* p_open);
        int32_t location = 0;
        void RenderFpsLineGraph() const;

        struct AtlasEntry
        {
            std::string name;
            int         x;  // raw X*100 from AtlasInfo.txt
            int         y;  // raw Y*100
        };
        std::vector<AtlasEntry> m_atlasEntries;
        int                     m_warpIdx = 0;
        void LoadAtlasInfo();

        void RenderAnisotropy (bool* p_open) const;
        bool show_anisotropy = false;

        /* - SHADERS ------------------------------------------- */
        void RenderShaders (bool* p_open) const;
        bool show_shaders = false;
        /* ----------------------------------------------------- */
};

#endif /* _DEBUG */
