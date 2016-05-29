#include "stdafxCommons.h"
#include "HTConstants.h"

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
		case LangCode::SURE_UNINSTALL_PROMPRT:
			_str[(int)i] = _T("即将把“H5一键分兵工具”从电脑中删除。你的游戏本体不会受到影响。确认要继续吗？");
			break;
		case LangCode::H5RunningNoUninstall:
			_str[(int)i] = _T("H5游戏正在运行中，无法进行一键分兵软件的卸载。如想要卸载，请先退出H5游戏。");
			break;
		case LangCode::UninstallSuccessful:
			_str[(int)i] = _T("卸载完成。点击确认后本设置工具的文件也会消失。");
			break;
		case LangCode::InstallerTitle:
			_str[(int)i] = _T("英雄无敌5一键分兵工具安装程序 --天天英吧 制作");
			break;
		case LangCode::InstallerDesc:
			_str[(int)i] = _T("即将安装英雄无敌5一键分兵工具。下方是来自于制作者的声明，请先阅读之后点击继续。只有萝莉才会不看说明就直接点下一步。");
			break;
		case LangCode::InstallerAgreement:
			_str[(int)i] = _T("本工具制作目的是出于编程练习，而非正式软件，和英雄无敌官方也没有关系。"
				"因此，由于使用本软件造成的使用者电脑的各种物理反应，化学反应甚至核反应等等和本人一切无关。\n"
				"本工具因为其性质会一定程度导致英雄无敌5主程序不稳定，作者会尽力保证质量，但是对此没有任何义务。\n");
			break;
		case LangCode::InstallerFolderDectectSuccess:
			_str[(int)i] = _T("检测到英雄无敌5安装在如下文件夹里，如果你的英雄无敌5安装在其他位置，你也可以指定其他位置。");
			break;
		case LangCode::InstallerFolderDectectFailurePrompt:
			_str[(int)i] = _T("并没有检测到英雄无敌5的安装目录，请指定你英雄无敌5的位置。\n"
				"注意：请指定原始位置，不是H5主程序所在的那个Bin文件夹，而是在上一层。");
			break;
		case LangCode::InstallerInvalidDirectory:
			_str[(int)i] = _T("文件夹路径不正确，或者里面没有安装英雄无敌5。");
			break;
		case LangCode::InstallerWrongVersionPrompt:
			_str[(int)i] = _T("版本不正确。你现在的英雄无敌5的版本本工具并不支持，你可以继续安装，但是对此造成的任何后果制作者不负任何责任。");
			break;
		case LangCode::InstallerDirectory:
			_str[(int)i] = _T("安装路径：");
			break;
		case LangCode::InstallerBrowseDirectory:
			_str[(int)i] = _T("浏览...");
			break;
		case LangCode::InstallSuccess:
			_str[(int)i] = _T("成功安装，点击完成关闭安装程序。");
			break;
		case LangCode::InstallerButtonNext:
			_str[(int)i] = _T("下一步");
			break;
		case LangCode::InstallerButtonCancel:
			_str[(int)i] = _T("取消");
			break;
		case LangCode::InstallerQuitPrompt:
			_str[(int)i] = _T("你确定要退出“英雄无敌5一键分兵工具”的安装吗？");
			break;
		case LangCode::InstallerButtonFinish:
			_str[(int)i] = _T("完成");
			break;
		case LangCode::InstallerRunGameCheckBox:
			_str[(int)i] = _T("安装完成后运行一键分兵工具设置向导");
			break;
		case LangCode::InstallerInstalledError:
			_str[(int)i] = _T("一键分兵已经安装在这个文件夹里面。请选择一个没有一键分兵工具的安装位置。");
			break;
		case LangCode::ShortcutName:
			_str[(int)i] = _T("英雄无敌5一键分兵设置");
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
			_str[(int)i] = _T("One-key Unit Splitter configuration -- by Berein");
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
		case LangCode::SURE_UNINSTALL_PROMPRT:
			_str[(int)i] = _T("You're about to remove \"H5 TOTE One-key Unit Splitter \". You game will remain unchanged. Are you sure?");
		case LangCode::H5RunningNoUninstall:
			_str[(int)i] = _T("Unable to uninstall while H5 game is running. Stop it first before uninstalling.");
			break;
		case LangCode::UninstallSuccessful:
			_str[(int)i] = _T("Uninstallation successfully completed. Click OK then this configuration programm will be removed.");
			break;
		case LangCode::InstallerTitle:
			_str[(int)i] = _T("H5 TOTE One-key Unit Splitter --by Berein");
			break;
		case LangCode::InstallerDesc:
			_str[(int)i] = _T("One-key Unit Splitter is going to be installed on your computer. Please read the following agreements to proceed.");
			break;
		case LangCode::InstallerAgreement:
			_str[(int)i] = _T("This software is made purely due to the programming interest of the authoer. He is not obligated to do this, and this software is not related to Ubisoft by any means. \n"
				"Therefore, any physical reaction, chemical reation or even nulear reaction that cause damage to you and your property is none of the author's business, it is your own fault. \n"
				"Due to the nature of the programming work, this tool will unstablise the H5 game to a certain extent. The author will do his best to perfect his software, but he takes no responsibility\n");
			break;
		case LangCode::InstallerFolderDectectSuccess:
			_str[(int)i] = _T("H5 is detected in this folder. You can pinpoint another folder location if you wish,");
			break;
		case LangCode::InstallerFolderDectectFailurePrompt:
			_str[(int)i] = _T("No installed version of H5 is detected, you need to specify the location. \n"
				"Reminder: Give the install location, not the H5_Game.exe folder named \"Bin\".");
			break;
		case LangCode::InstallerInvalidDirectory:
			_str[(int)i] = _T("Invalid folder or there is no H5 game detected in the folder.");
			break;
		case LangCode::InstallerWrongVersionPrompt:
			_str[(int)i] = _T("Your H5 version is not supported by this tool. You may proceed at your own expense.");
			break;
		case LangCode::InstallerDirectory:
			_str[(int)i] = _T("H5 Folder:");
			break;
		case LangCode::InstallerBrowseDirectory:
			_str[(int)i] = _T("Browse...");
			break;
		case LangCode::InstallSuccess:
			_str[(int)i] = _T("Installation complete. Click finish to end this program.");
			break;
		case LangCode::InstallerButtonNext:
			_str[(int)i] = _T("Next");
			break;
		case LangCode::InstallerButtonCancel:
			_str[(int)i] = _T("Cancel");
			break;
		case LangCode::InstallerQuitPrompt:
			_str[(int)i] = _T("Are you sure to quit?");
			break;
		case LangCode::InstallerButtonFinish:
			_str[(int)i] = _T("Finish");
			break;
		case LangCode::InstallerRunGameCheckBox:
			_str[(int)i] = _T("Run the configuration tools after installation.");
			break;
		case LangCode::InstallerInstalledError:
			_str[(int)i] = _T("One-key Splitter Tool is already installed in this directory. Please choose another h5 directory without the tool.");
			break;
		case LangCode::ShortcutName:
			_str[(int)i] = _T("HoMM5 One-key Splitter Setting");
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

