#include "stdafxConfig.h"
#include "HTConfig.h"
#include "HTConfigWnd.h"

TCHAR CONST HTConfig::MY_TOKEN[] = _T("Screw this window");

HTConfig::HTConfig() {
}


HTConfig::~HTConfig() {
}

BOOL HTConfig::InitInstance() {
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	if (CONSTS.init(MY_TOKEN) == FALSE) {
		return FALSE;
	}

	HTConfigWnd * mainWnd = new HTConfigWnd;
	if (StrCmp(m_lpCmdLine, _T("Scrublord"))==0 ) {
		mainWnd->setSlave();
	}
	mainWnd->Create(NULL, CONSTS.getTCHAR(LangCode::DialogTitle),
		WS_CAPTION | WS_OVERLAPPED | WS_SYSMENU, CRect(300, 200, 100, 100));
	m_pMainWnd = mainWnd;
	mainWnd->ShowWindow(SW_SHOW);
	mainWnd->UpdateWindow();
	

	return TRUE;
}

HTConfig theApp;