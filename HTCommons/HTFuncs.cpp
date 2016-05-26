#include "stdafxCommons.h"
#include "HTFuncs.h"

namespace HTFuncs {
	size_t getFileName(_In_ TCHAR CONST * CONST src, _Out_ TCHAR * CONST dest) {
		int j = 0;
		for (int i = 0; src[i]; i++) {
			if (src[i] != '\\') {
				dest[j++] = src[i];
			}
			else {
				j = 0;
			}
		}
		dest[j] = 0;
		return j;
	}

	VOID goUpPath(_Inout_ TCHAR * CONST src) {
		size_t len = 0;
		HRESULT hr = ::StringCchLength(src, _1K, &len);
		if (FAILED(hr)) {
			THROW_API("StringCchLength", hr, "");
		}
		for (int i = len; i >= 0; i--) {
			if (src[i] == _T('\\')) {
				return;
			}
			else {
				src[i] = 0;
			}
		}
	}

	VOID appendSlash(_Inout_ TCHAR * CONST src) {
		size_t len = 0;
		HRESULT hr = ::StringCchLength(src, _1K, &len);
		if (FAILED(hr)) {
			THROW_API("StringCchLength", hr, "");
		}
		if (src[len - 1] != _T('\\')) {
			src[len] = _T('\\');
			src[len + 1] = _T('\0');
		}
	}

	VOID keyCode2TCHAR(_In_ UINT code, _Out_ TCHAR * CONST dest) {

	}

	UINT TCHAR2keycode(_In_ TCHAR CONST * CONST src) {
		return 0;
	}
}