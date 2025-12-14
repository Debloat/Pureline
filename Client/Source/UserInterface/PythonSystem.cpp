#include "StdAfx.h"
#include "PythonSystem.h"
#include "PythonApplication.h"

void CPythonSystem::SetInterfaceHandler(PyObject * poHandler)
{
    // NOTE : 레퍼런스 카운트는 바꾸지 않는다. 레퍼런스가 남아 있어 Python에서 완전히 지워지지 않기 때문.
    //        대신에 __del__때 Destroy를 호출해 Handler를 NULL로 셋팅한다. - [levites]
    //  if (m_poInterfaceHandler)
    //      Py_DECREF(m_poInterfaceHandler);

    m_poInterfaceHandler = poHandler;

    //  if (m_poInterfaceHandler)
    //      Py_INCREF(m_poInterfaceHandler);
}

void CPythonSystem::DestroyInterfaceHandler()
{
    m_poInterfaceHandler = nullptr;
}

void CPythonSystem::SaveWindowStatus(int iIndex, int iVisible, int iMinimized, int ix, int iy, int iHeight)
{
    m_WindowStatus[iIndex].isVisible    = iVisible;
    m_WindowStatus[iIndex].isMinimized  = iMinimized;
    m_WindowStatus[iIndex].ixPosition   = ix;
    m_WindowStatus[iIndex].iyPosition   = iy;
    m_WindowStatus[iIndex].iHeight      = iHeight;
}

void CPythonSystem::GetDisplaySettings()
{
    memset(m_ResolutionList, 0, sizeof(TResolution) * RESOLUTION_MAX_NUM);
    m_ResolutionCount = 0;

    LPDIRECT3D9EX lpD3D = CPythonGraphic::Instance().GetD3D();

    D3DADAPTER_IDENTIFIER9 d3dAdapterIdentifier;
    D3DDISPLAYMODEEX d3ddmDesktop = {};
    d3ddmDesktop.Size = sizeof(D3DDISPLAYMODEEX);

    lpD3D->GetAdapterIdentifier(D3DADAPTER_DEFAULT, D3DENUM_WHQL_LEVEL, &d3dAdapterIdentifier);
    lpD3D->GetAdapterDisplayModeEx(D3DADAPTER_DEFAULT, &d3ddmDesktop, nullptr);

    // 이 어뎁터가 가지고 있는 디스플래이 모드갯수를 나열한다..
    D3DDISPLAYMODEFILTER filter = {};
    filter.Size = sizeof(D3DDISPLAYMODEFILTER);
    filter.Format = d3ddmDesktop.Format;

    DWORD dwNumAdapterModes = lpD3D->GetAdapterModeCountEx(D3DADAPTER_DEFAULT, &filter);


    for (UINT iMode = 0; iMode < dwNumAdapterModes; iMode++)
    {
        D3DDISPLAYMODEFILTER filter = {};
        filter.Size = sizeof(D3DDISPLAYMODEFILTER);
        filter.Format = d3ddmDesktop.Format;

        D3DDISPLAYMODEEX DisplayMode = {};
        DisplayMode.Size = sizeof(D3DDISPLAYMODEEX);

        lpD3D->EnumAdapterModesEx(D3DADAPTER_DEFAULT, &filter, iMode, &DisplayMode);

        // 800 600 이상만 걸러낸다.
        if (DisplayMode.Width < 800 || DisplayMode.Height < 600)
        {
            continue;
        }

        if (DisplayMode.Format != D3DFMT_X8R8G8B8 && DisplayMode.Format != D3DFMT_A8R8G8B8)
        {
            continue;
        }

        int check_res = false;

        for (int i = 0; !check_res && i < m_ResolutionCount; ++i)
        {
            if (m_ResolutionList[i].width != DisplayMode.Width || m_ResolutionList[i].height != DisplayMode.Height)
            {
                continue;
            }

            int check_fre = false;

            // 프리퀀시만 다르므로 프리퀀시만 셋팅해준다.
            for (int j = 0; j < m_ResolutionList[i].frequency_count; ++j)
            {
                if (m_ResolutionList[i].frequency[j] == DisplayMode.RefreshRate)
                {
                    check_fre = true;
                    break;
                }
            }

            if (!check_fre)
                if (m_ResolutionList[i].frequency_count < FREQUENCY_MAX_NUM)
                {
                    m_ResolutionList[i].frequency[m_ResolutionList[i].frequency_count++] = DisplayMode.RefreshRate;
                }

            check_res = true;
        }

        if (!check_res)
        {
            // 새로운 거니까 추가해주자.
            if (m_ResolutionCount < RESOLUTION_MAX_NUM)
            {
                m_ResolutionList[m_ResolutionCount].width           = DisplayMode.Width;
                m_ResolutionList[m_ResolutionCount].height          = DisplayMode.Height;
                m_ResolutionList[m_ResolutionCount].frequency[0]    = DisplayMode.RefreshRate;
                m_ResolutionList[m_ResolutionCount].frequency_count = 1;

                ++m_ResolutionCount;
            }
        }
    }
}

