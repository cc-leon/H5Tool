#include "stdafxCommons.h"
#include "HTConstants.h"

TCHAR CONST HTConstants::WIDECHAR_FILE_NAME[] = _T("widechar.chk");
TCHAR CONST HTConstants::CONFIG_FILE_NAME[] = _T("HTHotkey.cfg");
TCHAR CONST HTConstants::WEBLINK_FILE_NAME[] = _T("Weblink.txt");
TCHAR CONST HTConstants::NOSHOW_FILE_NAME[] = _T("NoShow.cfg");
HTConstants::HTConstants():
	_started(FALSE)
{ }


HTConstants::~HTConstants() {
	::CloseHandle(_hEvent);
}

HTConstants& HTConstants::get() {
	static HTConstants instance;
	return instance;
}

VOID HTConstants::_write31() {
	for (AddrCode i = (AddrCode)0; i < AddrCode::MAX; i = (AddrCode)((int)i + 1)) {
		switch (i) {
		case AddrCode::Start:
			_addr[(int)i] = 0x005EBE74;
			break;
		case AddrCode::Len:
			_addr[(int)i] = 6;
			break;
		case AddrCode::Offset:
			_addr[(int)i] = 0x00000000;
			break;
		case AddrCode::MAX:
			break;
		default:
			THROW_USER("Unhandled addr codes");
			break;
		}
	}
}

VOID HTConstants::_write30() {
	for (AddrCode i = (AddrCode)0; i < AddrCode::MAX; i = (AddrCode)((int)i + 1)) {
		switch (i) {
		case AddrCode::Start:
			break;
		case AddrCode::Len:
			break;
		case AddrCode::Offset:
			break;
		case AddrCode::MAX:
			break;
		default:
			THROW_USER("Unhandled addr codes");
			break;
		}
	}
}

VOID HTConstants::_writeChinese() {
	for (int i = 0; (int)i < (int)LangCode::MAX; i++) {
		switch ((LangCode)i) {
		case LangCode::DialogTitle:
			_str[(int)i] = _T("英雄无敌5一键分兵工具设置向导 --天天英吧 制作");
			break;
		case LangCode::QuestionGoto:
			_str[(int)i] = _T("如果有任何疑问，请前往百度英雄无敌5贴吧进行询问。");
			break;
		case LangCode::Description:
			_str[(int)i] = _T("进入游戏后，选择你想要分兵的英雄，按下如下描述的快捷键"
				"即可将你英雄身上的第一支部队按照描述分割，填充英雄剩余部队空缺。");
			break;
		case LangCode::Split1Desc:
			_str[(int)i] = _T("1. 按下 %s 键分出来数量为1的部队。");
			break;
		case LangCode::Split2Desc:
			_str[(int)i] = _T("2. 按下 %s 键分出来数量为2的部队。");
			break;
		case LangCode::SplitSPDesc:
			_str[(int)i] = _T("3. 按下 %s 键分出来最大化施法输出的部队。");
			break;
		case LangCode::SplitCustomDesc:
			_str[(int)i] = _T("4. 按下 %s 键分出来数量为%d（自定义）的部队。");
			break;
		case LangCode::CombineDesc:
			_str[(int)i] = _T("5. 按下 %s 键合并所有同种类部队。");
			break;
		case LangCode::ToPress:
			_str[(int)i] = _T("按下");
			break;
		case LangCode::ConfigDescTile:
			_str[(int)i] = _T("修改按键设定");
			break;
		case LangCode::Split1ConfigDesc:
			_str[(int)i] = _T("分出来数量为1的部队。");
			break;
		case LangCode::Split2ConfigDesc:
			_str[(int)i] = _T("分出来数量为2的部队。");
			break;
		case LangCode::SplitSPConfigDesc:
			_str[(int)i] = _T("分出来最大化施法输出的部队。");
			break;
		case LangCode::SplitCustomConfigDescP1:
			_str[(int)i] = _T("分出来数量为");
			break;
		case LangCode::SplitCustomConfigDescP2:
			_str[(int)i] = _T("的部队。");
			break;
		case LangCode::CombineConfigDesc:
			_str[(int)i] = _T("合并所有同种类部队。");
			break;
		case LangCode::DontShow:
			_str[(int)i] = _T("以后游戏启动的时候不再显示这个设置工具。");
			break;
		case LangCode::StartGame:
			_str[(int)i] = _T("开始游戏");
			break;
		case LangCode::Unintall:
			_str[(int)i] = _T("卸载本工具");
			break;
		case LangCode::Config:
			_str[(int)i] = _T("修改按键设置");
			break;
		case LangCode::ConfirmConfig:
			_str[(int)i] = _T("确认修改");
			break;
		case LangCode::CancelConfig:
			_str[(int)i] = _T("放弃修改");
			break;
		case LangCode::DuplicateInstWarning:
			_str[(int)i] = _T("无法同时打开两个h5的进程或者设置程序。");
			break;
		case LangCode::MAX:
			break;
		default:
			THROW_USER("Unhandled lang codes");
			break;
		}
	}
}

