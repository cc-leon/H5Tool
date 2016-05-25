#include "stdafxConfig.h"
#include "HTConfig.h"
#include "HTConfigWnd.h"

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

	CWinApp::InitInstance();

	HTConfigWnd * mainWnd = new HTConfigWnd;
	mainWnd->Create(NULL, NULL, 
		WS_VISIBLE | WS_CAPTION | WS_BORDER | WS_SYSMENU);
	m_pMainWnd = mainWnd;

	return TRUE;
}

HTConfig theApp;