#include "stdafxDLL.h"
#include "HTException.h"

#define _MSGBOX_INIT_ _message = reinterpret_cast<TCHAR *> (::HeapAlloc(::GetProcessHeap(),NULL,MSG_SIZE)); 
#define _MSGBOX_END_  ::MessageBox(NULL,_message,_T("Unhandled Exception!!"), MB_ICONERROR);

HTException::HTException(
	_In_ TCHAR CONST *CONST fileName,
	_In_ int CONST lineNo,
	_In_ TCHAR CONST *CONST funcName,
	_In_ TCHAR CONST *CONST APIName,
	_In_ DWORD CONST lastError,
	_In_ INT64 CONST returnValue,
	_In_ TCHAR CONST *CONST comment)
	:_message(nullptr)
{
	_MSGBOX_INIT_
		::StringCchPrintf(_message, MSG_SIZE,
			_T("Error Type: Windows API error\n")
			_T("--------------------Location--------------------\n")
			_T("Source: %s\n")
			_T("Function: %s\t")
			_T("Line No.: %d\n")
			_T("---------------------Details--------------------\n")
			_T("API name: %s\n")
			_T("GetLastError() = %d, Returned Value = %d\n")
			_T("------------------------------------------------\n")
			_T("Comment: \n%s"),
			fileName, funcName, lineNo,
			APIName, lastError, returnValue,
			comment);
	_MSGBOX_END_
}

HTException::HTException(
	_In_ TCHAR CONST *CONST fileName,
	_In_ int CONST lineNo,
	_In_ TCHAR CONST * CONST funcName,
	_In_ TCHAR CONST *CONST description)
	: _message(nullptr)
{
	_MSGBOX_INIT_
		::StringCchPrintf(_message, MSG_SIZE,
			_T("Error Type: Logical error\n")
			_T("--------------------Location--------------------\n")
			_T("Source: %s\n")
			_T("Function: %s\t")
			_T("Line No.: %d\n")
			_T("---------------------Details--------------------\n")
			_T("Description: \n%s"),
			fileName, funcName, lineNo,
			description);
	_MSGBOX_END_
}

HTException::HTException(
	_In_ TCHAR CONST * CONST fileName,
	_In_ int CONST lineNo,
	_In_ TCHAR CONST * CONST funcName,
	_In_ int CONST rc,
	_In_ TCHAR CONST * CONST APIName,
	_In_ char CONST * CONST query,
	_In_ char CONST * CONST sqlite3Message,
	_In_ TCHAR CONST * CONST comment) {
	TCHAR * tMessage = reinterpret_cast<TCHAR *>(::HeapAlloc(::GetProcessHeap(), NULL, ::strlen(sqlite3Message) + 1));
	size_t i = 0;
	while ((tMessage[i++] = sqlite3Message[i]) != 0);
	TCHAR * tQuery = reinterpret_cast<TCHAR *>(::HeapAlloc(::GetProcessHeap(), NULL, ::strlen(query) + 1));
	i = 0;
	while ((tQuery[i++] = query[i]) != 0);
	_MSGBOX_INIT_
		::StringCchPrintf(_message, MSG_SIZE,
			_T("Error Type: SQLite API error\n")
			_T("--------------------Location--------------------\n")
			_T("Source: %s\n")
			_T("Function: %s\t")
			_T("Line No.: %d\n")
			_T("---------------------Details--------------------\n")
			_T("SQLite3 API name: %s\n")
			_T("rc = %d\n")
			_T("Query = %s\n")
			_T("SQLite errMsg = %s\n")
			_T("------------------------------------------------\n")
			_T("Comment: \n%s"),
			fileName, funcName, lineNo,
			APIName, rc, tQuery, tMessage,
			comment);
	::HeapFree(::GetProcessHeap(), NULL, tMessage);
	::HeapFree(::GetProcessHeap(), NULL, tQuery);
	_MSGBOX_END_
}

HTException::HTException(_In_ HTException&& anotherException)
	:_message(anotherException._message)
{
	anotherException._message = nullptr;
}

#undef _MSGBOX_INIT_
#undef _MSGBOX_END_

HTException::~HTException() {
	if (_message != nullptr) {
		::HeapFree(::GetProcessHeap(), NULL, _message);
	}
}

HTException& HTException::operator= (_In_ HTException&& anotherException) {
	anotherException._message = nullptr;
	return *this;
}