// HTInstallWnd.cpp : implementation file
//

#include "stdafxInstall.h"
#include "HTInstallWnd.h"
#include <shlobj.h>
#include <winnls.h>
#include <shobjidl.h>
#include <objbase.h>
#include <objidl.h>
#include <shlguid.h>
// HTInstallWnd

CONST CRect HTInstallWnd::FrameRect(100, 100, 700, 500);
CONST CRect HTInstallWnd::lblDescRect(20, 20, 570, 90);
CONST CRect HTInstallWnd::txtAgreementRect(20, 90, 570, 250);
CONST CRect HTInstallWnd::lblQueryRect(20, 300, 400, 320);
CONST CRect HTInstallWnd::lblWeblinkRect(20, 320, 400, 340);
CONST CRect HTInstallWnd::btnNextRect(400, 295, 560, 320);
CONST CRect HTInstallWnd::btnCancelRect(400, 330, 560, 355);
CONST CRect HTInstallWnd::btnBrowseRect(490, 145, 560, 170);
CONST CRect HTInstallWnd::txtDirRect(20, 145, 480, 170);
CONST CRect HTInstallWnd::lblDirRect(20, 120, 480, 140);
CONST CRect HTInstallWnd::optRunGameRect(20, 120, 560, 140);

IMPLEMENT_DYNCREATE(HTInstallWnd, CFrameWnd)

HTInstallWnd::HTInstallWnd()
{

}

HTInstallWnd::~HTInstallWnd()
{
}


BEGIN_MESSAGE_MAP(HTInstallWnd, CFrameWnd)
	ON_WM_CREATE()
	ON_STN_CLICKED(HTInstallWnd::btnCancelID, On_btnCancel_Clicked)
	ON_STN_CLICKED(HTInstallWnd::btnBrowseID, On_btnBrowse_Clicked)
	ON_STN_CLICKED(HTInstallWnd::btnNextID, On_btnNext_Clicked)
	ON_STN_CLICKED(HTInstallWnd::optRunGameID, On_optRunGame_Clicked)
END_MESSAGE_MAP()


// HTInstallWnd message handlers


int HTInstallWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	SetIcon(hIcon, TRUE);
	UIFonts.displayFont = new CFont();
	UIFonts.displayFont->CreateFont(
		18,                            // Height
		0,                             // Width
		0,                             // Escapement
		0,                             // OrientationME
		FW_REGULAR,                       // Weight
		FALSE,                         // Italic
		FALSE,                          // Underline
		0,                             // StrikeOut
		ANSI_CHARSET,                  // CharSet
		OUT_DEVICE_PRECIS,            // OutPrecision
		CLIP_DEFAULT_PRECIS,           // ClipPrecision
		CLEARTYPE_QUALITY,               // Quality
		FIXED_PITCH | FF_ROMAN,      // PitchAndFamily
		_T("Segoe UI"));      // Facename
	UIFonts.textFont = new CFont();
	UIFonts.textFont->CreateFont(
		15,                            // Height
		0,                             // Width
		0,                             // Escapement
		0,                             // OrientationME
		FW_REGULAR,                       // Weight
		FALSE,                         // Italic
		FALSE,                          // Underline
		0,                             // StrikeOut
		ANSI_CHARSET,                  // CharSet
		OUT_DEVICE_PRECIS,            // OutPrecision
		CLIP_DEFAULT_PRECIS,           // ClipPrecision
		CLEARTYPE_QUALITY,               // Quality
		FIXED_PITCH | FF_ROMAN,      // PitchAndFamily
		_T("Consolas"));      // Facename
	UIFonts.hyperFont = new CFont();
	UIFonts.hyperFont->CreateFont(
		52,                            // Height
		0,                             // Width
		0,                             // Escapement
		0,                             // OrientationME
		FW_REGULAR,                       // Weight
		FALSE,                         // Italic
		FALSE,                          // Underline
		0,                             // StrikeOut
		ANSI_CHARSET,                  // CharSet
		OUT_DEVICE_PRECIS,            // OutPrecision
		CLIP_DEFAULT_PRECIS,           // ClipPrecision
		CLEARTYPE_QUALITY,               // Quality
		FIXED_PITCH | FF_ROMAN,      // PitchAndFamily
		_T("Segoe UI"));      // Facename

	SetFont(UIFonts.displayFont);
	// TODO:  Add your specialized creation code here
	lblDesc = new CStatic;
	lblDesc->Create(CONSTS.getTCHAR(LangCode::InstallerDesc), WS_VISIBLE, lblDescRect, this);
	lblDesc->SetFont(UIFonts.displayFont);

	txtAgreement = new CEdit;
	txtAgreement->Create(WS_VISIBLE | WS_VSCROLL | ES_READONLY | ES_MULTILINE |WS_BORDER,
		txtAgreementRect, this, txtAgreementID);
	txtAgreement->SetWindowText(CONSTS.getTCHAR(LangCode::InstallerAgreement));
	txtAgreement->SetFont(UIFonts.displayFont);
	
	lblQuery = new CStatic;
	lblQuery->Create(CONSTS.getTCHAR(LangCode::QuestionGoto), WS_VISIBLE, lblQueryRect, this);
	lblQuery->SetFont(UIFonts.displayFont);

	lblWeblink = new CMFCLinkCtrl;
	lblWeblink->Create(CONSTS.getWeblink(), WS_VISIBLE, lblWeblinkRect, this, NULL);
	lblWeblink->SetFont(UIFonts.hyperFont);
	lblWeblink->SetURL(CONSTS.getWeblink());

	btnNext = new CButton;
	btnNext->Create(CONSTS.getTCHAR(LangCode::InstallerButtonNext), WS_VISIBLE|BS_DEFPUSHBUTTON, btnNextRect, this, btnNextID);
	btnNext->SetFont(UIFonts.displayFont);

	btnCancel = new CButton;
	btnCancel->Create(CONSTS.getTCHAR(LangCode::InstallerButtonCancel), WS_VISIBLE, btnCancelRect, this, btnCancelID);
	btnCancel->SetFont(UIFonts.displayFont);

	lblDir = new CStatic;
	lblDir->Create(CONSTS.getTCHAR(LangCode::InstallerDirectory), NULL, lblDirRect, this);
	lblDir->SetFont(UIFonts.displayFont);

	txtDir = new CEdit;
	txtDir->Create(ES_READONLY | ES_AUTOHSCROLL |WS_BORDER, txtDirRect, this, txtDirID);
	txtDir->SetFont(UIFonts.textFont);

	btnBrowse = new CButton;
	btnBrowse->Create(CONSTS.getTCHAR(LangCode::InstallerBrowseDirectory), NULL, btnBrowseRect, this, btnBrowseID);
	btnBrowse->SetFont(UIFonts.displayFont);

	optRunGame = new CButton;
	optRunGame->Create(CONSTS.getTCHAR(LangCode::InstallerRunGameCheckBox), BS_CHECKBOX, optRunGameRect, this, optRunGameID);
	optRunGame->SetFont(UIFonts.displayFont);
	return 0;
}


BOOL HTInstallWnd::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Add your specialized code here and/or call the base class
	if (!CFrameWnd::PreCreateWindow(cs))
		return FALSE;

	// TODO: Add your specialized code here and/or call the base class
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.cx = FrameRect.Width();
	cs.cy = FrameRect.Height();
	cs.lpszClass = AfxRegisterWndClass(
		CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW | CS_NOCLOSE, // use any window styles
		AfxGetApp()->LoadStandardCursor(IDC_ARROW),
		(HBRUSH)(COLOR_3DFACE + 1));
	return TRUE;
}

void HTInstallWnd::On_btnCancel_Clicked() {
	if(::MessageBox(this->m_hWnd, CONSTS.getTCHAR(LangCode::InstallerQuitPrompt), _T(""), MB_YESNO | MB_ICONINFORMATION) == IDYES) {
		::PostQuitMessage(0);
	}
}

