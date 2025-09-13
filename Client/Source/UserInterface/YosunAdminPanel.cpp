#include "StdAfx.h"
#include "YosunAdminPanel.h"

#include "../SphereLib/YosunControlCenter.h"
#include "PythonBackground.h"
#include "../EterPack/EterPackManager.h"

#include <Psapi.h>

/* - SHADERS ------------------------------------------- */
#include "ShaderManager.h"
/* ----------------------------------------------------- */

#ifdef _DEBUG

YosunAdminPanel::YosunAdminPanel()
{
    LoadAtlasInfo();
}

YosunAdminPanel::~YosunAdminPanel() = default;

void YosunAdminPanel::Render()
{
    constexpr char kMainPanelName[] = "Yosun Admin Panel";

    if (ImGuiWindowFlags mainFlags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_AlwaysAutoResize;
        ImGui::Begin (kMainPanelName, nullptr, mainFlags))
    {
        RenderMenuBar();
    }
    ImGui::End();

    if (show_world_editor)
    {
        RenderWorldEditor (&show_world_editor);
    }
    if (show_anisotropy)
    {
        RenderAnisotropy (&show_anisotropy);
    }
    if (show_gm_commands)
    {
        RenderGMCommands (&show_gm_commands);
    }
    if (show_debug_overlay)
    {
        RenderDebugOverlay (&show_debug_overlay);
    }
    /* - SHADERS ------------------------------------------- */
    if (show_shaders)
    {
        RenderShaders (&show_shaders);
    }
    /* ----------------------------------------------------- */
}

void YosunAdminPanel::RenderMenuBar()
{
    if (!ImGui::BeginMenuBar())
    {
        return;
    }

    if (ImGui::BeginMenu ("Options"))
    {
        ImGui::SeparatorText ("FPS Graphs & Debug");
        ImGui::MenuItem ("Debug Overlay", nullptr, &show_debug_overlay);
        ImGui::MenuItem ("Syserr & Syslog", nullptr);

        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu ("Tools"))
    {
        ImGui::SeparatorText ("Map-Related");
        ImGui::MenuItem ("World Editor", nullptr, &show_world_editor);
        ImGui::SeparatorText ("Experimental Features");
        ImGui::MenuItem ("Anisotropy", nullptr, &show_anisotropy);
        /* - SHADERS ------------------------------------------- */
        ImGui::SeparatorText ("Shaders");
        ImGui::MenuItem ("Shaders", nullptr, &show_shaders);
        /* ----------------------------------------------------- */

        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu ("GM"))
    {
        ImGui::SeparatorText ("Quick Commands");
        ImGui::MenuItem ("GM Commands", nullptr, &show_gm_commands);

        ImGui::EndMenu();
    }

    ImGui::EndMenuBar();
}

void YosunAdminPanel::RenderWorldEditor (bool* p_open) const
{
    constexpr char kWorldEditorTitle[] = "World Editor";
    YosunControlCenter& i = YosunControlCenter::Instance();

    if (ImGuiWindowFlags worldEditorFlags = ImGuiWindowFlags_AlwaysAutoResize;
        ImGui::Begin (kWorldEditorTitle, p_open, worldEditorFlags))
    {
        ImGui::SeparatorText ("SpeedTree");
        {
            ImGui::Text ("Wind Strength");
            ImGui::SliderFloat ("##WindStrengthSlider", &i.fWindStrength, 0.0f, 400.0f);
            ImGui::SameLine();
            ImGui::PushID ("WindStrengthResetButton");
            if (ImGui::Button ("↻"))
            {
                i.fWindStrength = YosunControlCenter::defaultWindStrength;
            }
            ImGui::PopID();
        }

        {
            ImGui::Text ("Wind Oscillation Speed");
            ImGui::SliderFloat ("##WindOscillationSpeedSlider", &i.windOscillationSpeed, 0.0f, 200.0f);
            ImGui::SameLine();
            ImGui::PushID ("WindOscillationSpeedResetButton");
            if (ImGui::Button ("↻"))
            {
                i.windOscillationSpeed = YosunControlCenter::defaultWindOscillationSpeed;
            }
            ImGui::PopID();
        }

        {
            ImGui::Checkbox ("Enable SpeedTree Anisotropy", &YosunControlCenter::speedTreeAnisotropy);
        }
        {
            ImGui::Checkbox ("Enable Interface Anisotropy", &YosunControlCenter::interfaceAnisotropy);
        }
    }
    ImGui::End();
}

