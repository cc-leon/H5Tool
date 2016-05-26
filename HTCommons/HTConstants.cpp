#include "stdafxCommons.h"
#include "HTConstants.h"

TCHAR CONST HTConstants::WIDECHAR_FILE_NAME[] = _T("widechar.chk");

HTConstants::HTConstants() {
}


HTConstants::~HTConstants() {
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
	for (LangCode i = (LangCode)0; i < LangCode::MAX; i = (LangCode)((int)i + 1)) {
		switch (i) {
		case LangCode::DialogTitle:
			_str[(int)i] = _T("英雄无敌5一键分兵工具设置向导 --天天英吧 制作");
			break;
		case LangCode::QuestionGoto:
			_str[(int)i] = _T("如果有任何疑问，请前往百度英雄无敌5贴吧进行询问。");
			break;
		case LangCode::Description:
			_str[(int)i] = _T("进入游戏后，选择你想要分兵的英雄，按下如下描述的快捷键"
				"即可将你英雄身上的第一支部队按照描述分割，填充英雄剩余部队空缺");
			break;
		case LangCode::Split1Desc:
			_str[(int)i] = _T("按下%s键分出来数量为1的部队。");
			break;
		case LangCode::Split2Desc:
			_str[(int)i] = _T("按下%s键分出来数量为2的部队。");
			break;
		case LangCode::SplitSPDesc:
			_str[(int)i] = _T("按下%s键分出来最大化施法输出的部队。");
			break;
		case LangCode::SplitCustomDesc:
			_str[(int)i] = _T("按下%s键分出来数量为%d（自定义）的部队。");
			break;
		case LangCode::CombineDesc:
			_str[(int)i] = _T("按下%s键合并所有分散部队");
			break;
		case LangCode::ToPress:
			_str[(int)i] = _T("按下");
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
		case LangCode::MAX:
			break;
		default:
			THROW_USER("Unhandled lang codes");
			break;
		}
	}
}

