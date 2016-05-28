#pragma once
#include <afxlinkctrl.h>

// HTInstallWnd frame

class HTInstallWnd : public CFrameWnd {
	DECLARE_DYNCREATE(HTInstallWnd)
protected:
	static CONST CRect FrameRect;
	static CONST CRect lblDescRect;
	static CONST CRect txtAgreementRect;
	static CONST CRect lblQueryRect;
	static CONST CRect lblWeblinkRect;
	static CONST CRect btnNextRect;
	static CONST CRect btnCancelRect;
	static CONST CRect btnBrowseRect;
	static CONST CRect txtDirRect;
	static CONST CRect lblDirRect;
	static CONST CRect optRunGameRect;
	static INT CONST ID_START = 0x2000;
	enum {
		txtAgreementID = ID_START+1,
		btnNextID,
		btnCancelID,
		btnBrowseID,
		txtDirID,
		optRunGameID,
	};

	enum class Stage {
		one, two, three,
	} _stage;

	CStatic *lblDesc, *lblDir, *lblQuery;
	CButton *optRunGame, *btnNext, *btnCancel, *btnBrowse;
	CEdit *txtDir, *txtAgreement;
	CMFCLinkCtrl * lblWeblink;
	struct {
		CFont * displayFont; CFont * textFont;
		CFont * hyperFont;
	}UIFonts;

	VOID _copyFiles(_In_ TCHAR CONST * CONST targetDir);

public:
	HTInstallWnd(); 
	virtual ~HTInstallWnd();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	DECLARE_MESSAGE_MAP()
	afx_msg void On_btnCancel_Clicked();
	afx_msg void On_btnNext_Clicked();
	afx_msg void On_btnBrowse_Clicked();
	afx_msg void On_optRunGame_Clicked();
};


