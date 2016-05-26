#include "stdafxConfig.h"
#include "HTConfigWnd.h"

CRect CONST HTConfigWnd::MainFrameRect(300, 200, 900, 600);
CRect CONST HTConfigWnd::ConfigFrameRect(300, 200, 900, 600);
CRect CONST HTConfigWnd::lblS1Rect(10, 60, 570, 80);
CRect CONST HTConfigWnd::lblS2Rect(10, 90, 570, 110);
CRect CONST HTConfigWnd::lblSCRect(10, 150, 570, 170);
CRect CONST HTConfigWnd::lblSPRect(10, 120, 570, 140);
CRect CONST HTConfigWnd::lblCSRect(10, 180, 570, 200);
CRect CONST HTConfigWnd::lblDescRect(10, 10, 570, 50);
CRect CONST HTConfigWnd::lblQuestionRect(10, 300, 400, 320);
CRect CONST HTConfigWnd::lblLinkRect(10, 320, 400, 360);
CRect CONST HTConfigWnd::btnPlayRect(470, 240, 570, 270);
CRect CONST HTConfigWnd::btnConfigRect(470, 280, 570, 310);
CRect CONST HTConfigWnd::btnUninstallRect(470, 320, 570, 350);
CRect CONST HTConfigWnd::optNoShowRect(10, 240, 460, 260);
CRect CONST HTConfigWnd::btnConfirmRect(470, 295, 570, 320);
CRect CONST HTConfigWnd::btnCancelRect(470, 330, 570, 355);
CRect CONST HTConfigWnd::grpConfigRect(10, 10, 570, 290);
CRect CONST HTConfigWnd::lbls1P1Rect(10, 50, 50, 70);
CRect CONST HTConfigWnd::lbls2P1Rect(10, 90, 50, 110);
CRect CONST HTConfigWnd::lblscP1Rect(10, 170, 50, 190);
CRect CONST HTConfigWnd::lblspP1Rect(10, 130, 50, 150);
CRect CONST HTConfigWnd::lblcsP1Rect(10, 210, 50, 230);
CRect CONST HTConfigWnd::lbls1P2Rect(230, 50, 570, 70);
CRect CONST HTConfigWnd::lbls2P2Rect(230, 90, 570, 110);
CRect CONST HTConfigWnd::lblscP2Rect(230, 170, 420, 190);
CRect CONST HTConfigWnd::lblspP2Rect(230, 130, 570, 150);
CRect CONST HTConfigWnd::lblcsP2Rect(230, 210, 570, 230);
CRect CONST HTConfigWnd::lblscP3Rect(455, 170, 570, 190);
CRect CONST HTConfigWnd::lblCtrlRect(60, 30, 100, 50);
CRect CONST HTConfigWnd::lblShiftRect(100, 30, 140, 50);;
CRect CONST HTConfigWnd::lblAltRect(140, 30, 180, 50);;
CRect CONST HTConfigWnd::hcbs1CtrlRect(60, 50, 100, 70);
CRect CONST HTConfigWnd::hcbs1ShiftRect(100, 50, 140, 70);
CRect CONST HTConfigWnd::hcbs1AltRect(140, 50, 180, 70);
CRect CONST HTConfigWnd::hcbs2CtrlRect(60, 90, 100, 110);
CRect CONST HTConfigWnd::hcbs2ShiftRect(100, 90, 140, 110);
CRect CONST HTConfigWnd::hcbs2AltRect(140, 90, 180, 110);
CRect CONST HTConfigWnd::hcbscCtrlRect(60, 170, 100, 190);
CRect CONST HTConfigWnd::hcbscShiftRect(100, 170, 140, 190);
CRect CONST HTConfigWnd::hcbscAltRect(140, 170, 180, 190);
CRect CONST HTConfigWnd::hcbspCtrlRect(60, 130, 100, 150);
CRect CONST HTConfigWnd::hcbspShiftRect(100, 130, 140, 150);
CRect CONST HTConfigWnd::hcbspAltRect(140, 130, 180, 150);
CRect CONST HTConfigWnd::hcbcsCtrlRect(60, 210, 100, 230);
CRect CONST HTConfigWnd::hcbcsShiftRect(100, 210, 140, 230);
CRect CONST HTConfigWnd::hcbcsAltRect(140, 210, 180, 230);
CRect CONST HTConfigWnd::cmbS1Rect(180, 50, 220, 200);
CRect CONST HTConfigWnd::cmbS2Rect(180, 90, 220, 240);
CRect CONST HTConfigWnd::cmbSCRect(180, 170, 220, 320);
CRect CONST HTConfigWnd::cmbSPRect(180, 130, 220, 280);
CRect CONST HTConfigWnd::cmbCSRect(180, 210, 220, 360);
CRect CONST HTConfigWnd::txtSCRect(420, 170, 450, 190);

