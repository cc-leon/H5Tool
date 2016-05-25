#pragma once
class HTConfigWnd : public CFrameWnd {
public:
	DECLARE_DYNAMIC(HTConfigWnd)
	
	HTConfigWnd();
	virtual ~HTConfigWnd();

	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

