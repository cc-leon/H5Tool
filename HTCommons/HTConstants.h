#pragma once

#define _1K 0x400
#define _4K 0x1000

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