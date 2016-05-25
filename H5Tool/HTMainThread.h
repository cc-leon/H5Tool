#pragma once

class HTMainThread : public CWinApp {
protected:
	HANDLE _launchEXE();
	HANDLE _seekEXE();
	HANDLE _hookDLL(_In_ HANDLE CONST hProc);
	HANDLE _sendProcID(_In_ DWORD CONST procID);

public:
	static TCHAR CONST H5_EXE_NAME[];
	static CHAR CONST HOOK_DLL_NAME[];
	static TCHAR CONST PIPE_NAME[];

	friend UINT WINAPIV subThread(_Inout_ LPVOID lpParam);

	HTMainThread();
	virtual ~HTMainThread();

	virtual BOOL InitInstance() override;
	DECLARE_MESSAGE_MAP()
};

extern HTMainThread mainThread;
