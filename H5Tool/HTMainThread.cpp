#include "stdafxMainThread.h"
#include "HTMainThread.h"

BEGIN_MESSAGE_MAP(HTMainThread, CWinApp)
END_MESSAGE_MAP()

HTMainThread::HTMainThread() {
}

HTMainThread::~HTMainThread() {
}

BOOL HTMainThread::InitInstance() {
	CWinApp::InitInstance();

	CFrameWnd * tempWnd = new CFrameWnd;
	tempWnd->Create(NULL, NULL);
	m_pMainWnd = tempWnd;

	return TRUE;
}

UINT WINAPIV subThread(_Inout_ LPVOID lpParam) {
	return NULL;
}

HTMainThread mainThread;