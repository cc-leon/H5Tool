#include "stdafxMainThread.h"
#include "HTMainThread.h"

TCHAR CONST HTMainThread::MY_TOKEN[] = _T("This app sucks");

BEGIN_MESSAGE_MAP(HTMainThread, CWinApp)
END_MESSAGE_MAP()

HTMainThread::HTMainThread():
	_hProc(NULL),
	_procID(0),
	_isSlave(FALSE) 
{ }

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
	
	if (StrCmp(m_lpCmdLine, _T("Scrublord")) == 0) {
		_isSlave = TRUE;
	}
	
	if (CONSTS.init(MY_TOKEN) == FALSE) {
		return FALSE;
	}

	CFrameWnd * tempWnd = new CFrameWnd;
	tempWnd->Create(NULL, NULL);
	m_pMainWnd = tempWnd;

	return TRUE;
}

int HTMainThread::Run() {
	_hProc = NULL;
	_procID = NULL;

	TCHAR exe[MAX_PATH];

	if (CONSTS.getNoShow() == FALSE && _isSlave == FALSE) {
		TCHAR passcode[] = _T(" Scrublord");
		HTFuncs::getFullPath(Files::CONFIG_EXE_NAME, exe, MAX_PATH);
		HANDLE hTemp = HTFuncs::runEXE(exe, passcode);
		if (!VALID_HANDLE(hTemp)) {
			THROW_USER("Configuration tool file is missing, the software is tempered with");
		}
		BOOL uninst = _getUninstallSignal();
		::WaitForSingleObject(_hProc, INFINITE);
	}

	if (_seekEXE() == FALSE) {
		HTFuncs::getFullPath(Files::H5_EXE_NAME, exe, MAX_PATH);
		_hProc = HTFuncs::runEXE(exe,NULL,&_procID);
		if (!VALID_HANDLE(_hProc)) {
			THROW_USER("H5_Game.exe can be found in neither memory nor disk.");
		}
	}

	_hookDLL(_hProc);
	_sendProcIDAndVer(_procID);
	
	::CloseHandle(_hProc);
	
	return 0;
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
					int cmpRes = ::StrCmp(fileName, Files::H5_EXE_NAME);
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
	HRESULT hr = S_OK;

	CHAR dllFullName[MAX_PATH];
	if (::GetCurrentDirectoryA(MAX_PATH, dllFullName) == 0) {
		THROW_API("GetCurrentDirectoryA", 0, "");
	}
	size_t len = 0;
	hr = ::StringCchLengthA(dllFullName, MAX_PATH, &len);
	if (FAILED(hr)) {
		THROW_API("StringCchLengthA", hr, "");
	}
	if (dllFullName[len - 1] != '\\') {
		dllFullName[len] = '\\';
		dllFullName[len + 1] = 0;
	}
	hr = ::StringCchCatA(dllFullName, MAX_PATH, Files::HOOK_DLL_NAME_A);
	if (FAILED(hr)) {
		THROW_API("StringCchCatA", hr, "");
	}
	hr = ::StringCchLengthA(dllFullName, MAX_PATH, &len);
	if (FAILED(hr)) {
		THROW_API("StringCchLengthA", hr, "");
	}

	procAddr = (LPVOID)GetProcAddress(GetModuleHandle(_T("kernel32.dll")), "LoadLibraryA");
	if (procAddr == NULL) {
		THROW_API("GetProcAddress",NULL,"The LoadLibraryW function was not found inside kernel32.dll library.");
	}

	LPVOID memLoc = (LPVOID)VirtualAllocEx(hProc, NULL, len, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (memLoc == NULL) {
		THROW_API("VirtualAllocEx", NULL, "The memory could not be allocated inside the chosen process.");
	}

	int n = WriteProcessMemory(hProc, memLoc, dllFullName, len, NULL);
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

VOID HTMainThread::_sendProcIDAndVer(_In_ DWORD CONST procID) {
	HANDLE hPipe = ::CreateNamedPipe(Files::PIPE_NAME, PIPE_ACCESS_DUPLEX | FILE_FLAG_WRITE_THROUGH,
		PIPE_TYPE_MESSAGE, PIPE_UNLIMITED_INSTANCES, NULL, NULL, INFINITE, NULL);
	DWORD cc = GetLastError();
	if (!VALID_HANDLE(hPipe)) {
		THROW_API("CreateNamedPipe", hPipe, " ");
	}

	::ConnectNamedPipe(hPipe, NULL);
	DWORD cbSize = 0;
	::WriteFile(hPipe, &procID, sizeof(procID), &cbSize, NULL);
	DWORD fileVer = (DWORD)CONSTS.getFileVersion();
	::WriteFile(hPipe, &fileVer, sizeof(fileVer), &cbSize, NULL);
	::CloseHandle(hPipe);
}

BOOL HTMainThread::_getUninstallSignal() {
	HANDLE hPipe = ::CreateNamedPipe(Files::PIPE_NAME, PIPE_ACCESS_DUPLEX | FILE_FLAG_WRITE_THROUGH,
		PIPE_TYPE_MESSAGE, PIPE_UNLIMITED_INSTANCES, NULL, NULL, INFINITE, NULL);
	DWORD cc = GetLastError();
	if (!VALID_HANDLE(hPipe)) {
		THROW_API("CreateNamedPipe", hPipe, " ");
	}

	::ConnectNamedPipe(hPipe, NULL);
	BOOL uninstallResult = FALSE; DWORD cbRecv = 0;
	::ReadFile(hPipe, &uninstallResult, sizeof(uninstallResult), &cbRecv, NULL);
	::CloseHandle(hPipe);
	return uninstallResult;
}

HTMainThread mainThread;
