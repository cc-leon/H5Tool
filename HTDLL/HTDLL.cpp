#include "stdafxDLL.h"

BOOL WINAPI DllMain(_In_ HINSTANCE hinstDLL, _In_ DWORD fdwReason, _In_ LPVOID lpvReserved) {
	switch (fdwReason) {
	case DLL_PROCESS_ATTACH:
		AfxMessageBox (_T("DLL attach function called.\n"));
		break;
	case DLL_PROCESS_DETACH:
		AfxMessageBox(_T("DLL detach function called.\n"));
		break;
	case DLL_THREAD_ATTACH:
		AfxMessageBox(_T("DLL thread attach function called.\n"));
		break;
	case DLL_THREAD_DETACH:
		AfxMessageBox(_T("DLL thread detach function called.\n"));
		break;
	}

	return FALSE;
}