void HTInstallWnd::On_btnNext_Clicked() {
	if (_stage == Stage::one) {
		txtAgreement->ShowWindow(SW_HIDE);
		lblDesc->SetWindowText(CONSTS.getTCHAR(LangCode::InstallerFolderDectectFailurePrompt));
		btnBrowse->ShowWindow(SW_SHOW);
		lblDir->ShowWindow(SW_SHOW);
		txtDir->ShowWindow(SW_SHOW);
		_stage = Stage::two;
	}
	else if (_stage == Stage::two) {
		TCHAR targetName[MAX_PATH];
		txtDir->GetWindowText(targetName, MAX_PATH);
		HTFuncs::appendSlash(targetName);
		HRESULT hr;
		hr = ::StringCchCat(targetName, MAX_PATH, _T("bin\\"));
		if (FAILED(hr)) {
			THROW_API("StringCchCat", hr, "");
		}

		hr = ::StringCchCat(targetName, MAX_PATH, Files::H5_EXE_NAME);
		if (FAILED(hr)) {
			THROW_API("StringCchCat", hr, "");
		}
		if (::PathFileExists(targetName)) {
			::MessageBox(this->m_hWnd, CONSTS.getTCHAR(LangCode::InstallerInstalledError), _T(""), MB_OK | MB_ICONINFORMATION);
			return;
		}
		HTFuncs::goUpPath(targetName);
		HTFuncs::appendSlash(targetName);

		hr = ::StringCchCat(targetName, MAX_PATH, Files::TOOL_EXE_NAME);
		if (FAILED(hr)) {
			THROW_API("StringCchCat", hr, "");
		}
		if (::PathFileExists(targetName) == FALSE) {
			::MessageBox(this->m_hWnd, CONSTS.getTCHAR(LangCode::InstallerInvalidDirectory), _T(""), MB_ICONERROR);
		}
		else {
			DWORD hVer = 0, lVer = 0;

			HTFuncs::getFileVersion(targetName, hVer, lVer);
			if (hVer != 3 || lVer != 1) {
				if (::MessageBox(this->m_hWnd, CONSTS.getTCHAR(LangCode::InstallerWrongVersionPrompt), _T(""), MB_ICONWARNING | MB_OKCANCEL)==IDCANCEL) {
					return;
				}
			}
			_stage = Stage::three;
			txtDir->GetWindowText(targetName, MAX_PATH);
			HTFuncs::appendSlash(targetName);
			_copyFiles(targetName);
			lblDir->ShowWindow(SW_HIDE);
			txtDir->ShowWindow(SW_HIDE);
			btnBrowse->ShowWindow(SW_HIDE);
			btnCancel->ShowWindow(SW_HIDE);
			lblDesc->SetWindowText(CONSTS.getTCHAR(LangCode::InstallSuccess));
			btnNext->SetWindowText(CONSTS.getTCHAR(LangCode::InstallerButtonFinish));
			optRunGame->ShowWindow(SW_SHOW);
		}
	}
	else if (_stage == Stage::three) {
		if (optRunGame->GetCheck()) {
			STARTUPINFO si = { 0 };
			PROCESS_INFORMATION pi = { 0 };

			TCHAR configFullName[MAX_PATH];
			txtDir->GetWindowText( configFullName,MAX_PATH);
			HTFuncs::appendSlash(configFullName);
			::StringCchCat(configFullName, MAX_PATH, _T("bin\\"));
			TCHAR workingDir[MAX_PATH];
			::StringCchCopy(workingDir, MAX_PATH, configFullName);
			::StringCchCat(configFullName, MAX_PATH, Files::TOOL_EXE_NAME);
			::CreateProcess(configFullName,NULL , NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, workingDir, &si, &pi);
			::CloseHandle(pi.hThread);
			::CloseHandle(pi.hProcess);
		}
		::PostQuitMessage(0);
	}
}