int CPythonSystem::GetResolutionCount() const
{
    return m_ResolutionCount;
}

int CPythonSystem::GetFrequencyCount(int index) const
{
    if (index >= m_ResolutionCount)
    {
        return 0;
    }

    return m_ResolutionList[index].frequency_count;
}

bool CPythonSystem::GetResolution(int index, OUT DWORD *width, OUT DWORD *height) const
{
    if (index >= m_ResolutionCount)
    {
        return false;
    }

    *width = m_ResolutionList[index].width;
    *height = m_ResolutionList[index].height;
    return true;
}

bool CPythonSystem::GetFrequency(int index, int freq_index, OUT DWORD *frequncy) const
{
    if (index >= m_ResolutionCount)
    {
        return false;
    }

    if (freq_index >= m_ResolutionList[index].frequency_count)
    {
        return false;
    }

    *frequncy = m_ResolutionList[index].frequency[freq_index];
    return true;
}

int CPythonSystem::GetResolutionIndex(DWORD width, DWORD height) const
{
    DWORD re_width;
    DWORD re_height;
    int i = 0;

    while (GetResolution(i, &re_width, &re_height))
    {
        if (re_width == width)
            if (re_height == height)
            {
                return i;
            }
        i++;
    }

    return 0;
}

int CPythonSystem::GetFrequencyIndex(int res_index, DWORD frequency) const
{
    DWORD re_frequency;
    int i = 0;

    while (GetFrequency(res_index, i, &re_frequency))
    {
        if (re_frequency == frequency)
        {
            return i;
        }

        i++;
    }

    return 0;
}

DWORD CPythonSystem::GetWidth() const
{
    return m_Config.width;
}

DWORD CPythonSystem::GetHeight() const
{
    return m_Config.height;
}
DWORD CPythonSystem::GetFrequency() const
{
    return m_Config.frequency;
}

bool CPythonSystem::IsNoSoundCard() const
{
    return m_Config.bNoSoundCard;
}

bool CPythonSystem::IsSoftwareCursor() const
{
    return m_Config.is_software_cursor;
}

float CPythonSystem::GetMusicVolume() const
{
    return m_Config.music_volume;
}

int CPythonSystem::GetSoundVolume() const
{
    return m_Config.voice_volume;
}

void CPythonSystem::SetMusicVolume(float fVolume)
{
    m_Config.music_volume = fVolume;
}

void CPythonSystem::SetSoundVolumef(float fVolume)
{
    m_Config.voice_volume = int (5 * fVolume);
}

int CPythonSystem::GetDistance() const
{
    return m_Config.iDistance;
}

int CPythonSystem::GetShadowLevel() const
{
    return m_Config.iShadowLevel;
}

void CPythonSystem::SetShadowLevel(unsigned int level)
{
    m_Config.iShadowLevel = MIN(level, 5);
    CPythonBackground::instance().RefreshShadowLevel();
}

int CPythonSystem::IsSaveID() const
{
    return m_Config.isSaveID;
}

const char* CPythonSystem::GetSaveID()
{
    return m_Config.SaveID;
}

bool CPythonSystem::isViewCulling() const
{
    return m_Config.is_object_culling;
}

void CPythonSystem::SetSaveID(int iValue, const char* c_szSaveID)
{
    if (iValue != 1)
    {
        return;
    }

    m_Config.isSaveID = iValue;
    strncpy(m_Config.SaveID, c_szSaveID, sizeof(m_Config.SaveID) - 1);
}

CPythonSystem::TConfig* CPythonSystem::GetConfig()
{
    return &m_Config;
}

void CPythonSystem::SetConfig(TConfig * pNewConfig)
{
    m_Config = *pNewConfig;
}

