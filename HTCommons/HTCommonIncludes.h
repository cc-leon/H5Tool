#pragma once

#define _WIN32_WINNT _WIN32_WINNT_WINXP

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS
#define _AFX_ALL_WARNINGS
#define NO_WARN_MBCS_MFC_DEPRECATION

#include <afxwin.h>
#include <afxext.h>
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT
#include <tchar.h>
#include <strsafe.h>
#include <Psapi.h>

#pragma comment(lib, "Psapi.lib")
#pragma comment(lib, "version.lib")

#include "../HTCommons/HTFileNames.h"
#include "../HTCommons/HTEnumBase.h"
#include "../HTCommons/HTFuncs.h"
#include "../HTCommons/HTException.h"
#include "../HTCommons/HTConstants.h"
