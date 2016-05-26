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

	TCHAR keyCode2TCHAR(_In_ UINT CONST code) {
		if (code >= 0x30 && code <= 0x39) {
			return (_T('0') + code - 0x30);
		}
		else if (code >= 0x41 && code <= 0x5A) {
			return (_T('A') + code - 0x41);
		}
		else {
			return NULL;
		}
	}

	UINT TCHAR2keycode(_In_ TCHAR CONST src) {
		if (src >= _T('0') && src <= _T('9')) {
			return (src - _T('0') + 0x30);
		}
		else if (src >= _T('a') && src <= _T('z')) {
			return (src - _T('a') + 0x41);
		}
		else if (src >= _T('A') && src <= _T('Z')) {
			return (src - _T('A') + 0x41);
		}
		else {
			return NULL;
		}
	}

	VOID char2TCHAR(_In_ CHAR CONST * CONST src, _Out_ TCHAR * CONST dest) {
		int i = 0;
		while ((dest[i++] = src[i]) != 0);
	}

	VOID getFullPath(_In_ TCHAR CONST * CONST filename, _Out_ TCHAR * CONST dest, _In_ size_t CONST maxLen) {
		HRESULT hr = S_OK;
		if(::GetCurrentDirectory(maxLen, dest) == 0 ) {
			THROW_API("GetCurrentDirectory", 0, "");
		}
		appendSlash(dest);
		hr = ::StringCchCat(dest, maxLen, filename);
		if (FAILED(hr)) {
			THROW_API("StringCchCat", hr, "");
		}
	}

	VOID getFileVersion(_In_ TCHAR CONST * CONST fullName, _Out_ DWORD& hVer, _Out_ DWORD& lVer) {
		DWORD handle = NULL;
		DWORD infoSize = GetFileVersionInfoSize(fullName, &handle);
		if (infoSize == 0) {
			THROW_API("GetFileVersionInfoSize", 0, "");
		}
		LPVOID pBlock;
		pBlock = ALLOC(BYTE, infoSize);

		if (GetFileVersionInfo(fullName, handle, infoSize, pBlock) == 0) {
			THROW_API("GetFileVersionInfo", 0, "");
		}

		LPVOID ret = NULL;
		UINT len = 0;
		if (VerQueryValue(pBlock, _T("\\"), &ret, &len) == 0) {
			THROW_API("VerQueryValue", 0, "");
		}
		VS_FIXEDFILEINFO * info = reinterpret_cast<VS_FIXEDFILEINFO *>(ret);

		hVer = HIWORD(info->dwProductVersionMS);
		lVer = LOWORD(info->dwProductVersionMS);
	}

	BOOL getChineseLocal() {
		return FALSE;
	}

	VOID getKeyString(_In_ HTHotkeyInfo CONST& keyInfo, _Out_ TCHAR * CONST dest) {
		BOOL first = TRUE;
		HRESULT hr = S_OK;

		if (keyInfo.ctrl) {
			first = FALSE;
			hr = ::StringCchCopy(dest, MAX_PATH, _T("Ctrl "));
			if (FAILED(hr)) {
				THROW_API("StringCchCopy", 0, "");
			}
		}

		if (keyInfo.shift) {
			if (first) {
				first = FALSE;
				hr = ::StringCchCopy(dest, MAX_PATH, _T("Shift "));
				if (FAILED(hr)) {
					THROW_API("StringCchCopy", 0, "");
				}
			}
			else {
				hr = ::StringCchCat(dest, MAX_PATH, _T("+ Shift "));
				if (FAILED(hr)) {
					THROW_API("StringCchCat", 0, "");
				}
			}
		}

		if (keyInfo.alt) {
			if (first) {
				first = FALSE;
				hr = ::StringCchCopy(dest, MAX_PATH, _T("Alt "));
				if (FAILED(hr)) {
					THROW_API("StringCchCopy", 0, "");
				}
			}
			else {
				hr = ::StringCchCat(dest, MAX_PATH, _T("+ Alt "));
				if (FAILED(hr)) {
					THROW_API("StringCchCat", 0, "");
				}
			}
		}

		size_t len;
		::StringCchLength(dest, MAX_PATH, &len);
		dest[len] = _T('+');
		dest[len + 1] = _T(' ');
		dest[len + 2] = HTFuncs::keyCode2TCHAR(keyInfo.vs_key);
		dest[len + 3] = 0;
	}
}