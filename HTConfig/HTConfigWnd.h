#pragma once

class HTConfigWnd : public CFrameWnd {
protected:
	static CRect CONST MainFrameRect;
	static CRect CONST ConfigFrameRect;
	static CRect CONST lblS1Rect;
	static CRect CONST lblS2Rect;
	static CRect CONST lblSCRect;
	static CRect CONST lblSPRect;
	static CRect CONST lblCSRect;
	static CRect CONST lblDescRect;
	static CRect CONST lblQuestionRect;
	static CRect CONST lblLinkRect;
	static CRect CONST btnPlayRect;
	static CRect CONST btnConfigRect;
	static CRect CONST btnConfirmRect;

	enum {

	};

	struct {
		CStatic * desc;
		CStatic * s1;
		CStatic * s2;
		CStatic * sc;
		CStatic * sp;
		CStatic * cs;
		CButton * play;
	}UIInfoFrame;

	struct {
		CButton * frame;
	}UIConfigFrame;;

	struct {
		CFont * displayFont; CFont * textFont;
	}UIFonts;

	struct {
		CStatic * question;
		CLinkCtrl * link;
	}UICredits;

public:
	DECLARE_DYNAMIC(HTConfigWnd)
	
	HTConfigWnd();
	virtual ~HTConfigWnd();

	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