IMPLEMENT_DYNAMIC ( HTConfigWnd, CFrameWnd)

BEGIN_MESSAGE_MAP  (HTConfigWnd, CFrameWnd)
	ON_WM_CREATE()
	ON_STN_CLICKED(HTConfigWnd::btnCancelID, On_btnCancel_Clicked)
	ON_STN_CLICKED(HTConfigWnd::btnConfirmID, On_btnConfirm_Clicked)
	ON_STN_CLICKED(HTConfigWnd::btnUninstallID, On_btnUninstall_Clicked)
	ON_STN_CLICKED(HTConfigWnd::btnConfigID, On_btnConfig_Clicked)
	ON_STN_CLICKED(HTConfigWnd::btnPlayID, On_btnPlay_Clicked)
	ON_STN_CLICKED(HTConfigWnd::optNoShowID, On_optNoShow_Clicked)
END_MESSAGE_MAP()


HTConfigWnd::HTConfigWnd() :
	_isSlave(FALSE)
{ }


HTConfigWnd::~HTConfigWnd() {
}

BOOL HTConfigWnd::PreCreateWindow(CREATESTRUCT& cs) {
	if (!CFrameWnd::PreCreateWindow(cs))
		return FALSE;

	// TODO: Add your specialized code here and/or call the base class
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.cx = MainFrameRect.Width();
	cs.cy = MainFrameRect.Height();
	cs.lpszClass = AfxRegisterWndClass(
		CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW | CS_NOCLOSE, // use any window styles
		AfxGetApp()->LoadStandardCursor(IDC_ARROW),
		(HBRUSH)(COLOR_BTNFACE + 1));
	return TRUE;
}


int HTConfigWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	TCHAR buffer[MAX_PATH];
	HRESULT hr = S_OK;
	// TODO:  Add your specialized creation code here
	
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

	UIInfoFrame.desc = new CStatic;
	UIInfoFrame.desc->Create(CONSTS.getTCHAR(LangCode::Description),
		 WS_VISIBLE,
		lblDescRect,
		this, NULL);
	UIInfoFrame.desc->SetFont(UIFonts.displayFont);
	
	UIInfoFrame.play = new CButton;
	UIInfoFrame.play->Create(CONSTS.getTCHAR(LangCode::StartGame),
		BS_PUSHBUTTON |BS_DEFPUSHBUTTON | WS_VISIBLE,
		btnPlayRect,
		this, btnPlayID);
	UIInfoFrame.play->SetFont(UIFonts.displayFont);
	
	UIInfoFrame.config = new CButton;
	UIInfoFrame.config->Create(CONSTS.getTCHAR(LangCode::Config),
		BS_PUSHBUTTON | WS_VISIBLE,
		btnConfigRect,
		this, btnConfigID);
	UIInfoFrame.config->SetFont(UIFonts.displayFont);

	UIInfoFrame.uninstall = new CButton;
	UIInfoFrame.uninstall->Create(CONSTS.getTCHAR(LangCode::Unintall),
		BS_PUSHBUTTON | WS_VISIBLE,
		btnUninstallRect,
		this, btnUninstallID);
	UIInfoFrame.uninstall->SetFont(UIFonts.displayFont);

	TCHAR keyString[MAX_PATH];
	UIInfoFrame.s1 = new CStatic;
	HTFuncs::getKeyString(CONSTS.getHotkey(CONSTS.hk_S1), keyString);
	hr = ::StringCchPrintf(buffer, MAX_PATH, CONSTS.getTCHAR(LangCode::Split1Desc),  keyString);
	UIInfoFrame.s1->Create(buffer, SS_SIMPLE | WS_VISIBLE, lblS1Rect, this);
	UIInfoFrame.s1->SetFont(UIFonts.displayFont);

	UIInfoFrame.s2 = new CStatic;
	HTFuncs::getKeyString(CONSTS.getHotkey(CONSTS.hk_S2), keyString);
	hr = ::StringCchPrintf(buffer, MAX_PATH, CONSTS.getTCHAR(LangCode::Split2Desc), keyString);
	UIInfoFrame.s2->Create(buffer, SS_SIMPLE | WS_VISIBLE, lblS2Rect, this);
	UIInfoFrame.s2->SetFont(UIFonts.displayFont);

	UIInfoFrame.sp = new CStatic;
	HTFuncs::getKeyString(CONSTS.getHotkey(CONSTS.hk_SP), keyString);
	hr = ::StringCchPrintf(buffer, MAX_PATH, CONSTS.getTCHAR(LangCode::SplitSPDesc), keyString);
	UIInfoFrame.sp->Create(buffer, SS_SIMPLE | WS_VISIBLE, lblSPRect, this);
	UIInfoFrame.sp->SetFont(UIFonts.displayFont);

	UIInfoFrame.sc = new CStatic;
	HTFuncs::getKeyString(CONSTS.getHotkey(CONSTS.hk_SC),keyString);
	hr = ::StringCchPrintf(buffer, MAX_PATH, CONSTS.getTCHAR(LangCode::SplitCustomDesc), keyString,
		CONSTS.getHotkey(CONSTS.hk_SC).amount);
	UIInfoFrame.sc->Create(buffer, SS_SIMPLE | WS_VISIBLE, lblSCRect, this);
	UIInfoFrame.sc->SetFont(UIFonts.displayFont);

	UIInfoFrame.cs = new CStatic;
	HTFuncs::getKeyString(CONSTS.getHotkey(CONSTS.hk_CS),(keyString));
	hr = ::StringCchPrintf(buffer, MAX_PATH, CONSTS.getTCHAR(LangCode::CombineDesc), keyString);
	UIInfoFrame.cs->Create(buffer, SS_SIMPLE | WS_VISIBLE, lblCSRect, this);
	UIInfoFrame.cs->SetFont(UIFonts.displayFont);
	
	UIInfoFrame.noShow = new CButton;
	UIInfoFrame.noShow->Create(CONSTS.getTCHAR(LangCode::DontShow),
		BS_CHECKBOX | WS_VISIBLE, optNoShowRect, this, optNoShowID);
	UIInfoFrame.noShow->SetFont(UIFonts.displayFont);
	
	UIConfigFrame.frame = new CButton;
	UIConfigFrame.frame->Create(CONSTS.getTCHAR(LangCode::ConfigDescTile),
		WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
		grpConfigRect,
		this, NULL);
	UIConfigFrame.frame->SetFont(UIFonts.displayFont);
	{
		UIConfigFrame.ctrl = new CStatic;
		UIConfigFrame.ctrl->Create(_T("Ctrl"), SS_SIMPLE | WS_VISIBLE, lblCtrlRect, UIConfigFrame.frame);
		UIConfigFrame.ctrl->SetFont(UIFonts.displayFont);

		UIConfigFrame.shift = new CStatic;
		UIConfigFrame.shift->Create(_T("Shift"), SS_SIMPLE | WS_VISIBLE, lblShiftRect, UIConfigFrame.frame);
		UIConfigFrame.shift->SetFont(UIFonts.displayFont);

		UIConfigFrame.alt = new CStatic;
		UIConfigFrame.alt->Create(_T("Alt"), SS_SIMPLE | WS_VISIBLE, lblAltRect, UIConfigFrame.frame);
		UIConfigFrame.alt->SetFont(UIFonts.displayFont);
		
		UIConfigFrame.s1P1 = new CStatic;
		UIConfigFrame.s1P1->Create(CONSTS.getTCHAR(LangCode::ToPress), SS_SIMPLE | WS_VISIBLE, lbls1P1Rect, UIConfigFrame.frame);
		UIConfigFrame.s1P1->SetFont(UIFonts.displayFont);

		UIConfigFrame.s1Ctrl = new HTHotkeyCheckBox;
		UIConfigFrame.s1Ctrl->createCheckBox(_T(""), WS_VISIBLE, hcbs1CtrlRect, UIConfigFrame.frame, s1CtrlID);

		UIConfigFrame.s1Shift = new HTHotkeyCheckBox;
		UIConfigFrame.s1Shift->createCheckBox(_T(""), WS_VISIBLE, hcbs1ShiftRect, UIConfigFrame.frame, s1ShiftID);

		UIConfigFrame.s1Alt = new HTHotkeyCheckBox;
		UIConfigFrame.s1Alt->createCheckBox(_T(""), WS_VISIBLE, hcbs1AltRect, UIConfigFrame.frame, s1AltID);

		UIConfigFrame.s1Ctrl->setBrother(UIConfigFrame.s1Shift, UIConfigFrame.s1Alt);
		UIConfigFrame.s1Shift->setBrother(UIConfigFrame.s1Ctrl, UIConfigFrame.s1Alt);
		UIConfigFrame.s1Alt->setBrother(UIConfigFrame.s1Shift, UIConfigFrame.s1Ctrl);

		UIConfigFrame.cmbS1 = new CComboBox;
		UIConfigFrame.cmbS1->Create(WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST, cmbS1Rect, UIConfigFrame.frame, cmbS1ID);
		UIConfigFrame.cmbS1->SetFont(UIFonts.textFont);
		UIConfigFrame.cmbS1->SetItemHeight(-1, 16);
		_fillCombo(*UIConfigFrame.cmbS1);

		UIConfigFrame.s1P2 = new CStatic;
		UIConfigFrame.s1P2->Create(CONSTS.getTCHAR(LangCode::Split1ConfigDesc), SS_SIMPLE | WS_VISIBLE, lbls1P2Rect, UIConfigFrame.frame);
		UIConfigFrame.s1P2->SetFont(UIFonts.displayFont);

		UIConfigFrame.s2P1 = new CStatic;
		UIConfigFrame.s2P1->Create(CONSTS.getTCHAR(LangCode::ToPress), SS_SIMPLE | WS_VISIBLE, lbls2P1Rect, UIConfigFrame.frame);
		UIConfigFrame.s2P1->SetFont(UIFonts.displayFont);

		UIConfigFrame.s2Ctrl = new HTHotkeyCheckBox;
		UIConfigFrame.s2Ctrl->createCheckBox(_T(""), WS_VISIBLE, hcbs2CtrlRect, UIConfigFrame.frame, s2CtrlID);

		UIConfigFrame.s2Shift = new HTHotkeyCheckBox;
		UIConfigFrame.s2Shift->createCheckBox(_T(""), WS_VISIBLE, hcbs2ShiftRect, UIConfigFrame.frame, s2ShiftID);

		UIConfigFrame.s2Alt = new HTHotkeyCheckBox;
		UIConfigFrame.s2Alt->createCheckBox(_T(""), WS_VISIBLE, hcbs2AltRect, UIConfigFrame.frame, s2AltID);

		UIConfigFrame.s2Ctrl->setBrother(UIConfigFrame.s2Shift, UIConfigFrame.s2Alt);
		UIConfigFrame.s2Shift->setBrother(UIConfigFrame.s2Ctrl, UIConfigFrame.s2Alt);
		UIConfigFrame.s2Alt->setBrother(UIConfigFrame.s2Shift, UIConfigFrame.s2Ctrl);

		UIConfigFrame.cmbS2 = new CComboBox;
		UIConfigFrame.cmbS2->Create(WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST, cmbS2Rect, UIConfigFrame.frame, cmbS2ID);
		UIConfigFrame.cmbS2->SetFont(UIFonts.textFont);
		UIConfigFrame.cmbS2->SetItemHeight(-1, 16);
		_fillCombo(*UIConfigFrame.cmbS2);


		UIConfigFrame.s2P2 = new CStatic;
		UIConfigFrame.s2P2->Create(CONSTS.getTCHAR(LangCode::Split2ConfigDesc), SS_SIMPLE | WS_VISIBLE, lbls2P2Rect, UIConfigFrame.frame);
		UIConfigFrame.s2P2->SetFont(UIFonts.displayFont);
		
		UIConfigFrame.spP1 = new CStatic;
		UIConfigFrame.spP1->Create(CONSTS.getTCHAR(LangCode::ToPress), SS_SIMPLE | WS_VISIBLE, lblspP1Rect, UIConfigFrame.frame);
		UIConfigFrame.spP1->SetFont(UIFonts.displayFont);

		UIConfigFrame.spCtrl = new HTHotkeyCheckBox;
		UIConfigFrame.spCtrl->createCheckBox(_T(""), WS_VISIBLE, hcbspCtrlRect, UIConfigFrame.frame, spCtrlID);

		UIConfigFrame.spShift = new HTHotkeyCheckBox;
		UIConfigFrame.spShift->createCheckBox(_T(""), WS_VISIBLE, hcbspShiftRect, UIConfigFrame.frame, spShiftID);

		UIConfigFrame.spAlt = new HTHotkeyCheckBox;
		UIConfigFrame.spAlt->createCheckBox(_T(""), WS_VISIBLE, hcbspAltRect, UIConfigFrame.frame, spAltID);

		UIConfigFrame.spCtrl->setBrother(UIConfigFrame.spShift, UIConfigFrame.spAlt);
		UIConfigFrame.spShift->setBrother(UIConfigFrame.spCtrl, UIConfigFrame.spAlt);
		UIConfigFrame.spAlt->setBrother(UIConfigFrame.spShift, UIConfigFrame.spCtrl);

		UIConfigFrame.cmbSP = new CComboBox;
		UIConfigFrame.cmbSP->Create(WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST, cmbSPRect, UIConfigFrame.frame, cmbSPID);
		UIConfigFrame.cmbSP->SetFont(UIFonts.textFont);
		UIConfigFrame.cmbSP->SetItemHeight(-1, 16);
		_fillCombo(*UIConfigFrame.cmbSP);

		UIConfigFrame.spP2 = new CStatic;
		UIConfigFrame.spP2->Create(CONSTS.getTCHAR(LangCode::SplitSPConfigDesc), SS_SIMPLE | WS_VISIBLE, lblspP2Rect, UIConfigFrame.frame);
		UIConfigFrame.spP2->SetFont(UIFonts.displayFont);

		UIConfigFrame.scP1 = new CStatic;
		UIConfigFrame.scP1->Create(CONSTS.getTCHAR(LangCode::ToPress), SS_SIMPLE | WS_VISIBLE, lblscP1Rect, UIConfigFrame.frame);
		UIConfigFrame.scP1->SetFont(UIFonts.displayFont);

		UIConfigFrame.scCtrl = new HTHotkeyCheckBox;
		UIConfigFrame.scCtrl->createCheckBox(_T(""), WS_VISIBLE, hcbscCtrlRect, UIConfigFrame.frame, scCtrlID);

		UIConfigFrame.scShift = new HTHotkeyCheckBox;
		UIConfigFrame.scShift->createCheckBox(_T(""), WS_VISIBLE, hcbscShiftRect, UIConfigFrame.frame, scShiftID);

		UIConfigFrame.scAlt = new HTHotkeyCheckBox;
		UIConfigFrame.scAlt->createCheckBox(_T(""), WS_VISIBLE, hcbscAltRect, UIConfigFrame.frame, scAltID);

		UIConfigFrame.scCtrl->setBrother(UIConfigFrame.scShift, UIConfigFrame.scAlt);
		UIConfigFrame.scShift->setBrother(UIConfigFrame.scCtrl, UIConfigFrame.scAlt);
		UIConfigFrame.scAlt->setBrother(UIConfigFrame.scShift, UIConfigFrame.scCtrl);

		UIConfigFrame.cmbSC = new CComboBox;
		UIConfigFrame.cmbSC->Create(WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST, cmbSCRect, UIConfigFrame.frame, cmbSCID);
		UIConfigFrame.cmbSC->SetFont(UIFonts.textFont);
		UIConfigFrame.cmbSC->SetItemHeight(-1, 16);
		_fillCombo(*UIConfigFrame.cmbSC);

		UIConfigFrame.scP2 = new CStatic;
		UIConfigFrame.scP2->Create(CONSTS.getTCHAR(LangCode::SplitCustomConfigDescP1), SS_SIMPLE | WS_VISIBLE, lblscP2Rect, UIConfigFrame.frame);
		UIConfigFrame.scP2->SetFont(UIFonts.displayFont);

		UIConfigFrame.txtSC = new CEdit;
		UIConfigFrame.txtSC->Create(WS_VISIBLE|WS_BORDER|ES_NUMBER, txtSCRect, UIConfigFrame.frame, txtSCID);
		UIConfigFrame.txtSC->SetFont(UIFonts.textFont);

		UIConfigFrame.scP3 = new CStatic;
		UIConfigFrame.scP3->Create(CONSTS.getTCHAR(LangCode::SplitCustomConfigDescP2), SS_SIMPLE | WS_VISIBLE, lblscP3Rect, UIConfigFrame.frame);
		UIConfigFrame.scP3->SetFont(UIFonts.displayFont);

		UIConfigFrame.csP1 = new CStatic;
		UIConfigFrame.csP1->Create(CONSTS.getTCHAR(LangCode::ToPress), SS_SIMPLE | WS_VISIBLE, lblcsP1Rect, UIConfigFrame.frame);
		UIConfigFrame.csP1->SetFont(UIFonts.displayFont);

		UIConfigFrame.csCtrl = new HTHotkeyCheckBox;
		UIConfigFrame.csCtrl->createCheckBox(_T(""), WS_VISIBLE, hcbcsCtrlRect, UIConfigFrame.frame, csCtrlID);

		UIConfigFrame.csShift = new HTHotkeyCheckBox;
		UIConfigFrame.csShift->createCheckBox(_T(""), WS_VISIBLE, hcbcsShiftRect, UIConfigFrame.frame, csShiftID);

		UIConfigFrame.csAlt = new HTHotkeyCheckBox;
		UIConfigFrame.csAlt->createCheckBox(_T(""), WS_VISIBLE, hcbcsAltRect, UIConfigFrame.frame, csAltID);

		UIConfigFrame.csCtrl->setBrother(UIConfigFrame.csShift, UIConfigFrame.csAlt);
		UIConfigFrame.csShift->setBrother(UIConfigFrame.csCtrl, UIConfigFrame.csAlt);
		UIConfigFrame.csAlt->setBrother(UIConfigFrame.csShift, UIConfigFrame.csCtrl);

		UIConfigFrame.cmbCS = new CComboBox;
		UIConfigFrame.cmbCS->Create(WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST, cmbCSRect, UIConfigFrame.frame, cmbCSID);
		UIConfigFrame.cmbCS->SetFont(UIFonts.textFont);
		UIConfigFrame.cmbCS->SetItemHeight(-1, 16);
		_fillCombo(*UIConfigFrame.cmbCS);

		UIConfigFrame.csP2 = new CStatic;
		UIConfigFrame.csP2->Create(CONSTS.getTCHAR(LangCode::CombineConfigDesc), SS_SIMPLE | WS_VISIBLE, lblcsP2Rect, UIConfigFrame.frame);
		UIConfigFrame.csP2->SetFont(UIFonts.displayFont);

		UIConfigFrame.confirm = new CButton;
		UIConfigFrame.confirm->Create(CONSTS.getTCHAR(LangCode::ConfirmConfig),
			BS_PUSHBUTTON | BS_DEFPUSHBUTTON | WS_VISIBLE,
			btnConfirmRect,
			this, btnConfirmID);
		UIConfigFrame.confirm->SetFont(UIFonts.displayFont);

		UIConfigFrame.cancel = new CButton;
		UIConfigFrame.cancel->Create(CONSTS.getTCHAR(LangCode::CancelConfig),
			BS_PUSHBUTTON | WS_VISIBLE,
			btnCancelRect,
			this, btnCancelID);
		UIConfigFrame.cancel->SetFont(UIFonts.displayFont);
	}

	UICredits.question = new CStatic;
	UICredits.question->Create(CONSTS.getTCHAR(LangCode::QuestionGoto),
		SS_SIMPLE | WS_VISIBLE, lblQuestionRect, this);
	UICredits.question->SetFont(UIFonts.displayFont);
	
	UICredits.link = new CMFCLinkCtrl;
	UICredits.link->Create(CONSTS.getWeblink(),
		WS_VISIBLE, lblLinkRect,this, lblLinkID);
	UICredits.link->SetURL(CONSTS.getWeblink());
	UICredits.link->SizeToContent();
	UICredits.link->SetFont(UIFonts.hyperFont);
	
	_fillBlanks();
	_switchMode(FALSE);
	return 0;
}

