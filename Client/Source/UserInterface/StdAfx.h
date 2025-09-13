#pragma once

#pragma warning(disable:4702)
#pragma warning(disable:4100)
#pragma warning(disable:4201)
#pragma warning(disable:4511)
#pragma warning(disable:4663)
#pragma warning(disable:4018)
#pragma warning(disable:4245)
#pragma warning(disable:4995)

#include "../EterLib/StdAfx.h"
#include "../EterPythonLib/StdAfx.h"
#include "../GameLib/StdAfx.h"
#include "../ScriptLib/StdAfx.h"
#include "../MilesLib/StdAfx.h"
#include "../EffectLib/StdAfx.h"
#include "../TerrainLib/StdAfx.h"
#include "../SpeedTreeLib/StdAfx.h"

#ifndef __D3DRM_H__
    #define __D3DRM_H__
#endif

#include <dshow.h>
#include <DirectX9/qedit.h>

#include "Locale.h"

#include "GameType.h"
extern DWORD __DEFAULT_CODE_PAGE__;

#define APP_NAME    "Pureline By Kaptan Yosun @ MMOTutkunlari.com"

enum
{
    POINT_MAX_NUM = 255,
    CHARACTER_NAME_MAX_LEN = 24,
    PLAYER_NAME_MAX_LEN = 12,
};

void initudp();
void initapp();
void initime();
void initsystem();
void initchr();
void initchrmgr();
void initChat();
void initTextTail();
void initime();
void initItem();
void initNonPlayer();
void initnet();
void initPlayer();
void initSectionDisplayer();
void initServerStateChecker();

/* - SHADERS ------------------------------------------- */
void initshadermgr();
/* ----------------------------------------------------- */

void initTrade();
void initMiniMap();
void initProfiler();
void initEvent();
void initeffect();
void initsnd();
void initeventmgr();
void initBackground();
void initwndMgr();
void initshop();
void initpack();
void initskill();
void initfly();
void initquest();
void initsafebox();
void initguild();
void initMessenger();

extern const std::string& ApplicationStringTable_GetString(DWORD dwID);
extern const std::string& ApplicationStringTable_GetString(DWORD dwID, LPCSTR szKey);

extern const char* ApplicationStringTable_GetStringz(DWORD dwID);
extern const char* ApplicationStringTable_GetStringz(DWORD dwID, LPCSTR szKey);

extern void ApplicationSetErrorString(const char* szErrorString);
