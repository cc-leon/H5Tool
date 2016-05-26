#include "stdafxConfig.h"
#include "HTHotkeyCheckBox.h"

IMPLEMENT_DYNAMIC(HTHotkeyCheckBox, CButton)

BEGIN_MESSAGE_MAP(HTHotkeyCheckBox, CButton)
	ON_CONTROL_REFLECT(BN_CLICKED, &HTHotkeyCheckBox::OnBnClicked)
END_MESSAGE_MAP()

HTHotkeyCheckBox::HTHotkeyCheckBox() {
}


HTHotkeyCheckBox::~HTHotkeyCheckBox() {
}

BOOL HTHotkeyCheckBox::createCheckBox(_In_ TCHAR CONST * CONST text,
	_In_ DWORD CONST dwStyle,
	_In_ CRect CONST& rect,
	_In_ CWnd * CONST pParentWnd,
	_In_ UINT nID)
{
	BOOL br = CButton::Create(text, dwStyle | BS_CHECKBOX, rect, pParentWnd, nID);
	return br;
}

VOID HTHotkeyCheckBox::setBrother(_In_ HTHotkeyCheckBox * CONST bro1, _In_ HTHotkeyCheckBox * CONST bro2) {
	_bro[0] = bro1;
	_bro[1] = bro2;
}

void HTHotkeyCheckBox::OnBnClicked() {
	// TODO: Add your control notification handler code here
	if (_bro[0]->GetCheck() != BST_UNCHECKED || _bro[1]->GetCheck() != BST_UNCHECKED) {
		SetCheck(!GetCheck());
	}
	else {
		SetCheck(BST_CHECKED);
	}
}
