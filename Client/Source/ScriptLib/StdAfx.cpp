// stdafx.cpp : source file that includes just the standard includes
//  scriptLib.pch will be the pre-compiled header
//  stdafx.obj will contain the pre-compiled type information

#include "StdAfx.h"

void SetExceptionSender(IPythonExceptionSender * pkExceptionSender)
{
    g_pkExceptionSender = pkExceptionSender;
}
