#pragma once
#include "afxwin.h"
class HTHotkeyCheckBox : public CButton {
protected:
	HTHotkeyCheckBox * _bro[2];
public:
	BOOL createCheckBox(_In_ TCHAR CONST * CONST text,
		_In_ DWORD CONST dwStyle,
		_In_ CRect CONST& rect,
		_In_ CWnd * CONST pParentWnd,
		_In_ UINT nID);
	VOID setBrother(_In_ HTHotkeyCheckBox * CONST bro1, _In_ HTHotkeyCheckBox * CONST bro2);

	HTHotkeyCheckBox();
	virtual ~HTHotkeyCheckBox();

	DECLARE_DYNAMIC(HTHotkeyCheckBox)

	DECLARE_MESSAGE_MAP()

	afx_msg void OnBnClicked();
};

