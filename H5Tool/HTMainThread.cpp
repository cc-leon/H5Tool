#include "stdafxMainThread.h"
#include "HTMainThread.h"

TCHAR CONST HTMainThread::H5_EXE_NAME[] = _T("H5_Game.exe");
TCHAR CONST HTMainThread::HOOK_DLL_NAME[] = _T("HTDLL.dll");

BEGIN_MESSAGE_MAP(HTMainThread, CWinApp)
END_MESSAGE_MAP()

HTMainThread::HTMainThread() {
}

HTMainThread::~HTMainThread() {
}

BOOL HTMainThread::InitInstance() {
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	CFrameWnd * tempWnd = new CFrameWnd;
	tempWnd->Create(NULL, NULL);
	m_pMainWnd = tempWnd;

	if (::AfxBeginThread(subThread, this) == NULL) {
		THROW_API("AfxBeginThread", NULL, "");
	}

	return TRUE;
}

HANDLE HTMainThread::_launchEXE() {
	STARTUPINFO startInfo;
	PROCESS_INFORMATION procInfo;
	::ZeroMemory(&startInfo, sizeof(startInfo));
	::ZeroMemory(&procInfo, sizeof(procInfo));

	BOOL br = CreateProcess(H5_EXE_NAME,
		NULL, NULL, NULL,
		FALSE,
		NULL, NULL, NULL,
		&startInfo, &procInfo);

	if(br != FALSE) { //exe does exist 
		return 	procInfo.hProcess;
	}
	else {//exe doesn't exis
		return NULL;
	}
}

HANDLE HTMainThread::_seekEXE() {
	HANDLE hProc = NULL;
	DWORD procIDs[_1K],cbProcIDs;
	TCHAR fileName[_1K];

	::EnumProcesses(procIDs, _1K, &cbProcIDs);

	for (DWORD i = 0; i < cbProcIDs; i++) {
		hProc = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, procIDs[i]);
		if (VALID_HANDLE(hProc)) {
			if(::GetModuleFileNameEx(hProc, NULL, fileName, _1K) != 0) {
				size_t slen = HTFuncs::getFileName(fileName, fileName);
				if (slen > 0) {
					int cmpRes = ::StrCmp(fileName, H5_EXE_NAME);
					if (cmpRes == 0) {
						return hProc;
					}
				}
			}
		}
	}

	return NULL; 
}

HANDLE HTMainThread::_hookDLL(_In_ HANDLE CONST hProc) {
	LPVOID procAddr = NULL;

#ifdef _UNICODE
	procAddr = (LPVOID)GetProcAddress(GetModuleHandle(L"kernel32.dll"), "LoadLibraryW");
	if (procAddr == NULL) {
		THROW_API("GetProcAddress",NULL,"The LoadLibraryW function was not found inside kernel32.dll library.");
	}
#else 
	procAddr = (LPVOID)GetProcAddress(GetModuleHandle(L"kernel32.dll"), "LoadLibraryA");
	if (procAddr == NULL) {
		THROW_API("GetProcAddress", NULL, "The LoadLibraryA function was not found inside kernel32.dll library.");
	}
#endif

	LPVOID memLoc = (LPVOID)VirtualAllocEx(hProc, NULL, 10 * 2, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (memLoc == NULL) {
		THROW_API("VirtualAllocEx", NULL, "The memory could not be allocated inside the chosen process.");
	}

	if(WriteProcessMemory(hProc, memLoc, HOOK_DLL_NAME, sizeof(HOOK_DLL_NAME), NULL) == 0) {
		THROW_API("WriteProcessMemory", 0, "There was no bytes written to the process's address space.");
	}

	HANDLE hThread = CreateRemoteThread(hProc, NULL, 0, (LPTHREAD_START_ROUTINE)procAddr, memLoc, NULL, NULL);
	if (hThread == NULL) {
		THROW_API("CreateRemoteThread", 0, "The remote thread could not be created.");
	}

	return hThread;
}

UINT WINAPIV subThread(_Inout_ LPVOID lpParam) {
	HTMainThread * CONST ptr = reinterpret_cast<HTMainThread*>(lpParam);
	HANDLE hProc = NULL;
	TCHAR buffer[] = _T("HTDLL.dll");
	hProc = ptr->_seekEXE();
	
	if (!VALID_HANDLE(hProc)) {
		hProc = ptr->_launchEXE();
	}

	ptr->_hookDLL(hProc);

	CloseHandle(hProc);

	return NULL;
}

HTMainThread mainThread;