VOID HTConfigWnd::_fillCombo(_In_ CComboBox& cmb) {
	TCHAR temp[2];
	temp[1] = 0;
	int result = 0;
	cmb.InitStorage(34,34*sizeof(temp));
	for (TCHAR i = _T('0'); i <= _T('9');i++) {
		temp[0] = i;
		result = cmb.AddString(temp);
	}
	for (TCHAR i = _T('A'); i <= _T('Z');i++) {
		temp[0] = i;
		cmb.AddString(temp);
	}
}

VOID HTConfigWnd::_fillBlanks() {
	TCHAR vs_key[2];
	vs_key[1] = 0;
	HTHotkeyInfo CONST * pInfo = &CONSTS.getHotkey(CONSTS.hk_S1);
	if (pInfo->ctrl) {
		UIConfigFrame.s1Ctrl->SetCheck(BST_CHECKED);
	}
	if (pInfo->alt) {
		UIConfigFrame.s1Alt->SetCheck(BST_CHECKED);
	}
	if (pInfo->shift) {
		UIConfigFrame.s1Shift->SetCheck(BST_CHECKED);
	}
	vs_key[0] = HTFuncs::keyCode2TCHAR(pInfo->vs_key);
	UIConfigFrame.cmbS1->SelectString(-1,vs_key);

	pInfo = &CONSTS.getHotkey(CONSTS.hk_S2);
	if (pInfo->ctrl) {
		UIConfigFrame.s2Ctrl->SetCheck(BST_CHECKED);
	}
	if (pInfo->alt) {
		UIConfigFrame.s2Alt->SetCheck(BST_CHECKED);
	}
	if (pInfo->shift) {
		UIConfigFrame.s2Shift->SetCheck(BST_CHECKED);
	}
	vs_key[0] = HTFuncs::keyCode2TCHAR(pInfo->vs_key);
	UIConfigFrame.cmbS2->SelectString(-1, vs_key);


	pInfo = &CONSTS.getHotkey(CONSTS.hk_SP);
	if (pInfo->ctrl) {
		UIConfigFrame.spCtrl->SetCheck(BST_CHECKED);
	}
	if (pInfo->alt) {
		UIConfigFrame.spAlt->SetCheck(BST_CHECKED);
	}
	if (pInfo->shift) {
		UIConfigFrame.spShift->SetCheck(BST_CHECKED);
	}
	vs_key[0] = HTFuncs::keyCode2TCHAR(pInfo->vs_key);
	UIConfigFrame.cmbSP->SelectString(-1, vs_key);


	pInfo = &CONSTS.getHotkey(CONSTS.hk_SC);
	if (pInfo->ctrl) {
		UIConfigFrame.scCtrl->SetCheck(BST_CHECKED);
	}
	if (pInfo->alt) {
		UIConfigFrame.scAlt->SetCheck(BST_CHECKED);
	}
	if (pInfo->shift) {
		UIConfigFrame.scShift->SetCheck(BST_CHECKED);
	}
	vs_key[0] = HTFuncs::keyCode2TCHAR(pInfo->vs_key);
	UIConfigFrame.cmbSC->SelectString(-1, vs_key);
	TCHAR num[MAX_PATH];
	_itot_s(pInfo->amount, num, MAX_PATH, 10);
	UIConfigFrame.txtSC->SetWindowText(num);

	pInfo = &CONSTS.getHotkey(CONSTS.hk_CS);
	if (pInfo->ctrl) {
		UIConfigFrame.csCtrl->SetCheck(BST_CHECKED);
	}
	if (pInfo->alt) {
		UIConfigFrame.csAlt->SetCheck(BST_CHECKED);
	}
	if (pInfo->shift) {
		UIConfigFrame.csShift->SetCheck(BST_CHECKED);
	}
	vs_key[0] = HTFuncs::keyCode2TCHAR(pInfo->vs_key);
	UIConfigFrame.cmbCS->SelectString(-1, vs_key);

	UIInfoFrame.noShow->SetCheck(CONSTS.getNoShow());
}

