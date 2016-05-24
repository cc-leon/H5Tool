#pragma once

#define VALID_HANDLE(handle) ((handle==INVALID_HANDLE_VALUE||handle==NULL) ? FALSE : TRUE)
#define VALID_POINTER(pointer) ((pointer==nullptr||pointer==NULL) ? FALSE : TRUE)

namespace HTFuncs {
	size_t getFileName(_In_ TCHAR CONST * CONST src, _Out_ TCHAR * CONST dest);
}
