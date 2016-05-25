#include "stdafxConfig.h"
#include "HTConfigWnd.h"

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
	cs.cx = 500;
	cs.cy = 400;
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

	return 0;
}