VOID HTConfigWnd::_switchMode(_In_ BOOL CONST configMode) {
	if (configMode) {
		UIConfigFrame.frame->ShowWindow(SW_SHOW);
		UIConfigFrame.confirm->ShowWindow(SW_SHOW);
		UIConfigFrame.cancel->ShowWindow(SW_SHOW);

		UIInfoFrame.config->ShowWindow(SW_HIDE);
		UIInfoFrame.cs->ShowWindow(SW_HIDE);
		UIInfoFrame.desc->ShowWindow(SW_HIDE);
		UIInfoFrame.noShow->ShowWindow(SW_HIDE);
		UIInfoFrame.play->ShowWindow(SW_HIDE);
		UIInfoFrame.s1->ShowWindow(SW_HIDE);
		UIInfoFrame.s2->ShowWindow(SW_HIDE);
		UIInfoFrame.sp->ShowWindow(SW_HIDE);
		UIInfoFrame.sc->ShowWindow(SW_HIDE);
		UIInfoFrame.uninstall->ShowWindow(SW_HIDE);
	}
	else {
		UIConfigFrame.frame->ShowWindow(SW_HIDE);
		UIConfigFrame.confirm->ShowWindow(SW_HIDE);
		UIConfigFrame.cancel->ShowWindow(SW_HIDE);

		UIInfoFrame.config->ShowWindow(SW_SHOW);
		UIInfoFrame.cs->ShowWindow(SW_SHOW);
		UIInfoFrame.desc->ShowWindow(SW_SHOW);
		UIInfoFrame.noShow->ShowWindow(SW_SHOW);
		UIInfoFrame.play->ShowWindow(SW_SHOW);
		UIInfoFrame.s1->ShowWindow(SW_SHOW);
		UIInfoFrame.s2->ShowWindow(SW_SHOW);
		UIInfoFrame.sp->ShowWindow(SW_SHOW);
		UIInfoFrame.sc->ShowWindow(SW_SHOW);
		UIInfoFrame.uninstall->ShowWindow(SW_SHOW);
	}
}

void HTConfigWnd::On_btnCancel_Clicked() {
	_switchMode(FALSE);
}

void HTConfigWnd::On_btnConfirm_Clicked() {
	_switchMode(FALSE);
}

void HTConfigWnd::On_btnUninstall_Clicked() {

}

void HTConfigWnd::On_btnConfig_Clicked() {
	_switchMode(TRUE);
}

void HTConfigWnd::On_btnPlay_Clicked() {
	::PostQuitMessage(0);
	CONSTS.setNoShow(UIInfoFrame.noShow->GetCheck());
	if (_isSlave == FALSE) {

	}
}

void HTConfigWnd::On_optNoShow_Clicked() {
	UIInfoFrame.noShow->SetCheck(!UIInfoFrame.noShow->GetCheck());
}

VOID HTConfigWnd::setSlave() {
	_isSlave = TRUE;
}