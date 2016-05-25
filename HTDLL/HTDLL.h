#pragma once

BOOL WINAPI DllMain(_In_ HINSTANCE hinstDLL, _In_ DWORD fdwReason, _In_ LPVOID lpvReserved);
DWORD WINAPI MainThread(LPVOID param);

struct  {
	DWORD jmpBackAddy = 0;
	DWORD address = 0;
}InfoStack;