void CPythonSystem::SetDefaultConfig()
{
    memset(&m_Config, 0, sizeof(m_Config));

    m_Config.width              = 1280;
    m_Config.height             = 720;
    m_Config.bWindowed          = true;

    m_Config.is_software_cursor = false;
    m_Config.is_object_culling  = true;
    m_Config.iDistance          = 3;

    m_Config.gamma              = 3;
    m_Config.music_volume       = 0.0f;
    m_Config.voice_volume       = 3;

    m_Config.bDecompressDDS     = 0;
    m_Config.iShadowLevel       = 5;
    m_Config.bViewChat          = true;
    m_Config.bAlwaysShowName    = true;
    m_Config.bShowDamage        = true;
    m_Config.bShowSalesText     = true;

    /* - SAVE_CAMERA_MODE ---------------------------------- */
    m_Config.bCameraMode        = 0;
    /* ----------------------------------------------------- */
}

bool CPythonSystem::IsWindowed() const
{
    return m_Config.bWindowed;
}

bool CPythonSystem::IsViewChat() const
{
    return m_Config.bViewChat;
}

void CPythonSystem::SetViewChatFlag(int iFlag)
{
    m_Config.bViewChat = iFlag == 1 ? true : false;
}

bool CPythonSystem::IsAlwaysShowName() const
{
    return m_Config.bAlwaysShowName;
}

void CPythonSystem::SetAlwaysShowNameFlag(int iFlag)
{
    m_Config.bAlwaysShowName = iFlag == 1 ? true : false;
}

bool CPythonSystem::IsShowDamage() const
{
    return m_Config.bShowDamage;
}

void CPythonSystem::SetShowDamageFlag(int iFlag)
{
    m_Config.bShowDamage = iFlag == 1 ? true : false;
}

bool CPythonSystem::IsShowSalesText() const
{
    return m_Config.bShowSalesText;
}

void CPythonSystem::SetShowSalesTextFlag(int iFlag)
{
    m_Config.bShowSalesText = iFlag == 1 ? true : false;
}

bool CPythonSystem::IsUseDefaultIME() const
{
    return m_Config.bUseDefaultIME;
}

/* - SAVE_CAMERA_MODE ---------------------------------- */
void CPythonSystem::SetCameraMode(BYTE bMode)
{
    m_Config.bCameraMode = bMode;
}

BYTE CPythonSystem::GetCameraMode() const
{
    return m_Config.bCameraMode;
}
/* ----------------------------------------------------- */

