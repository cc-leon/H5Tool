#pragma once

#define _1K 0x400
#define _4K 0x1000

TCHAR CONST PIPE_NAME[] = _T("\\\\.\\pipe\\Idiots!!");

class HTConstants {
private:
	struct {

	}_addr;
	struct {

	}_lang;
public:
	HTConstants& get();
	BOOL init();
	HTConstants();
	~HTConstants();
};

#define CONSTS HTConstants.get()