void YosunAdminPanel::RenderAnisotropy (bool* p_open) const
{
    constexpr char kAnisotropyTitle[] = "Experimental Anisotropy";

    if (ImGuiWindowFlags AnisotropyFlags = ImGuiWindowFlags_AlwaysAutoResize;
        ImGui::Begin (kAnisotropyTitle, p_open, AnisotropyFlags))
    {
        {
            ImGui::SeparatorText ("Level");

            auto choose_level = [] (const char* label, unsigned char value)
            {
                bool checked = (YosunControlCenter::anisotropyLevel == value);
                if (ImGui::Checkbox (label, &checked) && checked)
                {
                    YosunControlCenter::anisotropyLevel = value;    // exclusive: only sets when turned on
                }
            };

            // Render in one row
            choose_level ("2x", 2);
            ImGui::SameLine();
            choose_level ("4x", 4);
            ImGui::SameLine();
            choose_level ("8x", 8);
            ImGui::SameLine();
            choose_level ("16x", 16);
        }
        ImGui::SeparatorText ("Enable Anisotropy");
        {
            ImGui::Checkbox ("SpeedTree", &YosunControlCenter::speedTreeAnisotropy);
        }
        {
            ImGui::Checkbox ("Interface", &YosunControlCenter::interfaceAnisotropy);
        }
    }
    ImGui::End();
}

void YosunAdminPanel::RenderGMCommands (bool* p_open)
{
    constexpr char kGMCommandsTitle[] = "GM Commands";

    if (ImGuiWindowFlags gmCommandsFlags = ImGuiWindowFlags_AlwaysAutoResize;
        ImGui::Begin (kGMCommandsTitle, p_open, gmCommandsFlags))
    {
        GMCommandsList();

        ImGui::Separator();

        {
            static bool isNightMode = false;

            if (ImGui::Checkbox ("Night Mode", &isNightMode))
            {
                if (isNightMode)
                {
                    CPythonNetworkStream::Instance().SendChatPacket ("/eclipse 1");
                }
                else
                {
                    CPythonNetworkStream::Instance().SendChatPacket ("/eclipse 0");
                }
            }
        }

        ImGui::Separator();

        Warp();

    }
    ImGui::End();
}

