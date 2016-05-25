#pragma once
class HTConfig : public CWinApp {
public:
	HTConfig();
	virtual ~HTConfig();

	virtual BOOL InitInstance() override;
};

extern HTConfig theApp;