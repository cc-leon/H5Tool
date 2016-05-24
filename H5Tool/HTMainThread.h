#pragma once

class HTMainThread : public CWinApp {
protected:

public:
	friend UINT WINAPIV subThread(_Inout_ LPVOID lpParam);
	
	HTMainThread();
	virtual ~HTMainThread();

	virtual BOOL InitInstance() override;
	DECLARE_MESSAGE_MAP()
};

extern HTMainThread mainThread;
