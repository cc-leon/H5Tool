#include "stdafxDLL.h"
#include "HTDLL.h"

namespace HTDLL {
	namespace Procs {
		VOID getProcIDAndVer() {
			HANDLE hPipe = INVALID_HANDLE_VALUE;
			do {
				hPipe = ::CreateFile(
					Files::PIPE_NAME, GENERIC_READ | GENERIC_WRITE,
					0, NULL,
					OPEN_EXISTING,
					0, NULL);
			} while (!VALID_HANDLE(hPipe));

			DWORD cbRead = 0;
			DWORD fileVer = 0;
			::ReadFile(hPipe, &GVars::procID, sizeof(GVars::procID), &cbRead, NULL);
			CHAR aaa[20];
			_itoa_s(GVars::procID, aaa, 20, 10);
			AfxMessageBox(aaa);
			::ReadFile(hPipe, &fileVer, sizeof(fileVer), &cbRead, NULL);
			GVars::h5Ver = (FileVersion)fileVer;
			::CloseHandle(hPipe);
		}

		VOID seekHWnd() {
			::EnumWindows(ClBks::enumWndProc, NULL);
		}

		VOID setKey() {
			BOOL br = ::RegisterHotKey(NULL, 1234, MOD_CONTROL, 0x31);
		}

		VOID procMsg() {
			MSG msg;
			if (::PeekMessage(&msg, NULL, NULL, NULL, PM_NOREMOVE)) {
				::GetMessage(&msg, NULL, NULL, NULL);
				::TranslateMessage(&msg);
				CHAR aaa[20];
				_itoa_s(LOWORD(msg.message), aaa, 20, 16);
				MessageBox(GVars::hWnd, aaa, "", NULL);
			}
		}

		VOID fillAddrCodes() {

		}

		VOID readHotkeyData() {
			::ZeroMemory(&GVars::keyInfo, sizeof(GVars::keyInfo));
			HTHotkeyInfo *reader;
			CHAR configFullName[MAX_PATH];
			Funcs::getFullPath(Files::CONFIG_FILE_NAME, configFullName, MAX_PATH);

			//BYTE = ALLOC(BYTE, );
		}
	}

	namespace Funcs {
		VOID appendSlash(_Inout_ TCHAR * CONST src) {
			size_t len = 0;
			HRESULT hr = ::StringCchLength(src, MAX_PATH, &len);
			if (FAILED(hr)) {
				THROW_API("StringCchLength", hr, "");
			}
			if (src[len - 1] != _T('\\')) {
				src[len] = _T('\\');
				src[len + 1] = _T('\0');
			}
		}

		VOID getFullPath(_In_ TCHAR CONST * CONST filename, _Out_ TCHAR * CONST dest, _In_ size_t CONST maxLen) {
			HRESULT hr = S_OK;
			if (::GetCurrentDirectory(maxLen, dest) == 0) {
				THROW_API("GetCurrentDirectory", 0, "");
			}
			appendSlash(dest);
			hr = ::StringCchCat(dest, maxLen, filename);
			if (FAILED(hr)) {
				THROW_API("StringCchCat", hr, "");
			}
		}
	}

	namespace ASMs {
		void __declspec(naked) asmFunc31() {
			__asm {
				mov ecx, [esi + 04]
					mov GVars::currHeroAddr, ecx
					cmp ecx, [edi + 04]
					jmp[GVars::jmpBackAddy]
			}
		}
	}

	namespace ClBks {
		LRESULT CALLBACK callWndProc(_In_ int nCode, _In_ WPARAM wParam, _In_ LPARAM lParam) {
			return 0;
		}
		BOOL CALLBACK enumWndProc(_In_ HWND hwnd, _In_ LPARAM lParam) {
			DWORD tID = 0, pID = 0;
			tID = ::GetWindowThreadProcessId(hwnd, &pID);
			if (tID != 0 && pID != 0) {
				if (pID == GVars::procID) {
					TCHAR title[MAX_PATH];
					::GetWindowText(hwnd, title, MAX_PATH);
					if (title[0] != _T('D') && title[0] != _T('M')) {						
						GVars::hWnd = hwnd;
						return FALSE;
					}
				}
			}
			return TRUE;
		}
		
	}

	BOOL hookFunc(_In_ LPVOID CONST toHook, _In_ LPVOID CONST asmFunc31, _In_ size_t CONST len) {
		if (len < 5) {
			return FALSE;
		}

		DWORD curProtection = 0;
		::VirtualProtect(toHook, len, PAGE_EXECUTE_READWRITE, &curProtection);

		::memset(toHook, 0x90, len);

		DWORD relativeAddress = ((DWORD)asmFunc31 - (DWORD)toHook) - 5;

		*(BYTE*)toHook = 0xE9;
		*(DWORD*)((DWORD)toHook + 1) = relativeAddress;

		DWORD temp = 0;
		::VirtualProtect(toHook, len, curProtection, &temp);

		return TRUE;
	}

	DWORD WINAPI MainThread(_In_ LPVOID param) {
		Procs::getProcIDAndVer();
		Procs::seekHWnd();
		Procs::setKey();

		int hookLength = 6;
		DWORD hookAddress = 0x005EBE74;
		GVars::jmpBackAddy = hookAddress + hookLength;

		switch (GVars::h5Ver) {
		case FileVersion::THREE_ONE:
			hookFunc((void*)hookAddress, ASMs::asmFunc31, hookLength);
			break;
		case FileVersion::THREE_ZERO:
			break;
		case FileVersion::MAX:
			break;
		default:
			break;
		}

		while (true) {
			if (GetAsyncKeyState(VK_RCONTROL)) {
				CHAR aaa[20];
				_itoa_s(GVars::currHeroAddr, aaa, 20, 16);
				MessageBox(GVars::hWnd, aaa, "", NULL);
			}
			Procs::procMsg();
			Sleep(50);
		}

		::FreeLibraryAndExitThread((HMODULE)param, 0);

		return 0;
	}

}

BOOL WINAPI DllMain(_In_ HINSTANCE hModule, _In_ DWORD dwReason, _In_ LPVOID lpReserved) {
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		::CreateThread(0, 0, HTDLL::MainThread, hModule, 0, 0);
		break;
	}

	return TRUE;
}