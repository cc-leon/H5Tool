#pragma once

#include "HTHotkeyInfo.h"

#define VALID_HANDLE(handle) ((handle==INVALID_HANDLE_VALUE||handle==NULL) ? FALSE : TRUE)
#define VALID_POINTER(pointer) ((pointer==nullptr||pointer==NULL) ? FALSE : TRUE)
#define ALLOC(datatype,size) reinterpret_cast<datatype *>(::HeapAlloc(::GetProcessHeap(),NULL,static_cast<SIZE_T>((size)*sizeof(datatype))))
#define FREE(ptr) ::HeapFree(::GetProcessHeap(),NULL,ptr)

namespace HTFuncs {
	size_t getFileName(_In_ TCHAR CONST * CONST src, _Out_ TCHAR * CONST dest);
	VOID goUpPath(_Inout_ TCHAR * CONST src);
	VOID appendSlash(_Inout_ TCHAR * CONST src);
	TCHAR keyCode2TCHAR(_In_ UINT CONST code);
	UINT TCHAR2keycode(_In_ TCHAR CONST src);
	VOID char2TCHAR(_In_ CHAR CONST * CONST src, _Out_ TCHAR * CONST dest);
	VOID getFullPath(_In_ TCHAR CONST * CONST filename, _Out_ TCHAR * CONST dest, _In_ size_t CONST maxLen);
	VOID getFileVersion(_In_ TCHAR CONST * CONST fullName, _Out_ DWORD& hVer, _Out_ DWORD& lVer);
	VOID getKeyString(_In_ HTHotkeyInfo CONST& keyInfo, _Out_ TCHAR * CONST dest);
	HANDLE runEXE(_In_ TCHAR CONST * CONST fullName, _In_ TCHAR * CONST param = NULL, _Out_opt_ DWORD * CONST procID = NULL);
	DWORD seekEXE(_In_ TCHAR CONST * CONST procName,_Out_ HANDLE& procHandle);
}
