#pragma once

#define _1K 0x400
#define _4K 0x1000

#include "FileVersion.h"
#include "HTHotkeyInfo.h"

enum class LangCode {
	DialogTitle,
	QuestionGoto,
	Description,
	Split1Desc,
	Split2Desc,
	SplitSPDesc,
	SplitCustomDesc,
	CombineDesc,
	ConfigDescTile,
	ToPress,
	Split1ConfigDesc,
	Split2ConfigDesc,
	SplitSPConfigDesc,
	SplitCustomConfigDescP1,
	SplitCustomConfigDescP2,
	CombineConfigDesc,
	DontShow,
	StartGame,
	Unintall,
	Config,
	ConfirmConfig,
	CancelConfig,
	DuplicateInstWarning,
	SURE_UNINSTALL_PROMPRT,
	H5RunningNoUninstall,
	UninstallSuccessful,
	InstallerTitle,
	InstallerDesc,
	InstallerAgreement,
	InstallerFolderDectectSuccess,
	InstallerFolderDectectFailurePrompt,
	InstallerInvalidDirectory,
	InstallerWrongVersionPrompt,
	InstallerDirectory,
	InstallerBrowseDirectory,
	InstallSuccess,
	InstallerButtonNext,
	InstallerButtonCancel,
	InstallerQuitPrompt,
	InstallerButtonFinish,
	InstallerRunGameCheckBox,
	InstallerInstalledError,
	ShortcutName,
	MAX
};

class HTConstants {
public:
	enum {
		hk_S1,
		hk_S2,
		hk_SP,
		hk_SC,
		hk_CS,
		hk_MAX
	};

private:

	enum class FileLanguage {
		ENGLISH,
		CHINESE,
	} _lang;

	struct LANGANDCODEPAGE {
		WORD wLanguage;
		WORD wCodePage;
	} *lpTranslate;

	FileVersion _ver;
	TCHAR CONST * _str[(int)LangCode::MAX];
	TCHAR CONST * _weblink;
	HTHotkeyInfo _hotkeyInfo[hk_MAX];
	BOOL _started;
	HANDLE _hEvent;

	VOID _writeChinese();
	VOID _writeEnglish();
	VOID _writeConstants();
	VOID _loadHotkeyInfo();
	VOID _loadWeblink();
	VOID _generateDefaultHotkeyInfo();
	VOID _generateDefaultWeblink();

public:

	static HTConstants& get();
	BOOL init(_In_ TCHAR CONST * CONST token, _In_ int CONST chinese = 0);
	TCHAR CONST * getTCHAR(_In_ LangCode CONST code) const;
	HTHotkeyInfo& getHotkey(_In_ INT CONST code);
	VOID saveHotkeyInfo();
	TCHAR CONST * getWeblink() const;
	FileVersion getFileVersion() const;
	BOOL getNoShow();
	VOID setNoShow(_In_ BOOL CONST noShow);
	
	HTConstants();
	~HTConstants();
};

#define CONSTS HTConstants::get()