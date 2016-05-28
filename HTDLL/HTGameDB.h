#pragma once

#include "../HTSQLite/sqlite3.h"

class HTGameDB {
private:
	static VOID appendSlash(_Inout_ TCHAR * CONST src);
protected:
	sqlite3 *_db;
public:
	static VOID getFullPath(_In_ TCHAR CONST * CONST filename, 
		_Out_ TCHAR * CONST dest, 
		_In_ size_t CONST maxLen);
	UINT getGrowth(_In_ UINT CONST creatureID);
	BOOL getCasterInfo(_In_ UINT CONST creatureID,_Out_ UINT& base, _Out_ UINT& multiplier);
	HTGameDB();
	~HTGameDB();
};