VOID HTConstants::_writeEnglish() {
	for (int i = 0; i < (int)LangCode::MAX; i++) {
		switch ((LangCode)i) {
		case LangCode::DialogTitle:
			_str[(int)i] = _T("One-key Stack Split configuration -- by Berein");
			break;
		case LangCode::QuestionGoto:
			_str[(int)i] = _T("Please proceed to Baidu Heroes5 forum for any enqueries.");
			break;
		case LangCode::Description:
			_str[(int)i] = _T("While you are in the game, select your hero, and use the shortcut key as described below.  "
				"Then the first stack of your troop will be split accordingly，and fill up all empty stacks.");
			break;
		case LangCode::Split1Desc:
			_str[(int)i] = _T("1. Press %s key to split stack into the amount of 1.");
			break;
		case LangCode::Split2Desc:
			_str[(int)i] = _T("2. Press %s key to split stack into the amount of 2.");
			break;
		case LangCode::SplitSPDesc:
			_str[(int)i] = _T("3. Press %s key to split spellcasters stack to maximise spell output.");
			break;
		case LangCode::SplitCustomDesc:
			_str[(int)i] = _T("4. Press %s key to split stack into the amount of %d (which is customised).");
			break;
		case LangCode::CombineDesc:
			_str[(int)i] = _T("5. Press %s key to combine all duplicate stacks.");
			break;
		case LangCode::ToPress:
			_str[(int)i] = _T("Press");
			break;
		case LangCode::ConfigDescTile:
			_str[(int)i] = _T("Redefine the shortcut key combinations");
			break;
		case LangCode::Split1ConfigDesc:
			_str[(int)i] = _T("to split stack into the amount of 1.");
			break;
		case LangCode::Split2ConfigDesc:
			_str[(int)i] = _T("to split stack into the amount of 2.");
			break;
		case LangCode::SplitSPConfigDesc:
			_str[(int)i] = _T("to split spellcasters stack to maximise spell output.");
			break;
		case LangCode::SplitCustomConfigDescP1:
			_str[(int)i] = _T("to split stack into the amount of");
			break;
		case LangCode::SplitCustomConfigDescP2:
			_str[(int)i] = _T(".");
			break;
		case LangCode::CombineConfigDesc:
			_str[(int)i] = _T("to combine all duplicate stacks.");
			break;
		case LangCode::DontShow:
			_str[(int)i] = _T("Don't show this window before game launch.");
			break;
		case LangCode::StartGame:
			_str[(int)i] = _T("Play game");
			break;
		case LangCode::Unintall:
			_str[(int)i] = _T("Uninstall");
			break;
		case LangCode::Config:
			_str[(int)i] = _T("Change Keys");
			break;
		case LangCode::ConfirmConfig:
			_str[(int)i] = _T("Confirm");
			break;
		case LangCode::CancelConfig:
			_str[(int)i] = _T("Abandon");
			break;
		case LangCode::DuplicateInstWarning:
			_str[(int)i] = _T("You cannot open more than one instance of the H5 game or this tool.");
			break;
		case LangCode::MAX:
			break;
		default:
			THROW_USER("Unhandled lang codes");
			break;
		}
	}
}

