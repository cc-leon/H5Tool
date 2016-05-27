#pragma once

class HTMainThread : public CWinApp {
protected:
	HANDLE _hProc;
	DWORD _procID;
	BOOL _isSlave;
	BOOL _seekEXE();
	HANDLE _hookDLL(_In_ HANDLE CONST hProc);
	VOID _sendProcIDAndVer(_In_ DWORD CONST procID);
	BOOL _getUninstallSignal();
public:
	static TCHAR CONST MY_TOKEN[];
	HTMainThread();
	virtual ~HTMainThread();

	virtual BOOL InitInstance() override;
	virtual int Run() override;

	DECLARE_MESSAGE_MAP()
};

extern HTMainThread mainThread;