VOID HTConstants::_writeEnglish() {
	for (LangCode i = (LangCode)0; i < LangCode::MAX; i = (LangCode)((int)i + 1)) {
		switch (i) {
		case LangCode::DialogTitle:
			_str[(int)i] = _T("One-key Unit Split Tool for Heroes 5 TOTE configuration-- by Berein");
			break;
		case LangCode::QuestionGoto:
			_str[(int)i] = _T("Please proceed to Baidu Heroes5 forum for any enqueries.");
		case LangCode::Description:
			_str[(int)i] = _T("While you are in the game, select your hero, and use the shortcut key as described below.\n"
				"Then the first stack of your troop will be split accordingly，and fill up all empty stacks.");
			break;
		case LangCode::Split1Desc:
			_str[(int)i] = _T("Press %s key to split stack into the amount of 1.");
			break;
		case LangCode::Split2Desc:
			_str[(int)i] = _T("Press %s key to split stack into the amount of 2.");
			break;
		case LangCode::SplitSPDesc:
			_str[(int)i] = _T("Press %s key to split spellcasters stack to maximise spell output.");
			break;
		case LangCode::SplitCustomDesc:
			_str[(int)i] = _T("Press %s key to split stack into the amount of %d (which is customised).");
			break;
		case LangCode::CombineDesc:
			_str[(int)i] = _T("Press %s key to combine all duplicate stacks.");
			break;
		case LangCode::ToPress:
			_str[(int)i] = _T("Press");
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
		case LangCode::DontShow:
			_str[(int)i] = _T("Do not show this window the next time I play game.");
			break;
		case LangCode::StartGame:
			_str[(int)i] = _T("Play game");
			break;
		case LangCode::Unintall:
			_str[(int)i] = _T("Uninstall");
			break;
		case LangCode::Config:
			_str[(int)i] = _T("Change shortcuts");
			break;
		case LangCode::ConfirmConfig:
			_str[(int)i] = _T("Confirm");
			break;
		case LangCode::CancelConfig:
			_str[(int)i] = _T("Abandon");
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
	case HTConstants::FileVersion::THREE_ONE:
		_write31();
		break;
	case HTConstants::FileVersion::THREE_ZERO:
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

BOOL HTConstants::init(_In_ DWORD CONST procID, _In_ TCHAR CONST * CONST fullPath) {
	HRESULT hr = S_OK;
	TCHAR fileName[_1K];

	if (fullPath != NULL) {
		DWORD dwAttrib = ::GetFileAttributes(fullPath);
		if (dwAttrib == INVALID_FILE_ATTRIBUTES || (dwAttrib & FILE_ATTRIBUTE_DIRECTORY) == 0) {
			return FALSE;
		}

		hr = ::StringCchCopy(fileName,_1K, fullPath);
		if (FAILED(hr)) {
			THROW_API("StringCchCopy", hr, "");
		}
		HTFuncs::appendSlash(fileName);	
	}
	else {
		if (::GetCurrentDirectory(_1K, fileName) == 0) {
			THROW_API("GetCurrentDirectory", 0, "");
		}

		HTFuncs::goUpPath(fileName);
		HTFuncs::appendSlash(fileName);
	}

	hr = ::StringCchCat(fileName,_1K, _T("data\\"));
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
	
	if (procID != NULL) {
		HANDLE hProc = ::OpenProcess(PROCESS_ALL_ACCESS, NULL, procID);
		if (!VALID_HANDLE(hProc)) {
			THROW_API("OpenProcess", hProc, "");
		}
		if (::GetModuleFileNameEx(hProc, NULL, fileName, _1K) == 0) {
			THROW_API("GetModuleFileNameEx", 0, "");
		}
		::CloseHandle(hProc);
	}
	else if (fullPath != NULL) {
		DWORD dwAttrib = ::GetFileAttributes(fullPath);
		if (dwAttrib == INVALID_FILE_ATTRIBUTES || (dwAttrib & FILE_ATTRIBUTE_DIRECTORY) == 0) {
			return FALSE;
		}

		hr = ::StringCchCopy(fileName, _1K, fullPath);
		if (FAILED(hr)) {
			THROW_API("StringCchCopy", hr, "");
		}
		HTFuncs::appendSlash(fileName);
		hr = ::StringCchCat(fileName, _1K, _T("bin\\"));
		if (FAILED(hr)) {
			THROW_API("StringCchCat", hr, "");
		}
		hr = ::StringCchCat(fileName, _1K, H5_EXE_NAME);
		if (FAILED(hr)) {
			THROW_API("StringCchCat", hr, "");
		}
	}
	else {
		if (::GetCurrentDirectory(_1K, fileName) == 0) {
			THROW_API("GetCurrentDirectory", 0, "");
		}
		
		HTFuncs::appendSlash(fileName);

		hr = ::StringCchCat(fileName, _1K, H5_EXE_NAME);
		if (FAILED(hr)) {
			THROW_API("StringCchCat", hr, "");
		}
	}

	DWORD handle = NULL;
	DWORD infoSize = GetFileVersionInfoSize(fileName, &handle);
	if (infoSize == 0) {
		THROW_API("GetFileVersionInfoSize", 0, "");
	}
	LPVOID pBlock;
	pBlock = ALLOC(BYTE,infoSize);

	if (GetFileVersionInfo(fileName, handle, infoSize, pBlock) == 0) {
		THROW_API("GetFileVersionInfo", 0, "");
	}

	LPVOID ret = NULL;
	UINT len = 0;
	if (VerQueryValue(pBlock, _T("\\"), &ret, &len) == 0) {
		THROW_API("VerQueryValue", 0, "");
	}
	VS_FIXEDFILEINFO * info = reinterpret_cast<VS_FIXEDFILEINFO *>(ret);
	int ver = HIWORD(info->dwProductVersionMS);
	if (ver != 3) {
		return FALSE;
	}
	ver = LOWORD(info->dwProductVersionMS);
	if (ver == 1) {
		_ver = FileVersion::THREE_ONE;
	}
	else if (ver == 0) {
		_ver = FileVersion::THREE_ZERO;
	}
	else {
		return FALSE;
	}

	_writeConstants();
	return TRUE;
}

TCHAR CONST * HTConstants::getTCHAR(_In_ LangCode CONST code) {
	return _str[(int)code];
}

DWORD HTConstants::getDWORD(_In_ AddrCode CONST code) {
	return _addr[(int)code];
}