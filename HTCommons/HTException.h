#pragma once
class HTException {
protected:
	TCHAR * _message;
public:
	static DWORD CONST MSG_SIZE = 0x1000;
	HTException(_In_ HTException CONST& anotherException) = delete;
	HTException(_In_ HTException && anotherException);
	HTException& operator= (_In_ HTException CONST& anotherException) = delete;
	HTException& operator= (_In_ HTException&& anotherException);
	
	explicit HTException(
		_In_ TCHAR CONST * CONST fileName,
		_In_ int CONST lineNo,
		_In_ TCHAR CONST * CONST funcName,
		_In_ TCHAR CONST * CONST APIName,
		_In_ DWORD CONST lastError,
		_In_ INT64 CONST returnValue,
		_In_ TCHAR CONST * CONST comment);
	explicit HTException(
		_In_ TCHAR CONST * CONST fileName,
		_In_ int CONST lineNo,
		_In_ TCHAR CONST * CONST funcName,
		_In_ TCHAR CONST * CONST description);
	explicit HTException(
		_In_ TCHAR CONST * CONST fileName,
		_In_ int CONST lineNo,
		_In_ TCHAR CONST * CONST funcName,
		_In_ int CONST rc,
		_In_ TCHAR CONST * CONST APIName,
		_In_ char CONST * CONST query,
		_In_ char CONST * CONST sqlite3Message,
		_In_ TCHAR CONST * CONST comment);
	~HTException();
};

#define THROW_API(api,value,cmnt) \
	throw HTException(_T(__FILE__), __LINE__, _T(__FUNCTION__), _T(api), ::GetLastError(),(INT64)(value), _T(cmnt))
#define THROW_USER(desc) \
	throw HTException(_T(__FILE__),__LINE__,_T(__FUNCTION__),_T(desc))
#define THROW_SQL(api,rc,query,errmsg,cmnt) \
	throw HTException(_T(__FILE__),__LINE__,_T(__FUNCTION__), (int)rc , _T(api),query, errmsg, _T(cmnt))
