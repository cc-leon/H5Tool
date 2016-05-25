
#include <Windows.h>

bool Hook(void * toHook, void * ourFunct, int len) {
	if (len < 5) {
		return false;
	}

	DWORD curProtection;
	VirtualProtect(toHook, len, PAGE_EXECUTE_READWRITE, &curProtection);

	memset(toHook, 0x90, len);

	DWORD relativeAddress = ((DWORD)ourFunct - (DWORD)toHook) - 5;

	*(BYTE*)toHook = 0xE9;
	*(DWORD*)((DWORD)toHook + 1) = relativeAddress;

	DWORD temp;
	VirtualProtect(toHook, len, curProtection, &temp);

	return true;
}

DWORD jmpBackAddy = 0;
DWORD address = 0;
void __declspec(naked) ourFunct() {
	__asm {
		mov ecx, [esi + 04]
			mov address, ecx
			cmp ecx, [edi + 04]
			jmp[jmpBackAddy]
	}
}

DWORD WINAPI MainThread(LPVOID param) {
	int hookLength = 6;
	DWORD hookAddress = 0x005EBE74;
	jmpBackAddy = hookAddress + hookLength;

	Hook((void*)hookAddress, ourFunct, hookLength);

	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE)) {
			CHAR aaa[20];
			_itoa_s(address, aaa, 20, 16);
			MessageBox(NULL, aaa, "", NULL);
		}
		//Sleep(50);
		//break;
	}

	FreeLibraryAndExitThread((HMODULE)param, 0);

	return 0;
}

BOOL WINAPI DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved) {
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, MainThread, hModule, 0, 0);
		break;
	}

	return TRUE;
}