
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

	DWORD WINAPI MainThread(_In_ LPVOID param) {
		int hookLength = 6;
		DWORD hookAddress = 0x005EBE74;
		jmpBackAddy = hookAddress + hookLength;

		hookFunc((void*)hookAddress, asmFunc, hookLength);

		while (true) {
			if (GetAsyncKeyState(VK_ESCAPE)) {
				CHAR aaa[20];
				_itoa_s(currHeroAddr, aaa, 20, 16);
				MessageBox(NULL, aaa, "", NULL);
			}
			//Sleep(50);
			//break;
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