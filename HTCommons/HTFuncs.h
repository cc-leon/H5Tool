#pragma once

#define VALID_HANDLE(handle) ((handle==INVALID_HANDLE_VALUE||handle==NULL) ? FALSE : TRUE)
#define VALID_POINTER(pointer) ((pointer==nullptr||pointer==NULL) ? FALSE : TRUE)
#define ALLOC(datatype,size) reinterpret_cast<datatype *>(::HeapAlloc(::GetProcessHeap(),NULL,static_cast<SIZE_T>((size)*sizeof(datatype))))
#define FREE(ptr) ::HeapFree(::GetProcessHeap(),NULL,ptr)

namespace HTFuncs {
	size_t getFileName(_In_ TCHAR CONST * CONST src, _Out_ TCHAR * CONST dest);
	VOID goUpPath(_Inout_ TCHAR * CONST src);
	VOID appendSlash(_Inout_ TCHAR * CONST src);
	VOID keyCode2TCHAR(_In_ UINT code, _Out_ TCHAR * CONST dest);
	UINT TCHAR2keycode(_In_ TCHAR CONST * CONST src);
}
