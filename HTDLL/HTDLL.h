
namespace HTDLL {
	enum class AddrCode {
		Start, Len, Offset,
		MAX
	};

	enum class KeyCode {
		S1 = 0x100,S2,SP,SC,CS
	};

	TCHAR CONST token[] = _T("What a stupid DLL!");
	
	//Global Variables
	namespace GVars {
		
		HTHotkeyInfo keyInfo[5];
		DWORD jmpBackAddy = 0;
		DWORD currHeroAddr = 0;
		DWORD procID = 0;
		DWORD addrCodes[(int)AddrCode::MAX];
		FileVersion h5Ver;
		HWND hWnd = NULL;
	}

	//Procedures
	namespace Procs {
		VOID getProcIDAndVer();
		VOID seekHWnd();
		VOID setKey();
		VOID procMsg();
		VOID fillAddrCodes();
		VOID readHotkeyData();
	}

	//Functions
	namespace Funcs{
		VOID appendSlash(_Inout_ TCHAR * CONST src);
		VOID getFullPath(_In_ TCHAR CONST * CONST filename, _Out_ TCHAR * CONST dest, _In_ size_t CONST maxLen);
	}

	//Assembly inline functions
	namespace ASMs{
		void asmFunc31();
	}
	
	//Callbacks
	namespace ClBks {
		BOOL CALLBACK enumWndProc(_In_ HWND hwnd, _In_ LPARAM lParam);
		LRESULT CALLBACK callWndProc(_In_ int nCode, _In_ WPARAM wParam, _In_ LPARAM lParam);
	}
	
	BOOL hookFunc(_In_ LPVOID CONST toHook, _In_ LPVOID CONST ourFunct, _In_ size_t CONST len);
	DWORD WINAPI MainThread(_In_ LPVOID param);
	
}
