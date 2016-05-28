#pragma once
class H5Tool_Installer : public CWinApp {
public:
	static TCHAR CONST MY_TOKEN[];
	H5Tool_Installer();
	~H5Tool_Installer();
	virtual BOOL InitInstance();
};

extern H5Tool_Installer theApp;