#include "stdafxDLL.h"
#include "HTDLL.h"

namespace HTDLL {

	BOOL hookFunc(_In_ LPVOID CONST toHook, _In_ LPVOID CONST asmFunc, _In_ size_t CONST len) {
		if (len < 5) {
			return FALSE;
		}

		DWORD curProtection = 0;
		::VirtualProtect(toHook, len, PAGE_EXECUTE_READWRITE, &curProtection);

		::memset(toHook, 0x90, len);

		DWORD relativeAddress = ((DWORD)asmFunc - (DWORD)toHook) - 5;

		*(BYTE*)toHook = 0xE9;
		*(DWORD*)((DWORD)toHook + 1) = relativeAddress;

		DWORD temp = 0;
		::VirtualProtect(toHook, len, curProtection, &temp);

		return TRUE;
	}

	void __declspec(naked) asmFunc() {
		__asm {
			mov ecx, [esi + 04]
				mov currHeroAddr, ecx
				cmp ecx, [edi + 04]
				jmp[jmpBackAddy]
		}
	}

	VOID getProcID() {
		HANDLE hPipe = INVALID_HANDLE_VALUE;
		do {
			hPipe = ::CreateFile(
				PIPE_NAME, GENERIC_READ | GENERIC_WRITE,
				0, NULL,
				OPEN_EXISTING,
				0, NULL);
		} while (!VALID_HANDLE(hPipe));

		DWORD cbRead = 0;
		::ReadFile(hPipe, &procID, sizeof(procID), &cbRead, NULL);
		::CloseHandle(hPipe);
	}

	BOOL CALLBACK enumWndProc(_In_ HWND hwnd, _In_ LPARAM lParam) {
		DWORD tID = 0, pID = 0;
		tID = ::GetWindowThreadProcessId(hwnd, &pID);
		if (tID != 0 && pID != 0) {
			if (pID == procID) {
				TCHAR title[MAX_PATH];
				::GetWindowText(hwnd, title, MAX_PATH);
				if (title[0] != _T('D') && title[0] != _T('M')) {
					hWnd = hwnd;
					return FALSE;
				}
			}
		}
		return TRUE;
	}

	VOID seekHWnd() {
		::EnumWindows(enumWndProc, NULL);
	}

	LRESULT CALLBACK callWndProc(_In_ int nCode, _In_ WPARAM wParam, _In_ LPARAM lParam) {
		return 0;
	}

	VOID setKey() {
		BOOL br = ::RegisterHotKey(NULL, 1234, MOD_CONTROL, 0x31);
		if (br) {
			::MessageBox(hWnd, "Success1", NULL, NULL);
		}
		else {
			::MessageBox(hWnd, "Fail1", NULL, NULL);
		}
	}

	VOID procMsg() {
		MSG msg;
		if (::PeekMessage(&msg, NULL, NULL, NULL, PM_NOREMOVE)) {
			::GetMessage(&msg, NULL, NULL, NULL);
			::TranslateMessage(&msg);
			CHAR aaa[20];
			_itoa_s(LOWORD(msg.message), aaa, 20, 16);
			MessageBox(hWnd, aaa, "", NULL);
		}
	}

	DWORD WINAPI MainThread(_In_ LPVOID param) {
		int hookLength = 6;
		DWORD hookAddress = 0x005EBE74;
		jmpBackAddy = hookAddress + hookLength;

		hookFunc((void*)hookAddress, asmFunc, hookLength);

		getProcID();
		seekHWnd();
		setKey();

		while (true) {
			if (GetAsyncKeyState(VK_RCONTROL)) {
				CHAR aaa[20];
				_itoa_s(currHeroAddr, aaa, 20, 16);
				MessageBox(hWnd, aaa, "", NULL);
			}
			procMsg();
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