void HTInstallWnd::On_btnBrowse_Clicked() {
	TCHAR * const fileName = ALLOC(TCHAR, txtDir->GetWindowTextLength() + 1);
	txtDir->GetWindowText(fileName, txtDir->GetWindowTextLength() + 1);
	CFolderPickerDialog fileDlg(fileName, NULL, this);
	INT_PTR dlgResult = fileDlg.DoModal();
	if (dlgResult == IDOK) {
		txtDir->SetWindowText(fileDlg.GetPathName());
	}
	FREE(fileName);
}

void HTInstallWnd::On_optRunGame_Clicked() {
	optRunGame->SetCheck(!optRunGame->GetCheck());
}

VOID HTInstallWnd::_copyFiles(_In_ TCHAR CONST * CONST targetDir) {
	TCHAR currDir[MAX_PATH];
	HRESULT hr;
	
	::GetCurrentDirectory(MAX_PATH, currDir);
	HTFuncs::appendSlash(currDir);

	TCHAR targetName[MAX_PATH], currName[MAX_PATH];
	::StringCchPrintf(targetName, MAX_PATH, _T("%sbin\\%s"), targetDir, Files::H5_EXE_NAME);
	::StringCchPrintf(currName, MAX_PATH, _T("%sbin\\%s"), targetDir, Files::TOOL_EXE_NAME);
	::MoveFile(currName, targetName);
	
	::StringCchPrintf(targetName, MAX_PATH,_T("%sbin\\%s"), targetDir, Files::HOOK_DLL_NAME);
	::StringCchPrintf(currName, MAX_PATH, _T("%s%s"), currDir, Files::HOOK_DLL_NAME);
	::CopyFile(currName, targetName, FALSE);
	::StringCchPrintf(targetName, MAX_PATH, _T("%sbin\\%s"), targetDir, Files::TOOL_EXE_NAME);
	::StringCchPrintf(currName, MAX_PATH, _T("%s%s"), currDir, Files::TOOL_EXE_NAME);
	::CopyFile(currName, targetName, FALSE);
	::StringCchPrintf(targetName, MAX_PATH, _T("%sbin\\%s"), targetDir, Files::WEBLINK_FILE_NAME);
	::StringCchPrintf(currName, MAX_PATH, _T("%s%s"), currDir, Files::WEBLINK_FILE_NAME);
	::CopyFile(currName, targetName, FALSE);
	::StringCchPrintf(targetName, MAX_PATH, _T("%sbin\\%s"), targetDir, Files::DB_NAME);
	::StringCchPrintf(currName, MAX_PATH, _T("%s%s"), currDir, Files::DB_NAME);
	::CopyFile(currName, targetName, FALSE);
	::StringCchPrintf(targetName, MAX_PATH, _T("%sbin\\%s"), targetDir, Files::CONFIG_EXE_NAME);
	::StringCchPrintf(currName, MAX_PATH, _T("%s%s"), currDir, Files::CONFIG_EXE_NAME);
	::CopyFile(currName, targetName, FALSE);

	hr = SHGetFolderPath(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, currName);
	if ( FAILED(hr)) {
		THROW_API("SHGetFolderPath", 0, "");
	}
	HTFuncs::appendSlash(currName);
	::StringCchCat(currName, MAX_PATH, CONSTS.getTCHAR(LangCode::ShortcutName));
	::StringCchCat(currName, MAX_PATH, _T(".lnk"));
	TCHAR workingDir[MAX_PATH];
	::StringCchCopy(workingDir, MAX_PATH, targetDir);
	HTFuncs::appendSlash(workingDir);
	::StringCchCat(workingDir, MAX_PATH, _T("bin"));

	IShellLink* psl;
	hr = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLink, (LPVOID*)&psl);
	if (SUCCEEDED(hr)) {
		IPersistFile* ppf;
		psl->SetPath(targetName);
		psl->SetDescription(CONSTS.getTCHAR(LangCode::DialogTitle));
		psl->SetWorkingDirectory(workingDir);
		hr = psl->QueryInterface(IID_IPersistFile, (LPVOID*)&ppf);

		if (SUCCEEDED(hr)) {
			hr = ppf->Save(currName, TRUE);
			ppf->Release();
		}
		psl->Release();
	}
}