void YosunAdminPanel::RenderDebugOverlay (bool* p_open)
{
    auto const& io = ImGui::GetIO();
    ImGuiWindowFlags window_flags =
        ImGuiWindowFlags_NoDecoration       |
        ImGuiWindowFlags_NoDocking          |
        ImGuiWindowFlags_AlwaysAutoResize   |
        ImGuiWindowFlags_NoSavedSettings    |
        ImGuiWindowFlags_NoFocusOnAppearing |
        ImGuiWindowFlags_NoNav;

    if (location >= 0)
    {
        const float PAD = 10.0f;
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImVec2 work_pos = viewport->WorkPos; // Use work area to avoid menu-bar/task-bar, if any!
        ImVec2 work_size = viewport->WorkSize;
        ImVec2 window_pos;
        ImVec2 window_pos_pivot;
        window_pos.x = (location & 1) ? (work_pos.x + work_size.x - PAD) : (work_pos.x + PAD);
        window_pos.y = (location & 2) ? (work_pos.y + work_size.y - PAD) : (work_pos.y + PAD);
        window_pos_pivot.x = (location & 1) ? 1.0f : 0.0f;
        window_pos_pivot.y = (location & 2) ? 1.0f : 0.0f;
        ImGui::SetNextWindowPos (window_pos, ImGuiCond_Always, window_pos_pivot);
        ImGui::SetNextWindowViewport (viewport->ID);
        window_flags |= ImGuiWindowFlags_NoMove;
    }
    else if (location == -2)
    {
        // Center window
        ImGui::SetNextWindowPos (ImGui::GetMainViewport()->GetCenter(), ImGuiCond_Always, ImVec2 (0.5f, 0.5f));
        window_flags |= ImGuiWindowFlags_NoMove;
    }
    ImGui::SetNextWindowBgAlpha (0.35f); // Transparent background
    if (ImGui::Begin ("YosunAdminPanel Debug Overlay", p_open, window_flags))
    {
        ImGui::Text ("Debug Overlay\n(right-click to change position)");
        ImGui::Separator();
        if (ImGui::IsMousePosValid())
        {
            ImGui::Text ("Mouse Position: (%.1f,%.1f)", io.MousePos.x, io.MousePos.y);
        }
        else
        {
            ImGui::Text ("Mouse Position: <invalid>");
        }

        RenderFpsLineGraph();
        DebugOverlayChangePosition (p_open);
    }
    ImGui::End();
}

void YosunAdminPanel::DebugOverlayChangePosition (bool* p_open)
{
    if (ImGui::BeginPopupContextWindow())
    {
        if (ImGui::MenuItem ("Custom", nullptr, location == -1))
        {
            location = -1;
        }
        if (ImGui::MenuItem ("Center", nullptr, location == -2))
        {
            location = -2;
        }
        if (ImGui::MenuItem ("Top-left", nullptr, location == 0))
        {
            location = 0;
        }
        if (ImGui::MenuItem ("Top-right", nullptr, location == 1))
        {
            location = 1;
        }
        if (ImGui::MenuItem ("Bottom-left", nullptr, location == 2))
        {
            location = 2;
        }
        if (ImGui::MenuItem ("Bottom-right", nullptr, location == 3))
        {
            location = 3;
        }
        if (p_open && ImGui::MenuItem ("Close"))
        {
            *p_open = false;
        }
        ImGui::EndPopup();
    }
}

