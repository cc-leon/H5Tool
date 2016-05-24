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
	return TRUE;
}

HTMainThread mainThread;