VOID HTConstants::_writeConstants() {
	switch (_ver) {
	case FileVersion::THREE_ONE:
		_write31();
		break;
	case FileVersion::THREE_ZERO:
		_write30();
		break;
	default:
		THROW_USER("Unhandled version code");
		break;
	}

	switch (_lang)
	{
	case HTConstants::FileLanguage::ENGLISH:
		_writeEnglish();
		break;
	case HTConstants::FileLanguage::CHINESE:
		_writeChinese();
		break;
	default:
		THROW_USER("Unhandled languague code");
		break;
	}
}

BOOL HTConstants::init(_In_ TCHAR CONST * CONST token, _In_ BOOL CONST chinese) {
	if (_started == TRUE) {
		THROW_USER("The HTConstants class is initiated twice!");
	}

	_started = TRUE;
	HRESULT hr = S_OK;
	TCHAR fileName[MAX_PATH];

	if (chinese) {
		_lang = FileLanguage::CHINESE;
	}
	else {
		if (::GetCurrentDirectory(_1K, fileName) == 0) {
			THROW_API("GetCurrentDirectory", 0, "");
		}
		HTFuncs::goUpPath(fileName);
		HTFuncs::appendSlash(fileName);

		hr = ::StringCchCat(fileName, _1K, _T("data\\"));
		if (FAILED(hr)) {
			THROW_API("StringCchCat", hr, "");
		}
		hr = ::StringCchCat(fileName, _1K, WIDECHAR_FILE_NAME);
		if (FAILED(hr)) {
			THROW_API("StringCchCat", hr, "");
		}

		if (::PathFileExists(fileName)) {
			_lang = FileLanguage::CHINESE;
		}
		else {
			_lang = FileLanguage::ENGLISH;
		}
	}
	
	HTFuncs::getFullPath(H5_EXE_NAME, fileName, MAX_PATH);
	
	DWORD hVer = 0, lVer = 0;
	HTFuncs::getFileVersion(fileName, hVer, lVer);
	if (hVer != 3) {
		return FALSE;
	}
	
	if (lVer == 1) {
		_ver = FileVersion::THREE_ONE;
	}
	else if (lVer == 0) {
		_ver = FileVersion::THREE_ZERO;
	}
	else {
		return FALSE;
	}

	_writeConstants();
	_loadHotkeyInfo();
	_loadWeblink();

	_hEvent = ::CreateEvent(NULL, FALSE, FALSE, token);
	if (::GetLastError() == ERROR_ALREADY_EXISTS) {
		::AfxMessageBox(getTCHAR(LangCode::DuplicateInstWarning));
		return FALSE;
	}

	return TRUE;
}

TCHAR CONST * HTConstants::getTCHAR(_In_ LangCode CONST code) const {
	if (_started == FALSE) {
		THROW_USER("Attempt to call a method without calling init() first!");
	}
	return _str[(int)code];
}

DWORD HTConstants::getDWORD(_In_ AddrCode CONST code) const {
	if (_started == FALSE) {
		THROW_USER("Attempt to call a method without calling init() first!");
	}
	return _addr[(int)code];
}

HTHotkeyInfo& HTConstants::getHotkey(_In_ INT CONST code) {
	if (_started == FALSE) {
		THROW_USER("Attempt to call a method without calling init() first!");
	}
	return _hotkeyInfo[code];
}

VOID HTConstants::_loadHotkeyInfo() {
	CFile file;
	if (file.Open(CONFIG_FILE_NAME, CFile::typeBinary | CFile::modeRead)) {
		BYTE * CONST buffer = ALLOC(BYTE, file.GetLength());
		HTHotkeyInfo * reader = reinterpret_cast<HTHotkeyInfo*>(buffer);

		file.Read(buffer, (UINT)file.GetLength());
		for (int i = 0; i < hk_MAX; i++) {
			_hotkeyInfo[i] = *reader;
			reader++;
		}
	}
	else {
		_generateDefaultHotkeyInfo();
	}
}

