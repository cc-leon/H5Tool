#include "stdafxInstall.h"
#include "H5Tool_Installer.h"
#include "HTInstallWnd.h"

CONST TCHAR H5Tool_Installer::MY_TOKEN[] = _T("Screw those bitches");

H5Tool_Installer::H5Tool_Installer() {
}


H5Tool_Installer::~H5Tool_Installer() {
}

H5Tool_Installer theApp;


BOOL H5Tool_Installer::InitInstance()
{
	// TODO: Add your specialized code here and/or call the base class
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);
	
	int mr = ::MessageBox(NULL, _T("点击“是(Yes)”使用中文安装界面。\n"
		"Click 否(No) to start the installation in English interface"),
		_T("安装程序语言选择|Choose your language"), MB_YESNOCANCEL | MB_ICONINFORMATION);
	if (mr == IDYES) {
		if (CONSTS.init(MY_TOKEN,1) == FALSE) {
			return FALSE;
		}
	}
	else if(mr ==IDNO) {
		if (CONSTS.init(MY_TOKEN,-1) == FALSE) {
			return FALSE;
		}
	}
	else {
		return FALSE;
	}

	HTInstallWnd * mainWnd = new HTInstallWnd;
	
	mainWnd->Create(NULL, CONSTS.getTCHAR(LangCode::InstallerTitle),
		WS_CAPTION | WS_OVERLAPPED | WS_SYSMENU, CRect(300, 200, 100, 100));
	m_pMainWnd = mainWnd;
	mainWnd->ShowWindow(SW_SHOW);
	mainWnd->UpdateWindow();


	return TRUE;
}
