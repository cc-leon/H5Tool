#pragma once
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