bool CPythonSystem::LoadConfig()
{
    FILE * fp = nullptr;

    if (nullptr == (fp = fopen("metin2.cfg", "rt")))
    {
        return false;
    }

    char buf[256];
    char command[256];
    char value[256];

    while (fgets(buf, 256, fp))
    {
        if (sscanf(buf, " %s %s\n", command, value) == EOF)
        {
            break;
        }

        if (!stricmp(command, "WIDTH"))
        {
            m_Config.width      = atoi(value);
        }
        else if (!stricmp(command, "HEIGHT"))
        {
            m_Config.height = atoi(value);
        }
        else if (!stricmp(command, "FREQUENCY"))
        {
            m_Config.frequency = atoi(value);
        }
        else if (!stricmp(command, "SOFTWARE_CURSOR"))
        {
            m_Config.is_software_cursor = atoi(value) ? true : false;
        }
        else if (!stricmp(command, "OBJECT_CULLING"))
        {
            m_Config.is_object_culling = atoi(value) ? true : false;
        }
        else if (!stricmp(command, "VISIBILITY"))
        {
            m_Config.iDistance = atoi(value);
        }
        else if (!stricmp(command, "MUSIC_VOLUME"))
        {
            if (strchr(value, '.') == 0)  // Old compatiability
            {
                m_Config.music_volume = pow(10.0f, (-1.0f + (((float) atoi(value)) / 5.0f)));
                if (atoi(value) == 0)
                {
                    m_Config.music_volume = 0.0f;
                }
            }
            else
            {
                m_Config.music_volume = atof(value);
            }
        }
        else if (!stricmp(command, "VOICE_VOLUME"))
        {
            m_Config.voice_volume = (char) atoi(value);
        }
        else if (!stricmp(command, "GAMMA"))
        {
            m_Config.gamma = atoi(value);
        }
        else if (!stricmp(command, "IS_SAVE_ID"))
        {
            m_Config.isSaveID = atoi(value);
        }
        else if (!stricmp(command, "SAVE_ID"))
        {
            strncpy(m_Config.SaveID, value, 20);
        }
        else if (!stricmp(command, "PRE_LOADING_DELAY_TIME"))
        {
            g_iLoadingDelayTime = atoi(value);
        }
        else if (!stricmp(command, "WINDOWED"))
        {
            m_Config.bWindowed = atoi(value) == 1 ? true : false;
        }
        else if (!stricmp(command, "USE_DEFAULT_IME"))
        {
            m_Config.bUseDefaultIME = atoi(value) == 1 ? true : false;
        }
        else if (!stricmp(command, "SHADOW_LEVEL"))
        {
            m_Config.iShadowLevel = atoi(value);
        }
        else if (!stricmp(command, "DECOMPRESSED_TEXTURE"))
        {
            m_Config.bDecompressDDS = atoi(value) == 1 ? true : false;
        }
        else if (!stricmp(command, "NO_SOUND_CARD"))
        {
            m_Config.bNoSoundCard = atoi(value) == 1 ? true : false;
        }
        else if (!stricmp(command, "VIEW_CHAT"))
        {
            m_Config.bViewChat = atoi(value) == 1 ? true : false;
        }
        else if (!stricmp(command, "ALWAYS_VIEW_NAME"))
        {
            m_Config.bAlwaysShowName = atoi(value) == 1 ? true : false;
        }
        else if (!stricmp(command, "SHOW_DAMAGE"))
        {
            m_Config.bShowDamage = atoi(value) == 1 ? true : false;
        }
        else if (!stricmp(command, "SHOW_SALESTEXT"))
        {
            m_Config.bShowSalesText = atoi(value) == 1 ? true : false;
        }

        /* - SAVE_CAMERA_MODE ---------------------------------- */
        else if (!stricmp(command, "CAMERA_MODE"))
        {
            m_Config.bCameraMode = atoi(value);
        }
        /* ----------------------------------------------------- */
    }

    if (m_Config.bWindowed)
    {
        unsigned screen_width = GetSystemMetrics(SM_CXFULLSCREEN);
        unsigned screen_height = GetSystemMetrics(SM_CYFULLSCREEN);

        if (m_Config.width >= screen_width)
        {
            m_Config.width = screen_width;
        }
        if (m_Config.height >= screen_height)
        {
            m_Config.height = screen_height;
        }
    }

    m_OldConfig = m_Config;

    fclose(fp);

    //  Tracef("LoadConfig: Resolution: %dx%d %dHZ Software Cursor: %d, Music/Voice Volume: %d/%d Gamma: %d\n",
    //      m_Config.width,
    //      m_Config.height,
    //      m_Config.frequency,
    //      m_Config.is_software_cursor,
    //      m_Config.music_volume,
    //      m_Config.voice_volume,
    //      m_Config.gamma);

    return true;
}

bool CPythonSystem::SaveConfig()
{
    FILE *fp;

    if (nullptr == (fp = fopen("metin2.cfg", "wt")))
    {
        return false;
    }

    fprintf(fp, "WIDTH\t\t\t\t\t%d\n", m_Config.width);
    fprintf(fp, "HEIGHT\t\t\t\t\t%d\n", m_Config.height);
    fprintf(fp, "FREQUENCY\t\t\t\t%d\n", m_Config.frequency);
    fprintf(fp, "SOFTWARE_CURSOR\t\t\t%d\n", m_Config.is_software_cursor);
    fprintf(fp, "OBJECT_CULLING\t\t\t%d\n", m_Config.is_object_culling);
    fprintf(fp, "VISIBILITY\t\t\t\t%d\n", m_Config.iDistance);
    fprintf(fp, "MUSIC_VOLUME\t\t\t%.3f\n", m_Config.music_volume);
    fprintf(fp, "VOICE_VOLUME\t\t\t%d\n", m_Config.voice_volume);
    fprintf(fp, "GAMMA\t\t\t\t\t%d\n", m_Config.gamma);
    fprintf(fp, "IS_SAVE_ID\t\t\t\t%d\n", m_Config.isSaveID);
    fprintf(fp, "SAVE_ID\t\t\t\t\t%s\n", m_Config.SaveID);
    fprintf(fp, "PRE_LOADING_DELAY_TIME\t%d\n", g_iLoadingDelayTime);
    fprintf(fp, "DECOMPRESSED_TEXTURE\t%d\n", m_Config.bDecompressDDS);
    fprintf(fp, "WINDOWED\t\t\t\t%d\n", m_Config.bWindowed);
    fprintf(fp, "VIEW_CHAT\t\t\t\t%d\n", m_Config.bViewChat);
    fprintf(fp, "ALWAYS_VIEW_NAME\t\t%d\n", m_Config.bAlwaysShowName);
    fprintf(fp, "SHOW_DAMAGE\t\t\t\t%d\n", m_Config.bShowDamage);
    fprintf(fp, "SHOW_SALESTEXT\t\t\t%d\n", m_Config.bShowSalesText);
    fprintf(fp, "USE_DEFAULT_IME\t\t\t%d\n", m_Config.bUseDefaultIME);
    fprintf(fp, "SHADOW_LEVEL\t\t\t%d\n", m_Config.iShadowLevel);

    /* - SAVE_CAMERA_MODE ---------------------------------- */
    fprintf(fp, "CAMERA_MODE\t\t\t\t%d\n", m_Config.bCameraMode);
    /* ----------------------------------------------------- */

    fprintf(fp, "\n");

    fclose(fp);
    return true;
}

