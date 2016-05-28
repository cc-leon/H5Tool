#pragma once

#define _WIN32_WINNT _WIN32_WINNT_WINXP

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS
#define _AFX_ALL_WARNINGS
#define NO_WARN_MBCS_MFC_DEPRECATION

#define VALID_HANDLE(handle) ((handle==INVALID_HANDLE_VALUE||handle==NULL) ? FALSE : TRUE)
#define VALID_POINTER(pointer) ((pointer==nullptr||pointer==NULL) ? FALSE : TRUE)
#define ALLOC(datatype,size) reinterpret_cast<datatype *>(::HeapAlloc(::GetProcessHeap(),NULL,static_cast<SIZE_T>((size)*sizeof(datatype))))
#define FREE(ptr) ::HeapFree(::GetProcessHeap(),NULL,ptr)


#include <afxwin.h>
#include <afxext.h>
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT
#include <tchar.h>
#include <strsafe.h>

#include "HTException.h"
#include "../HTCommons/FileVersion.h"
#include "../HTCommons/HTHotkeyInfo.h"
#include "../HTCommons/HTFileNames.h"