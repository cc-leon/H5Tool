#include "HTGameDB.h"

namespace HTDLL {
	enum class AddrCode {
		Start, Len, Offset,DataLen,
		TypeOffset,AmtOffset,
		MAX
	};

	enum class KeyCode {
		S1,S2,SP,SC,CS,
		MAX,
	};

	TCHAR CONST token[] = _T("What a stupid DLL!");
	DWORD64 CONST MAX_TICKS = 0x100;
	INT CONST MAX_SLOTS = 7;
	//Global Variables
	namespace GVars {
		
		HTHotkeyInfo keyInfo[5];
		DWORD jmpBackAddy = 0;
		DWORD currHeroAddr = 0;
		DWORD procID = 0;
		DWORD addrCodes[(int)AddrCode::MAX];
		DWORD64 advTicks = 0;
		FileVersion h5Ver;
		HWND hWnd = NULL;
		HTGameDB dbGame;
	}

	//Procedures
	namespace Procs {
		VOID getProcIDAndVer();
		VOID seekHWnd();
		VOID setKey();
		VOID procMsg();
		VOID fillAddrCodes();
		VOID __fillAddr31();
		VOID __fileAddr30();
		VOID readHotkeyData();
		VOID __generateDefaultHotkeyData();
		VOID splitUnit(_In_ DWORD CONST amount);
		INT __getFirstCreature();
		DWORD * getCreatureAddr(_In_ INT CONST slotNum);
		VOID combineUnit();
		VOID splitCaster();
	}

	//Functions
	namespace Funcs{
		VOID popMsgBox(_In_ int CONST number,_In_ int CONST radix = 10);
	}

	//Assembly inline functions
	namespace ASMs{
		void asmFunc31();
	}
	
	//Callbacks
	namespace ClBks {
		BOOL CALLBACK enumWndProc(_In_ HWND hwnd, _In_ LPARAM lParam);
	}
	
	BOOL hookFunc(_In_ LPVOID CONST toHook, _In_ LPVOID CONST ourFunct, _In_ size_t CONST len);
	DWORD WINAPI MainThread(_In_ LPVOID param);
	
}
