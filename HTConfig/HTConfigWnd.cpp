#include "stdafxConfig.h"
#include "HTConfigWnd.h"

CRect CONST HTConfigWnd::MainFrameRect(300, 200, 900, 600);
CRect CONST HTConfigWnd::ConfigFrameRect(300, 200, 900, 600);
CRect CONST HTConfigWnd::lblS1Rect(300, 200, 900, 600);
CRect CONST HTConfigWnd::lblS2Rect(300, 200, 900, 600);
CRect CONST HTConfigWnd::lblSCRect(300, 200, 900, 600);
CRect CONST HTConfigWnd::lblSPRect(300, 200, 900, 600);
CRect CONST HTConfigWnd::lblCSRect(300, 200, 900, 600);
CRect CONST HTConfigWnd::lblDescRect(10, 10, 570, 100);
CRect CONST HTConfigWnd::lblQuestionRect(300, 200, 900, 600);
CRect CONST HTConfigWnd::lblLinkRect(300, 200, 900, 600);
CRect CONST HTConfigWnd::btnPlayRect(300, 200, 900, 600);
CRect CONST HTConfigWnd::btnConfigRect(300, 200, 900, 600);
CRect CONST HTConfigWnd::btnConfirmRect(300, 200, 900, 600);
IMPLEMENT_DYNAMIC ( HTConfigWnd, CFrameWnd)

BEGIN_MESSAGE_MAP  (HTConfigWnd, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()


HTConfigWnd::HTConfigWnd() {
}


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

	// TODO:  Add your specialized creation code here
	
	UIFonts.displayFont = new CFont();
	UIFonts.displayFont->CreateFont(
		20,                            // Height
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
		16,                            // Height
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
	SetFont(UIFonts.displayFont);

	UIInfoFrame.desc = new CStatic;
	UIInfoFrame.desc->Create(_T("static"),
		 WS_VISIBLE,
		lblDescRect,
		this, NULL);
	UIInfoFrame.desc->SetWindowText(CONSTS.getTCHAR(LangCode::Description));
	UIInfoFrame.desc->SetFont(UIFonts.displayFont);
	return 0;
}