void YosunAdminPanel::RenderFpsLineGraph() const
{
    auto const& io = ImGui::GetIO();

    // -----------------------------
    // --- Persistent Buffers
    // -----------------------------
    static float fpsValue = 0.0f;
    static std::array<float, 100> fpsHistory{};
    static size_t fpsHistoryIndex = 0;

    static float frametimeValue = 0.0f;
    static std::array<float, 100> frametimeHistory{};
    static size_t frametimeHistoryIndex = 0;

    static float ramProcessMB = 0.0f;
    static std::array<float, 100> ramHistory{};
    static size_t ramHistoryIndex = 0;

    // -----------------------------
    // --- Update Timer
    // -----------------------------
    static auto lastUpdate = std::chrono::steady_clock::now();
    constexpr auto updateInterval = std::chrono::duration<float>(1.0f);

    if (auto now = std::chrono::steady_clock::now();
        now - lastUpdate >= updateInterval)
    {
        lastUpdate = now;

        // ================================
        // FPS + Frametime
        // ================================
        fpsValue = io.Framerate;
        frametimeValue = 1000.0f / io.Framerate;

        fpsHistory[fpsHistoryIndex] = fpsValue;
        fpsHistoryIndex = (fpsHistoryIndex + 1) % fpsHistory.size();

        frametimeHistory[frametimeHistoryIndex] = frametimeValue;
        frametimeHistoryIndex = (frametimeHistoryIndex + 1) % frametimeHistory.size();

        // ================================
        // RAM Usage (Process Working Set)
        // ================================
        if (PROCESS_MEMORY_COUNTERS_EX pmc{};
            GetProcessMemoryInfo(GetCurrentProcess(),
                reinterpret_cast<PROCESS_MEMORY_COUNTERS*>(&pmc),
                sizeof(pmc)))
        {
            ramProcessMB = pmc.WorkingSetSize / (1024.0f * 1024.0f);
        }

        ramHistory[ramHistoryIndex] = ramProcessMB;
        ramHistoryIndex = (ramHistoryIndex + 1) % ramHistory.size();
    }

    // -----------------------------
    // --- UI Rendering
    // -----------------------------
    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0, 0, 0, 0.25f));
    ImGui::PushStyleColor(ImGuiCol_PlotLines, ImVec4(1, 1, 1, 0.6f));

    // Frametime Graph
    ImGui::Text("Frametime: %.1f ms", frametimeValue);
    ImGui::PlotLines(
        "##FrameTimeGraph",
        frametimeHistory.data(),
        static_cast<int>(frametimeHistory.size()),
        static_cast<int>(frametimeHistoryIndex),
        nullptr,
        0.0f,
        *std::ranges::max_element(frametimeHistory),
        ImVec2(0, 80)
    );

    // FPS Graph
    ImGui::Text("FPS: %.1f", fpsValue);
    ImGui::PlotLines(
        "##FPSGraph",
        fpsHistory.data(),
        static_cast<int>(fpsHistory.size()),
        static_cast<int>(fpsHistoryIndex),
        nullptr,
        0.0f,
        *std::ranges::max_element(fpsHistory),
        ImVec2(0, 80)
    );

    // RAM History Graph
    ImGui::Text("RAM: %.1f MB", ramProcessMB);
    ImGui::PlotLines(
        "##RAMGraph",
        ramHistory.data(),
        static_cast<int>(ramHistory.size()),
        static_cast<int>(ramHistoryIndex),
        nullptr,
        0.0f,
        *std::ranges::max_element(ramHistory),
        ImVec2(0, 80)
    );

    ImGui::Separator();

    ImGui::PopStyleColor(2);
}

void YosunAdminPanel::GMCommandsList() const
{
    struct Action
    {
        const char* label;
        const char* cmd;
    };
    static constexpr std::array<Action, 4> actions =
    {
        {
            { "Invisibility",          "/invisible" },
            { "Purge inventory",       "/ipurge"    },
            { "Purge nearby entities", "/purge"     },
            { "Weaken nearby monsters", "/weak"      }
        }
    };

    static int action_idx = 0;
    ImGui::Text ("Generic GM Commands");
    if (ImGui::BeginCombo ("##Action", actions[action_idx].label))
    {
        for (int i = 0; i < static_cast<int> (actions.size()); ++i)
        {
            bool is_selected = (action_idx == i);
            if (ImGui::Selectable (actions[i].label, is_selected))
            {
                action_idx = i;
            }
            if (is_selected)
            {
                ImGui::SetItemDefaultFocus();    // scroll to selected on open
            }
        }
        ImGui::EndCombo();
    }

    ImGui::SameLine();
    if (ImGui::Button ("Apply") && (action_idx >= 0 && action_idx < static_cast<int> (actions.size())))
    {
        CPythonNetworkStream::Instance().SendChatPacket (actions[action_idx].cmd);
    }
}