VOID HTConstants::_generateDefaultHotkeyInfo() {
	::ZeroMemory(_hotkeyInfo, sizeof(_hotkeyInfo));
	_hotkeyInfo[hk_S1].ctrl = TRUE;
	_hotkeyInfo[hk_S1].vs_key = HTFuncs::TCHAR2keycode(_T('1'));
	_hotkeyInfo[hk_S2].ctrl = TRUE;
	_hotkeyInfo[hk_S2].vs_key = HTFuncs::TCHAR2keycode(_T('2'));
	_hotkeyInfo[hk_SP].ctrl = TRUE;
	_hotkeyInfo[hk_SP].vs_key = HTFuncs::TCHAR2keycode(_T('s'));
	_hotkeyInfo[hk_SC].ctrl = TRUE;
	_hotkeyInfo[hk_SC].vs_key = HTFuncs::TCHAR2keycode(_T('a'));
	_hotkeyInfo[hk_SC].amount = 4;
	_hotkeyInfo[hk_CS].ctrl = TRUE;
	_hotkeyInfo[hk_CS].vs_key = HTFuncs::TCHAR2keycode(_T('c'));
}

VOID HTConstants::saveHotkeyInfo() {
	if (_started == FALSE) {
		THROW_USER("Attempt to call a method without calling init() first!");
	}

	CFile file(CONFIG_FILE_NAME, CFile::typeBinary | CFile::modeWrite | CFile::modeCreate);
	file.Write(&_hotkeyInfo, sizeof(_hotkeyInfo));
	file.Close();
}

VOID HTConstants::_loadWeblink() {
	CFile file;
	TCHAR linkFile[MAX_PATH];
	HTFuncs::getFullPath(WEBLINK_FILE_NAME, linkFile, MAX_PATH);
	if (file.Open(linkFile, CFile::typeUnicode | CFile::modeRead)) {
		BYTE * buffer = ALLOC(BYTE, file.GetLength()+1);
		buffer[file.GetLength()] = 0;
		file.Read(buffer, (int)file.GetLength());
		TCHAR * newLink = ALLOC(TCHAR,file.GetLength() + 1);
		HTFuncs::char2TCHAR((char*)(buffer), newLink);
		_weblink = newLink;
	}
	else {
		_generateDefaultWeblink();
	}
}

VOID HTConstants::_generateDefaultWeblink() {
	_weblink = _T("http://tieba.baidu.com/f?kw=heroes5");
}

TCHAR CONST * HTConstants::getWeblink() const {
	if (_started == FALSE) {
		THROW_USER("Attempt to call a method without calling init() first!");
	}
	return _weblink;
}

FileVersion HTConstants::getFileVersion() const {
	if (_started == FALSE) {
		THROW_USER("Attempt to call a method without calling init() first!");
	}
	return _ver;
}

BOOL HTConstants::getNoShow() {
	if (_started == FALSE) {
		THROW_USER("Attempt to call a method without calling init() first!");
	}
	CFile file;
	TCHAR noshowFile[MAX_PATH];
	HTFuncs::getFullPath(NOSHOW_FILE_NAME, noshowFile, MAX_PATH);
	if (file.Open(noshowFile, CFile::modeRead | CFile::typeBinary)) {
		file.Close();
		return TRUE;
	}
	else {
		return FALSE;
	}
}

VOID HTConstants::setNoShow(_In_ BOOL CONST noShow) {
	if (_started == FALSE) {
		THROW_USER("Attempt to call a method without calling init() first!");
	}
	TCHAR noshowFile[MAX_PATH];
	HTFuncs::getFullPath(NOSHOW_FILE_NAME, noshowFile, MAX_PATH);
	if (noShow) {
		CFile file(noshowFile, CFile::modeCreate|CFile::modeWrite);
		file.Close();
	}
	else {
		::DeleteFile(noshowFile);
	}
}