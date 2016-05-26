#pragma once

#include <afxlinkctrl.h>
#include "HTHotkeyCheckBox.h"

class HTConfigWnd : public CFrameWnd {
public:
	static INT CONST ID_START = 0x1000;
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
	static CRect CONST btnUninstallRect;
	static CRect CONST optNoShowRect;
	static CRect CONST btnConfirmRect;
	static CRect CONST btnCancelRect;
	static CRect CONST grpConfigRect;
	static CRect CONST lbls1P1Rect;
	static CRect CONST lbls2P1Rect;
	static CRect CONST lblscP1Rect;
	static CRect CONST lblspP1Rect;
	static CRect CONST lblcsP1Rect;
	static CRect CONST lbls1P2Rect;
	static CRect CONST lbls2P2Rect;
	static CRect CONST lblscP2Rect;
	static CRect CONST lblspP2Rect;
	static CRect CONST lblcsP2Rect;
	static CRect CONST lblscP3Rect;
	static CRect CONST lblCtrlRect;
	static CRect CONST lblShiftRect;
	static CRect CONST lblAltRect;
	static CRect CONST hcbs1CtrlRect;
	static CRect CONST hcbs1ShiftRect;
	static CRect CONST hcbs1AltRect;
	static CRect CONST hcbs2CtrlRect;
	static CRect CONST hcbs2ShiftRect;
	static CRect CONST hcbs2AltRect;
	static CRect CONST hcbscCtrlRect;
	static CRect CONST hcbscShiftRect;
	static CRect CONST hcbscAltRect;
	static CRect CONST hcbspCtrlRect;
	static CRect CONST hcbspShiftRect;
	static CRect CONST hcbspAltRect;
	static CRect CONST hcbcsShiftRect;
	static CRect CONST hcbcsCtrlRect;
	static CRect CONST hcbcsAltRect;
	static CRect CONST cmbS1Rect;
	static CRect CONST cmbS2Rect;
	static CRect CONST cmbSCRect;
	static CRect CONST cmbSPRect;
	static CRect CONST cmbCSRect;
	static CRect CONST txtSCRect;
	
	enum {
		btnPlayID = ID_START + 1,
		btnConfigID,
		btnUninstallID,
		optNoShowID,
		lblLinkID,
		btnConfirmID, btnCancelID,
		s1CtrlID, s1ShiftID, s1AltID,
		s2CtrlID, s2ShiftID, s2AltID,
		scCtrlID, scShiftID, scAltID,
		spCtrlID, spShiftID, spAltID,
		csCtrlID, csShiftID, csAltID,
		cmbS1ID, cmbS2ID, cmbSCID, cmbSPID, cmbCSID,
		txtSCID,
	};

	struct {
		CStatic * desc;
		CStatic * s1;
		CStatic * s2;
		CStatic * sc;
		CStatic * sp;
		CStatic * cs;
		CButton * play;
		CButton * config;
		CButton * uninstall;
		CButton * noShow;
	}UIInfoFrame;

	struct {
		CStatic * s1P1;
		CStatic * s2P1;
		CStatic * scP1;
		CStatic * spP1;
		CStatic * csP1;
		CStatic * s1P2;
		CStatic * s2P2;
		CStatic * scP2;
		CStatic * spP2;
		CStatic * csP2;
		CStatic * scP3;
		
		CStatic * ctrl;
		CStatic * shift;
		CStatic * alt;

		HTHotkeyCheckBox * s1Ctrl;
		HTHotkeyCheckBox * s1Shift;
		HTHotkeyCheckBox * s1Alt;
		HTHotkeyCheckBox * s2Ctrl;
		HTHotkeyCheckBox * s2Shift;
		HTHotkeyCheckBox * s2Alt;
		HTHotkeyCheckBox * scCtrl;
		HTHotkeyCheckBox * scShift;
		HTHotkeyCheckBox * scAlt;
		HTHotkeyCheckBox * spCtrl;
		HTHotkeyCheckBox * spShift;
		HTHotkeyCheckBox * spAlt;
		HTHotkeyCheckBox * csCtrl;
		HTHotkeyCheckBox * csShift;
		HTHotkeyCheckBox * csAlt;

		CComboBox *cmbS1;
		CComboBox *cmbS2;
		CComboBox *cmbSC;
		CComboBox *cmbSP;
		CComboBox *cmbCS;

		CEdit * txtSC;
		CButton * frame;
		CButton * confirm;
		CButton * cancel;
	}UIConfigFrame;

	struct {
		CFont * displayFont; CFont * textFont;
		CFont * hyperFont;
	}UIFonts;

	struct {
		CStatic * question;
		CMFCLinkCtrl * link;
	}UICredits;
	
	BOOL _isSlave;

	static VOID _fillCombo(_In_ CComboBox& cmb);
	VOID _fillBlanks();
	VOID _switchMode(_In_ BOOL CONST configMode);
public:
	DECLARE_DYNAMIC(HTConfigWnd)
	
	VOID setSlave();

	HTConfigWnd();
	virtual ~HTConfigWnd();

	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void On_btnCancel_Clicked();
	afx_msg void On_btnConfirm_Clicked();
	afx_msg void On_btnUninstall_Clicked();
	afx_msg void On_btnConfig_Clicked();
	afx_msg void On_btnPlay_Clicked();
	afx_msg void On_optNoShow_Clicked();
};

