#pragma once

class HTMainThread : public CWinApp {
public:
	HTMainThread();
	
	~HTMainThread();
	virtual BOOL InitInstance() override;
	DECLARE_MESSAGE_MAP()
};

UINT WINAPIV bgThread(LPVOID pParam);

extern HTMainThread mainThread;
