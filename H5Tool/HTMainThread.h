#pragma once

class HTMainThread : public CWinApp {
protected:
	HANDLE _hProc;
	DWORD _procID;
	BOOL _launchEXE();
	BOOL _seekEXE();
	HANDLE _hookDLL(_In_ HANDLE CONST hProc);
	VOID _sendProcID(_In_ DWORD CONST procID);

public:
	static TCHAR CONST H5_EXE_NAME[];
	static CHAR CONST HOOK_DLL_NAME[];

	friend UINT WINAPIV subThread(_Inout_ LPVOID lpParam);

	HTMainThread();
	virtual ~HTMainThread();

	virtual BOOL InitInstance() override;
	DECLARE_MESSAGE_MAP()
};

extern HTMainThread mainThread;