BOOL HTConstants::init(_In_ TCHAR CONST * CONST token, _In_ int CONST chinese ) {
	if (_started == TRUE) {
		THROW_USER("The HTConstants class is initiated twice!");
	}

	_started = TRUE;
	HRESULT hr = S_OK;
	TCHAR fileName[MAX_PATH];

	if (chinese != 0) {
		if (chinese > 0) {
			_lang = FileLanguage::CHINESE;
			_writeChinese();
		}
		else if (chinese < 0) {
			_lang = FileLanguage::ENGLISH;
			_writeEnglish();
		}
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
		hr = ::StringCchCat(fileName, _1K, Files::WIDECHAR_FILE_NAME);
		if (FAILED(hr)) {
			THROW_API("StringCchCat", hr, "");
		}

		if (::PathFileExists(fileName)) {
			_lang = FileLanguage::CHINESE;
		}
		else {
			_lang = FileLanguage::ENGLISH;
		}

		HTFuncs::getFullPath(Files::H5_EXE_NAME, fileName, MAX_PATH);

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
	}
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

HTHotkeyInfo& HTConstants::getHotkey(_In_ INT CONST code) {
	if (_started == FALSE) {
		THROW_USER("Attempt to call a method without calling init() first!");
	}
	return _hotkeyInfo[code];
}

VOID HTConstants::_loadHotkeyInfo() {
	CFile file;
	if (file.Open(Files::CONFIG_FILE_NAME,CFile::modeRead)) {
		BYTE * CONST buffer = ALLOC(BYTE, file.GetLength());
		HTHotkeyInfo * reader = reinterpret_cast<HTHotkeyInfo*>(buffer);

		file.Read(buffer, (UINT)file.GetLength());
		for (int i = 0; i < hk_MAX; i++) {
			_hotkeyInfo[i] = *reader;
			reader++;
		}
		FREE(buffer);
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

	CFile file(Files::CONFIG_FILE_NAME, CFile::modeWrite | CFile::modeCreate);
	file.Write(&_hotkeyInfo, sizeof(_hotkeyInfo));
	file.Close();
}

VOID HTConstants::_loadWeblink() {
	CFile file;
	TCHAR linkFile[MAX_PATH];
	HTFuncs::getFullPath(Files::WEBLINK_FILE_NAME, linkFile, MAX_PATH);
	if (file.Open(linkFile, CFile::modeRead)) {
		BYTE * buffer = ALLOC(BYTE, file.GetLength()+1);
		buffer[file.GetLength()] = 0;
		file.Read(buffer, (int)file.GetLength());
		TCHAR * newLink = ALLOC(TCHAR,file.GetLength() + 1);
		HTFuncs::char2TCHAR((char*)(buffer), newLink);
		_weblink = newLink;
		FREE(buffer);
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
	HTFuncs::getFullPath(Files::NOSHOW_FILE_NAME, noshowFile, MAX_PATH);
	if (file.Open(noshowFile, CFile::modeRead)) {
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
	HTFuncs::getFullPath(Files::NOSHOW_FILE_NAME, noshowFile, MAX_PATH);
	if (noShow) {
		CFile file(noshowFile, CFile::modeCreate|CFile::modeWrite);
		file.Close();
	}
	else {
		::DeleteFile(noshowFile);
	}
}