void YosunAdminPanel::LoadAtlasInfo()
{
    m_atlasEntries.clear();

    CMappedFile      kFile;
    LPCVOID          pData;
    if (!CEterPackManager::Instance().Get (kFile, "AtlasInfo.txt", &pData))
    {
        return;    // no atlas data
    }

    CMemoryTextFileLoader loader;
    loader.Bind (kFile.Size(), pData);

    const std::size_t lineCount = loader.GetLineCount();
    m_atlasEntries.reserve (lineCount);

    for (std::size_t i = 0; i < lineCount; ++i)
    {
        // get the full line as a std::string, then view it
        std::string_view sv = loader.GetLineString (i);

        // split out first three columns by '\t'
        auto pos0 = sv.find ('\t');      // end of name
        if (pos0 == std::string_view::npos)
        {
            continue;
        }

        auto pos1 = sv.find ('\t', pos0 + 1); // end of x100
        if (pos1 == std::string_view::npos)
        {
            continue;
        }

        auto pos2 = sv.find ('\t', pos1 + 1); // end of y100
        if (pos2 == std::string_view::npos)
        {
            continue;
        }

        // name field (could be empty, skip if so)
        auto name_sv = sv.substr (0, pos0);
        if (name_sv.empty())
        {
            continue;
        }

        // numeric fields as views
        auto x_sv = sv.substr (pos0 + 1, pos1 - pos0 - 1);
        auto y_sv = sv.substr (pos1 + 1, pos2 - pos1 - 1);

        int x100{};
        int y100{};
        // parse without allocations
        if (auto[ptr, ec] = std::from_chars (x_sv.data(), x_sv.data() + x_sv.size(), x100); ec != std::errc{})
            continue;
        if (auto[ptr, ec] = std::from_chars (y_sv.data(), y_sv.data() + y_sv.size(), y100); ec != std::errc{})
            continue;

        // store a real string for the name
        m_atlasEntries.emplace_back (std::string{ name_sv }, x100, y100);
    }
}

void YosunAdminPanel::Warp()
{
    ImGui::TextUnformatted ("Warp to Map");

    if (m_atlasEntries.empty())
    {
        ImGui::TextUnformatted ("No map data loaded.");
        return;
    }

    // build C‐string list
    std::vector<const char*> names;
    names.reserve (m_atlasEntries.size());
    for (auto const& e : m_atlasEntries)
    {
        names.push_back (e.name.c_str());
    }

    ImGui::Combo ("##Warp", (&m_warpIdx), names.data(), static_cast<int> (names.size()));
    ImGui::SameLine();
    if (ImGui::Button ("Warp"))
    {
        const auto& e = m_atlasEntries[m_warpIdx];
        int realX = e.x / 100;
        int realY = e.y / 100;

        // build and send
        auto cmd = std::format ("/warp {} {}", realX, realY);
        CPythonNetworkStream::Instance().SendChatPacket (cmd.c_str());
    }
}

/* - SHADERS ------------------------------------------- */
static void RenderShaderToggle (const char* label, bool& flag, IShader::EType type)
{
    if (ImGui::Checkbox (label, &flag))
    {
        if (auto* shader = CShaderManager::Instance().GetShader (type))
        {
            if (flag)
            {
                shader->Show();
            }
            else
            {
                shader->Hide();
            }
        }
    }
}

void YosunAdminPanel::RenderShaders (bool* p_open) const
{
    constexpr char kShaderTitle[] = "Shaders";

    if (ImGuiWindowFlags shaderFlags = ImGuiWindowFlags_AlwaysAutoResize;
        ImGui::Begin (kShaderTitle, p_open, shaderFlags))
    {
        using enum IShader::EType;
        ImGui::SeparatorText ("Shaders");

        RenderShaderToggle ("Wave Screen",       YosunControlCenter::waveShader,             WAVE);
        RenderShaderToggle ("Greyscale",         YosunControlCenter::greyscaleShader,        GRAY);
        RenderShaderToggle ("Pixelate",          YosunControlCenter::pixelateShader,         PIXELATE);
        RenderShaderToggle ("Invert Colors",     YosunControlCenter::invertColorsShader,     INVERT);
        RenderShaderToggle ("Atlas Spotlight",   YosunControlCenter::atlasSpotlightShader,   ATLAS_SPOTLIGHT);
        RenderShaderToggle ("Ui Blur",           YosunControlCenter::uiBlurShader,           UI_BLUR);
        RenderShaderToggle ("Water Shader",      YosunControlCenter::waterShader,            WATER);
    }

    ImGui::End();
}
/* ----------------------------------------------------- */

#endif /* _DEBUG */
