#pragma once
class HTConfig : public CWinApp {
public:
	static TCHAR CONST MY_TOKEN[];
	HTConfig();
	virtual ~HTConfig();

	virtual BOOL InitInstance() override;
};

extern HTConfig theApp;