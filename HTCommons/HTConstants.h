#pragma once

#define _1K 0x400
#define _4K 0x1000

#include "HTHotkeyInfo.h"

TCHAR CONST PIPE_NAME[] = _T("\\\\.\\pipe\\Idiots!!");
TCHAR CONST H5_EXE_NAME[] = _T("H5_Game.exe");;

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
	MAX
};

enum class AddrCode{
	Start,
	Len,
	Offset,
	MAX
};

enum class FileVersion {
	THREE_ONE,
	THREE_ZERO
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
	static TCHAR CONST WIDECHAR_FILE_NAME[]; 
	static TCHAR CONST CONFIG_FILE_NAME[];
	static TCHAR CONST WEBLINK_FILE_NAME[];
	static TCHAR CONST NOSHOW_FILE_NAME[];

	enum class FileLanguage {
		ENGLISH,
		CHINESE,
	} _lang;

	struct LANGANDCODEPAGE {
		WORD wLanguage;
		WORD wCodePage;
	} *lpTranslate;

	FileVersion _ver;
	DWORD _addr[(int)AddrCode::MAX];
	TCHAR CONST * _str[(int)LangCode::MAX];
	TCHAR CONST * _weblink;
	HTHotkeyInfo _hotkeyInfo[hk_MAX];
	BOOL _started;
	BOOL _localedSynced;
	HANDLE _hEvent;

	VOID _write31();
	VOID _write30();
	VOID _writeChinese();
	VOID _writeEnglish();
	VOID _writeConstants();
	VOID _loadHotkeyInfo();
	VOID _loadWeblink();
	VOID _generateDefaultHotkeyInfo();
	VOID _generateDefaultWeblink();

public:

	static HTConstants& get();
	BOOL init(_In_ TCHAR CONST * CONST token, _In_ BOOL CONST chinese = FALSE);
	TCHAR CONST * getTCHAR(_In_ LangCode CONST code) const;
	DWORD getDWORD(_In_ AddrCode CONST code) const;
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