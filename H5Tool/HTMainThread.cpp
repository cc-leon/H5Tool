#include "stdafxMainThread.h"
#include "HTMainThread.h"

CHAR CONST HTMainThread::HOOK_DLL_NAME[] = "D:\\Projects\\H5Tool\\Debug\\HTDLL.dll";

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


	return TRUE;
}

int HTMainThread::Run() {
	_hProc = NULL;
	_procID = NULL;

	if (_seekEXE() == FALSE) {
		if (_launchEXE() == FALSE) {
			THROW_USER("H5_Game.exe can be found in neither memory nor disk.");
		}
	}

	_hookDLL(_hProc);

	_sendProcID(_procID);

	::WaitForSingleObject(_hProc, INFINITE);
	::CloseHandle(_hProc);
	
	return 0;
}

BOOL HTMainThread::_launchEXE() {
	STARTUPINFO startInfo;
	PROCESS_INFORMATION procInfo;
	::ZeroMemory(&startInfo, sizeof(startInfo));
	::ZeroMemory(&procInfo, sizeof(procInfo));

	BOOL br = CreateProcess(H5_EXE_NAME,
		NULL, NULL, NULL,
		FALSE,
		NULL, NULL, NULL,
		&startInfo, &procInfo);

	_hProc = procInfo.hProcess;
	_procID = procInfo.dwProcessId;

	return br;
}

BOOL HTMainThread::_seekEXE() {
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
						_hProc = hProc;
						_procID = procIDs[i];
						return TRUE;
					}
				}
			}
		}
		::CloseHandle(hProc);
	}

	return FALSE; 
}

HANDLE HTMainThread::_hookDLL(_In_ HANDLE CONST hProc) {
	LPVOID procAddr = NULL;

	procAddr = (LPVOID)GetProcAddress(GetModuleHandle(_T("kernel32.dll")), "LoadLibraryA");
	if (procAddr == NULL) {
		THROW_API("GetProcAddress",NULL,"The LoadLibraryW function was not found inside kernel32.dll library.");
	}

	LPVOID memLoc = (LPVOID)VirtualAllocEx(hProc, NULL, strlen(HOOK_DLL_NAME), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (memLoc == NULL) {
		THROW_API("VirtualAllocEx", NULL, "The memory could not be allocated inside the chosen process.");
	}

	int n = WriteProcessMemory(hProc, memLoc, HOOK_DLL_NAME, strlen(HOOK_DLL_NAME), NULL);
	if( n == 0) {
		THROW_API("WriteProcessMemory", 0, "There was no bytes written to the process's address space.");
	}

	HANDLE hThread = CreateRemoteThread(hProc, NULL, 0, (LPTHREAD_START_ROUTINE)procAddr, memLoc, NULL, NULL);
	if (hThread == NULL) {
		THROW_API("CreateRemoteThread", 0, "The remote thread could not be created.");
	}

	return hThread;
	return 0;
}

VOID HTMainThread::_sendProcID(_In_ DWORD CONST procID) {
	HANDLE hPipe = ::CreateNamedPipe(PIPE_NAME, PIPE_ACCESS_DUPLEX | FILE_FLAG_WRITE_THROUGH,
		PIPE_TYPE_MESSAGE, PIPE_UNLIMITED_INSTANCES, NULL, NULL, NULL, NULL);
	DWORD cc = GetLastError();
	if (!VALID_HANDLE(hPipe)) {
		THROW_API("CreateNamedPipe", hPipe, " ");
	}

	::ConnectNamedPipe(hPipe, NULL);
	::WriteFile(hPipe, &procID, sizeof(procID), NULL, NULL);
	
	::CloseHandle(hPipe);
}

HTMainThread mainThread;
