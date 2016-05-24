#pragma once

class HTMainThread : public CWinApp {
public:
	HTMainThread();
	~HTMainThread();
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern HTMainThread mainThread;
