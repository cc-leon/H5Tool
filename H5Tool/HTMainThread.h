#pragma once

class HTMainThread : public CWinApp {
protected:
	HANDLE _hProc;
	DWORD _procID;
	BOOL _isSlave;
	BOOL _launchEXE(_In_ TCHAR CONST * CONST fullName, _In_ TCHAR * CONST param = NULL);
	BOOL _seekEXE();
	HANDLE _hookDLL(_In_ HANDLE CONST hProc);
	VOID _sendProcID(_In_ DWORD CONST procID);
	BOOL _getUninstallSignal();
public:
	static CHAR CONST HOOK_DLL_NAME[];
	static TCHAR CONST CONFIG_EXE_NAME[];
	static TCHAR CONST MY_TOKEN[];
	HTMainThread();
	virtual ~HTMainThread();

	virtual BOOL InitInstance() override;
	virtual int Run() override;

	DECLARE_MESSAGE_MAP()
};

extern HTMainThread mainThread;
