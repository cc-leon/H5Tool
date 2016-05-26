
namespace HTDLL {
	TCHAR CONST token[] = _T("What a stupid DLL!");
	HTHotkeyInfo keyInfo[5];
	DWORD jmpBackAddy = 0;
	DWORD currHeroAddr = 0;
	DWORD procID = 0;
	HWND hWnd = NULL;

	VOID getProcID();
	VOID seekHWnd();
	VOID setKey();
	VOID procMsg();
	
	BOOL CALLBACK enumWndProc (_In_ HWND hwnd, _In_ LPARAM lParam);
	LRESULT CALLBACK callWndProc (_In_ int nCode, _In_ WPARAM wParam, _In_ LPARAM lParam);

	BOOL hookFunc(_In_ LPVOID CONST toHook, _In_ LPVOID CONST ourFunct, _In_ size_t CONST len);
	DWORD WINAPI MainThread(_In_ LPVOID param);
	void asmFunc();
}
