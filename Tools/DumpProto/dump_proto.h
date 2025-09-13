#pragma once

//#include "../../libthecore/include/stdafx.h"
//#include ""
//#define __WIN32__
#include <stdio.h>
#include <string>
#include <map>
#include <set>
#include <algorithm>

#include "lzo.h"

//윈도우exe파일 만들면서 새로 추가 : 파일 읽어올 수 있도록 하였다.
#include "CsvFile.h"
#include "ItemCSVReader.h"

#ifdef _DEBUG
    #pragma comment(lib, "lzo2_debug.lib")
#else
    #pragma comment(lib, "lzo2.lib")
#endif