bool CPythonSystem::LoadInterfaceStatus()
{
    FILE * File;
    File = fopen("interface.cfg", "rb");

    if (!File)
    {
        return false;
    }

    fread(m_WindowStatus, 1, sizeof(TWindowStatus) * WINDOW_MAX_NUM, File);
    fclose(File);
    return true;
}

void CPythonSystem::SaveInterfaceStatus()
{
    if (!m_poInterfaceHandler)
    {
        return;
    }

    PyCallClassMemberFunc(m_poInterfaceHandler, "OnSaveInterfaceStatus", Py_BuildValue("()"));

    FILE * File;

    File = fopen("interface.cfg", "wb");

    if (!File)
    {
        TraceError("Cannot open interface.cfg");
        return;
    }

    fwrite(m_WindowStatus, 1, sizeof(TWindowStatus) * WINDOW_MAX_NUM, File);
    fclose(File);
}

bool CPythonSystem::isInterfaceConfig() const
{
    return m_isInterfaceConfig;
}

const CPythonSystem::TWindowStatus& CPythonSystem::GetWindowStatusReference(int iIndex)
{
    return m_WindowStatus[iIndex];
}

void CPythonSystem::ApplyConfig() // 이전 설정과 현재 설정을 비교해서 바뀐 설정을 적용 한다.
{
    if (m_OldConfig.gamma != m_Config.gamma)
    {
        float val = 1.0f;

        switch (m_Config.gamma)
        {
            case 0:
                val = 0.4f;
                break;
            case 1:
                val = 0.7f;
                break;
            case 2:
                val = 1.0f;
                break;
            case 3:
                val = 1.2f;
                break;
            case 4:
                val = 1.4f;
                break;
        }

        CPythonGraphic::Instance().SetGamma(val);
    }

    if (m_OldConfig.is_software_cursor != m_Config.is_software_cursor)
    {
        if (m_Config.is_software_cursor)
        {
            CPythonApplication::Instance().SetCursorMode(CPythonApplication::CURSOR_MODE_SOFTWARE);
        }
        else
        {
            CPythonApplication::Instance().SetCursorMode(CPythonApplication::CURSOR_MODE_HARDWARE);
        }
    }

    m_OldConfig = m_Config;

    ChangeSystem();
}

void CPythonSystem::ChangeSystem()
{
    // Shadow
    /*
    if (m_Config.is_shadow)
        CScreen::SetShadowFlag(true);
    else
        CScreen::SetShadowFlag(false);
    */
    CSoundManager& rkSndMgr = CSoundManager::Instance();
    /*
    float fMusicVolume;
    if (0 == m_Config.music_volume)
        fMusicVolume = 0.0f;
    else
        fMusicVolume= (float)pow(10.0f, (-1.0f + (float)m_Config.music_volume / 5.0f));
        */
    rkSndMgr.SetMusicVolume(m_Config.music_volume);

    /*
    float fVoiceVolume;
    if (0 == m_Config.voice_volume)
        fVoiceVolume = 0.0f;
    else
        fVoiceVolume = (float)pow(10.0f, (-1.0f + (float)m_Config.voice_volume / 5.0f));
    */
    rkSndMgr.SetSoundVolumeGrade(m_Config.voice_volume);
}

void CPythonSystem::Clear()
{
    SetInterfaceHandler(nullptr);
}

CPythonSystem::CPythonSystem()
{
    memset(&m_Config, 0, sizeof(TConfig));

    m_poInterfaceHandler = nullptr;

    SetDefaultConfig();

    LoadConfig();

    ChangeSystem();

    if (LoadInterfaceStatus())
    {
        m_isInterfaceConfig = true;
    }
    else
    {
        m_isInterfaceConfig = false;
    }
}

CPythonSystem::~CPythonSystem()
{
    assert(m_poInterfaceHandler == NULL && "CPythonSystem MUST CLEAR!");
}
