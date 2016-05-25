#pragma once

#define _1K 0x400
#define _4K 0x1000

TCHAR CONST PIPE_NAME[] = _T("\\\\.\\pipe\\Idiots!!");

class HTConstants {
public:
	struct FileVersion : public HTEnumBase {
		ENUM_BODY;
		enum  {
			THREE_ONE,
			THREE_ZERO,
		};
	};

private:
	struct {
		DWORD start;
		DWORD len;
		DWORD offset;
	}_addr;
	struct {

	}_lang;

public:
	HTConstants& get();
	BOOL init(_In_ DWORD CONST procID);
	HTConstants();
	~HTConstants();
};

#define CONSTS HTConstants.get()