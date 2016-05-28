#include "stdafxDLL.h"
#include "HTException.h"
#include "HTGameDB.h"

VOID HTGameDB::appendSlash(_Inout_ TCHAR * CONST src) {
	size_t len = 0;
	HRESULT hr = ::StringCchLength(src, MAX_PATH, &len);
	if (FAILED(hr)) {
		THROW_API("StringCchLength", hr, "");
	}
	if (src[len - 1] != _T('\\')) {
		src[len] = _T('\\');
		src[len + 1] = _T('\0');
	}
}

VOID HTGameDB::getFullPath(_In_ TCHAR CONST * CONST filename, _Out_ TCHAR * CONST dest, _In_ size_t CONST maxLen) {
	HRESULT hr = S_OK;
	if (::GetCurrentDirectory(maxLen, dest) == 0) {
		THROW_API("GetCurrentDirectory", 0, "");
	}
	appendSlash(dest);
	hr = ::StringCchCat(dest, maxLen, filename);
	if (FAILED(hr)) {
		THROW_API("StringCchCat", hr, "");
	}
}

HTGameDB::HTGameDB() {
	char dbFullName[MAX_PATH];
	char *zErrMsg = 0;

	getFullPath(Files::DB_NAME, dbFullName, MAX_PATH);
	int rc = ::sqlite3_open_v2(dbFullName, &_db, SQLITE_OPEN_READONLY,NULL);
	if (rc) {
		THROW_SQL("sqlite3_open_v2", rc, "no query", sqlite3_errmsg(_db), "");
	}
	char query[] = "PRAGMA foreign_keys = ON;";
	rc = sqlite3_exec(_db, query, nullptr, 0, &zErrMsg);
	if (rc != SQLITE_OK) {
		THROW_SQL("sqlite3_exec", rc, query, zErrMsg, "");
	}
}	

UINT HTGameDB::getGrowth(_In_ UINT CONST creatureID) {
	char query[] = "SELECT growth FROM creatures WHERE id = ? ;";
	sqlite3_stmt * pStmt = NULL; 
	int rc = 0;
	UINT result = 0;

	do {
		rc = ::sqlite3_prepare_v2(_db, query, -1, &pStmt, NULL);
		if (rc != SQLITE_OK) {
			THROW_SQL("sqlite3_prepare_v2", rc, query, ::sqlite3_errmsg(_db), "");
		}
		::sqlite3_bind_int(pStmt, 1, creatureID);
		while (true) {
			rc = ::sqlite3_step(pStmt);
			if (rc == SQLITE_DONE) {
				break;
			}
			if (rc != SQLITE_ROW) {
				THROW_SQL("sqlite3_step", rc, query, ::sqlite3_errmsg(_db), "sqlite3_step function return a value other than SQLITE_ROW before it is done");
			}
			result = ::sqlite3_column_int(pStmt, 0);
		}
		rc = ::sqlite3_finalize(pStmt);
	} while (rc == SQLITE_SCHEMA);
	return result;
}

BOOL HTGameDB::getCasterInfo(_In_ UINT CONST creatureID, _Out_ UINT& base, _Out_ UINT& multiplier) {
	char query[] = "SELECT COUNT(*) FROM caster_creatures WHERE creature = ?;";
	sqlite3_stmt * pStmt = NULL;
	int rc = 0;
	UINT count = 0;

	do {
		rc = ::sqlite3_prepare_v2(_db, query, -1, &pStmt, NULL);
		if (rc != SQLITE_OK) {
			THROW_SQL("sqlite3_prepare_v2", rc, query, ::sqlite3_errmsg(_db), "");
		}
		::sqlite3_bind_int(pStmt, 1, creatureID);
		while (true) {
			rc = ::sqlite3_step(pStmt);
			if (rc == SQLITE_DONE) {
				break;
			}
			if (rc != SQLITE_ROW) {
				THROW_SQL("sqlite3_step", rc, query, ::sqlite3_errmsg(_db), "sqlite3_step function return a value other than SQLITE_ROW before it is done");
			}
			count = ::sqlite3_column_int(pStmt, 0);
		}
		rc = ::sqlite3_finalize(pStmt);
	} while (rc == SQLITE_SCHEMA);
	
	if (count == 0) {
		return FALSE;
	}

	count = 0;
	base = 0;
	multiplier = 1;
	char query2[] = "SELECT T1.base, T1.multiplier FROM spell_damage T1, caster_creatures T2 "
		"where T2.creature = ? and T1.spell = T2.spell and T1.level = T2.level;";
	do {
		rc = ::sqlite3_prepare_v2(_db, query2, -1, &pStmt, NULL);
		if (rc != SQLITE_OK) {
			THROW_SQL("sqlite3_prepare_v2", rc, query2, ::sqlite3_errmsg(_db), "");
		}
		::sqlite3_bind_int(pStmt, 1, creatureID);
		while (true) {
			rc = ::sqlite3_step(pStmt);
			if (rc == SQLITE_DONE) {
				break;
			}
			if (rc != SQLITE_ROW) {
				THROW_SQL("sqlite3_step", rc, query, ::sqlite3_errmsg(_db), "sqlite3_step function return a value other than SQLITE_ROW before it is done");
			}
			if (count == 0) {
				count = ::sqlite3_column_count(pStmt);
				if (count == 0) {
					break;
				}
				else {
					count = 1;
				}
			}
			else {
				count++;
			}
			UINT newBase = ::sqlite3_column_int(pStmt, 0);
			UINT newMultiplier = ::sqlite3_column_int(pStmt,1);
			if (newBase > base) {
				base = newBase;
				multiplier = newMultiplier;
			}
			else if (newBase == base) {
				if (newMultiplier > multiplier) {
					multiplier = newMultiplier;
				}
			}
		}
		rc = ::sqlite3_finalize(pStmt);
	} while (rc == SQLITE_SCHEMA);
	return TRUE;
}

HTGameDB::~HTGameDB() {
	::sqlite3_close(_db);
}
