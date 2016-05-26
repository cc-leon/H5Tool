#pragma once

#define _1K 0x400
#define _4K 0x1000

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
	ToPress,
	Split1ConfigDesc,
	Split2ConfigDesc,
	SplitSPConfigDesc,
	SplitCustomConfigDescP1,
	SplitCustomConfigDescP2,
	DontShow,
	StartGame,
	Unintall,
	Config,
	ConfirmConfig,
	CancelConfig,
	MAX
};

enum class AddrCode{
	Start,
	Len,
	Offset,
	MAX
};

class HTConstants {
private:
	static TCHAR CONST WIDECHAR_FILE_NAME[]; 

	enum class FileVersion {
		THREE_ONE,
		THREE_ZERO
	} _ver;

	enum class FileLanguage {
		ENGLISH,
		CHINESE,
	} _lang;

	DWORD _addr[(int)AddrCode::MAX];
	TCHAR CONST * _str[(int)AddrCode::MAX];

	struct LANGANDCODEPAGE {
		WORD wLanguage;
		WORD wCodePage;
	} *lpTranslate;


	VOID _write31();
	VOID _write30();
	VOID _writeChinese();
	VOID _writeEnglish();
	VOID _writeConstants();
	
public:
	static HTConstants& get();
	BOOL init(_In_ DWORD CONST procID, _In_ TCHAR CONST * CONST fullPath);
	TCHAR CONST * getTCHAR(_In_ LangCode CONST code);
	DWORD getDWORD(_In_ AddrCode CONST code);

	HTConstants();
	~HTConstants();
};

#define CONSTS HTConstants::get()