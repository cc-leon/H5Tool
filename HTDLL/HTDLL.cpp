#include "stdafxDLL.h"
#include "HTDLL.h"
#include "HTCasterSplitter.h"

namespace HTDLL {
	namespace Procs {
		VOID getProcIDAndVer() {
			HANDLE hPipe = INVALID_HANDLE_VALUE;
			do {
				hPipe = ::CreateFile(
					Files::PIPE_NAME, GENERIC_READ | GENERIC_WRITE,
					0, NULL,
					OPEN_EXISTING,
					0, NULL);
			} while (!VALID_HANDLE(hPipe));

			DWORD cbRead = 0;
			DWORD fileVer = 0;
			::ReadFile(hPipe, &GVars::procID, sizeof(GVars::procID), &cbRead, NULL);
			//Funcs::popMsgBox(GVars::procID);
			::ReadFile(hPipe, &fileVer, sizeof(fileVer), &cbRead, NULL);
			GVars::h5Ver = (FileVersion)fileVer;
			::CloseHandle(hPipe);
		}

		VOID seekHWnd() {
			::EnumWindows(ClBks::enumWndProc, NULL);
		}

		VOID setKey() {
			for (int i = 0; i < (int)KeyCode::MAX;i++) {
				UINT fsModifiers = 0;
				if (GVars::keyInfo[i].ctrl) {
					fsModifiers |= MOD_CONTROL;
				}
				if (GVars::keyInfo[i].shift) {
					fsModifiers |= MOD_SHIFT;
				}
				if (GVars::keyInfo[i].alt) {
					fsModifiers |= MOD_ALT;
				}

				BOOL br = ::RegisterHotKey(NULL, i, fsModifiers, GVars::keyInfo[i].vs_key);
			}
		}

		VOID procMsg() {
			MSG msg;
			if (::PeekMessage(&msg, NULL, NULL, NULL, PM_NOREMOVE)) {
				::GetMessage(&msg, NULL, NULL, NULL);
				::TranslateMessage(&msg);
				if (LOWORD(msg.message) == WM_HOTKEY) {
					DWORD64 elapsed = __rdtsc() - GVars::advTicks;
					LARGE_INTEGER freq;
					::QueryPerformanceFrequency(&freq);
					elapsed /= freq.QuadPart;
					if (elapsed < MAX_TICKS) {
						switch ((KeyCode)msg.wParam) {
						case KeyCode::S1:
							splitUnit(1);
							break;
						case KeyCode::S2:
							splitUnit(2);
							break;
						case KeyCode::SP:
							splitCaster();
							break;
						case KeyCode::SC:
							splitUnit(GVars::keyInfo[(int)KeyCode::SC].amount);
							break;
						case KeyCode::CS:
							combineUnit();
							break;
						default:
							THROW_USER("Unhandled key code");
							break;
						}
					}
					else {
						::MessageBeep(MB_ICONERROR);
					}
				}
			}
		}

		VOID __fillAddr31() {
			for (int i = 0; i < (int)AddrCode::MAX;i++) {
				switch ((AddrCode)i) {
				case AddrCode::Start:
					GVars::addrCodes[i] = 0x005EBE74;
					break;
				case AddrCode::Len:
					GVars::addrCodes[i] = 6;
					break;
				case AddrCode::Offset:
					GVars::addrCodes[i] = 0x110;
					break;
				case AddrCode::DataLen:
					GVars::addrCodes[i] = 0x100;
					break;
				case AddrCode::TypeOffset:
					GVars::addrCodes[i] = 0x7;
					break;
				case AddrCode::AmtOffset:
					GVars::addrCodes[i] = 0x8;
					break;
				default:
					THROW_USER("Invalid address code");
					break;
				}
			}
		}
		VOID __fileAddr30() {

		}

		VOID fillAddrCodes() {
			switch (GVars::h5Ver) {
			case FileVersion::THREE_ONE:
				__fillAddr31();
				break;
			case FileVersion::THREE_ZERO:
				__fileAddr30();
				break;
			default:
				THROW_USER("Invalid version code");
				break;
			}
		}

		VOID readHotkeyData() {
			::ZeroMemory(&GVars::keyInfo, sizeof(GVars::keyInfo));
			CHAR configFullName[MAX_PATH];
			HTGameDB::getFullPath(Files::CONFIG_FILE_NAME, configFullName, MAX_PATH);

			CFile file;
			if (file.Open(configFullName, CFile::typeBinary | CFile::modeRead)) {
				BYTE * CONST buffer = ALLOC(BYTE, file.GetLength());
				file.Read(buffer, (UINT)file.GetLength());
				file.Close();

				HTHotkeyInfo *reader = reinterpret_cast<HTHotkeyInfo*> (buffer);
				for (int i = 0; i < (int) KeyCode::MAX;i++) {
					GVars::keyInfo[i] = *reader;
					reader++;
				}
				FREE(buffer);
			}
			else {
				__generateDefaultHotkeyData();
			}
		}

		VOID __generateDefaultHotkeyData() {
			::ZeroMemory(GVars::keyInfo, sizeof(GVars::keyInfo));
			GVars::keyInfo[(int)KeyCode::S1].ctrl = TRUE;
			GVars::keyInfo[(int)KeyCode::S1].vs_key = 0x31;
			GVars::keyInfo[(int)KeyCode::S2].ctrl = TRUE;
			GVars::keyInfo[(int)KeyCode::S2].vs_key = 0x32;
			GVars::keyInfo[(int)KeyCode::SP].ctrl = TRUE;
			GVars::keyInfo[(int)KeyCode::SP].vs_key = 0x53;
			GVars::keyInfo[(int)KeyCode::SC].ctrl = TRUE;
			GVars::keyInfo[(int)KeyCode::SC].vs_key = 0x41;
			GVars::keyInfo[(int)KeyCode::SC].amount = 4;
			GVars::keyInfo[(int)KeyCode::CS].ctrl = TRUE;
			GVars::keyInfo[(int)KeyCode::CS].vs_key = 0x43;
		}

		VOID splitUnit(_In_ DWORD CONST amount) {
			if (amount == 0) {
				return;
			}
			
			DWORD *heroCreaturePos = (DWORD*)(GVars::currHeroAddr + GVars::addrCodes[(int)AddrCode::Offset]);
			DWORD * creatureSlotPtrs = (DWORD*)*heroCreaturePos;

			INT mainSlot = __getFirstCreature();

			for (int i = 0; i < MAX_SLOTS; i++) {
				if (getCreatureAddr(i) == NULL) {
					if (*(getCreatureAddr(mainSlot) + GVars::addrCodes[(int)AddrCode::AmtOffset]) > amount) {
						BYTE * content = (BYTE*)VirtualAllocEx(GetCurrentProcess(), NULL, GVars::addrCodes[(int)AddrCode::DataLen],
							MEM_COMMIT|MEM_TOP_DOWN, PAGE_READWRITE);
						::memcpy(content, getCreatureAddr(mainSlot), GVars::addrCodes[(int)AddrCode::DataLen]);
						*(creatureSlotPtrs + i) = (DWORD)content;
						*(getCreatureAddr(i) + GVars::addrCodes[(int)AddrCode::AmtOffset]) = amount;
						*(getCreatureAddr(mainSlot) + GVars::addrCodes[(int)AddrCode::AmtOffset]) -= amount;
					}
					else {
						break;
					}
				}
			}
		}

		DWORD * getCreatureAddr(_In_ INT CONST slotNum) {
			if (slotNum >= 0 && slotNum < MAX_SLOTS) {
				DWORD *heroCreaturePos = (DWORD*)(GVars::currHeroAddr + GVars::addrCodes[(int)AddrCode::Offset]);
				DWORD * creatureSlotPtrs = (DWORD*)*heroCreaturePos;
				return (DWORD*)*(creatureSlotPtrs+slotNum);
			}
			else {
				THROW_USER("Invalid slot number parameter");
			}
		}

		INT __getFirstCreature() {
			for (int i = 0; i < MAX_SLOTS; i++) {
				if (getCreatureAddr(i) != NULL) {
					return i;
				}
			}
			return -1;
		}

		VOID combineUnit() {
			DWORD *heroCreaturePos = (DWORD*)(GVars::currHeroAddr + GVars::addrCodes[(int)AddrCode::Offset]);
			DWORD * creatureSlotPtrs = (DWORD*)*heroCreaturePos;
			DWORD *iAddr = NULL, *jAddr = NULL;
			for (int i = 0; i < MAX_SLOTS; i++) {
				iAddr = getCreatureAddr(i);
				if (iAddr != NULL) {
					DWORD amount = *(iAddr + GVars::addrCodes[(int)AddrCode::AmtOffset]);
					DWORD type = *(iAddr + GVars::addrCodes[(int)AddrCode::TypeOffset]);
					BOOL foundMax = TRUE;
					for (int j = i + 1; j < MAX_SLOTS;j++) {
						jAddr = getCreatureAddr(j);
						if (jAddr != NULL) {
							if (*(jAddr + GVars::addrCodes[(int)AddrCode::TypeOffset]) == type) {
								if (amount < *(jAddr + GVars::addrCodes[(int)AddrCode::AmtOffset])) {
									foundMax = FALSE;
									break;
								}
							}
						}
					}
					if (foundMax) {
						for (int j = 0; j < MAX_SLOTS;j++) {
							jAddr = getCreatureAddr(j);
							if (jAddr != NULL && j != i) {
								if (*(jAddr + GVars::addrCodes[(int)AddrCode::TypeOffset]) == type) {
									*(iAddr + GVars::addrCodes[(int)AddrCode::AmtOffset]) += *(jAddr + GVars::addrCodes[(int)AddrCode::AmtOffset]);
									VirtualAlloc(jAddr, GVars::addrCodes[(int)AddrCode::DataLen], MEM_RESET, PAGE_READWRITE);
									*(creatureSlotPtrs + j) = 0;
								}
							}
						}
					}
				}
			}
		}

		VOID splitCaster() {
			DWORD *heroCreaturePos = (DWORD*)(GVars::currHeroAddr + GVars::addrCodes[(int)AddrCode::Offset]);
			DWORD * creatureSlotPtrs = (DWORD*)*heroCreaturePos;
			UINT emptySlots = 0;
			INT mainSlot = __getFirstCreature();
			DWORD * mainAddr = getCreatureAddr(mainSlot);
			DWORD amount = *(mainAddr+ GVars::addrCodes[(int)AddrCode::AmtOffset]) ;
			DWORD type = *(mainAddr + GVars::addrCodes[(int)AddrCode::TypeOffset]);
			
			UINT base = 0, multiplier = 0, growth = 0;
			if (GVars::dbGame.getCasterInfo((UINT)type, base, multiplier) == FALSE) {
				return;
			}
			growth = GVars::dbGame.getGrowth((UINT)type);

			for (int i = 0; i < MAX_SLOTS;i++) {
				if (getCreatureAddr(i) == NULL) {
					emptySlots++;
				}
			}
			if (emptySlots == 0||amount == 1) {
				return;
			}
			if (emptySlots > amount) {
				emptySlots = amount - 1;
			}
			UINT j = 0;
			for (int i = 0; i < MAX_SLOTS;i++) {
				if (getCreatureAddr(i) == NULL) {
					BYTE * content = (BYTE*)VirtualAllocEx(GetCurrentProcess(), NULL, GVars::addrCodes[(int)AddrCode::DataLen],
					MEM_COMMIT | MEM_TOP_DOWN, PAGE_READWRITE);
					::memcpy(content, mainAddr, GVars::addrCodes[(int)AddrCode::DataLen]);
					*(creatureSlotPtrs + i) = (DWORD)content;
					*(getCreatureAddr(i) + GVars::addrCodes[(int)AddrCode::AmtOffset]) = amount;
					*(getCreatureAddr(mainSlot) + GVars::addrCodes[(int)AddrCode::AmtOffset]) -= amount;
					j++;
					if (j >= emptySlots) {
						break;
					}
				}
			}

			HTCasterSplitter split(amount, emptySlots + 1, growth, base, multiplier);
			UINT * CONST splitResult = ALLOC(UINT,emptySlots+1);
			DWORD *iAddr = NULL;
			j = 0;
			split.getOutput(splitResult);
			for (int i = 0; i < MAX_SLOTS;i++) {
				iAddr = getCreatureAddr(i);
				if (iAddr != NULL) {
					if (*(iAddr + GVars::addrCodes[(int)AddrCode::TypeOffset]) == type) {
						*(iAddr + GVars::addrCodes[(int)AddrCode::AmtOffset]) = splitResult[j];
						j++;
						if (j > emptySlots) {
							break;
						}
					}
				}
			}
			FREE(splitResult);
		}
	}

	namespace Funcs {

		VOID popMsgBox(_In_ int CONST number,_In_ int CONST radix) {
			CHAR num[20];
			_itoa_s(number, num, 20, radix);
			//MessageBox(GVars::hWnd, num, "", NULL);
		}
	}

	namespace ASMs {
		void __declspec(naked) asmFunc31() { 
			GVars::advTicks = __rdtsc();
			__asm {
				mov ecx, [esi + 04]
				mov GVars::currHeroAddr, ecx
				cmp ecx, [edi + 04]

				jmp[GVars::jmpBackAddy]
			}
		}
	}

	namespace ClBks {
		
		BOOL CALLBACK enumWndProc(_In_ HWND hwnd, _In_ LPARAM lParam) {
			DWORD tID = 0, pID = 0;
			tID = ::GetWindowThreadProcessId(hwnd, &pID);
			if (tID != 0 && pID != 0) {
				if (pID == GVars::procID) {
					TCHAR title[MAX_PATH];
					::GetWindowText(hwnd, title, MAX_PATH);
					if (title[0] != _T('D') && title[0] != _T('M')) {						
						GVars::hWnd = hwnd;
						return FALSE;
					}
				}
			}
			return TRUE;
		}
		
	}

	BOOL hookFunc(_In_ LPVOID CONST toHook, _In_ LPVOID CONST asmFunc31, _In_ size_t CONST len) {
		if (len < 5) {
			return FALSE;
		}

		DWORD curProtection = 0;
		::VirtualProtect(toHook, len, PAGE_EXECUTE_READWRITE, &curProtection);

		::memset(toHook, 0x90, len);

		DWORD relativeAddress = ((DWORD)asmFunc31 - (DWORD)toHook) - 5;

		*(BYTE*)toHook = 0xE9;
		*(DWORD*)((DWORD)toHook + 1) = relativeAddress;

		DWORD temp = 0;
		::VirtualProtect(toHook, len, curProtection, &temp);

		return TRUE;
	}

	DWORD WINAPI MainThread(_In_ LPVOID param) {
		Procs::getProcIDAndVer();
		Procs::fillAddrCodes();
		Procs::seekHWnd();
		Procs::readHotkeyData();
		Procs::setKey();

		//int hookLength = 6;
		//DWORD hookAddress = 0x005EBE74;
		GVars::jmpBackAddy = GVars::addrCodes[(int)AddrCode::Start] + GVars::addrCodes[(int)AddrCode::Len];

		switch (GVars::h5Ver) {
		case FileVersion::THREE_ONE:
			hookFunc(
				(void*)GVars::addrCodes[(int)AddrCode::Start], 
				ASMs::asmFunc31,
				GVars::addrCodes[(int)AddrCode::Len]);
			break;
		case FileVersion::THREE_ZERO:
			break;
		case FileVersion::MAX:
			break;
		default:
			break;
		}

		while (true) {
			if (GetAsyncKeyState(VK_RCONTROL)) {
				break;
			}
			Procs::procMsg();
			Sleep(50);
		}

		::FreeLibraryAndExitThread((HMODULE)param, 0);

		return 0;
	}

}

BOOL WINAPI DllMain(_In_ HINSTANCE hModule, _In_ DWORD dwReason, _In_ LPVOID lpReserved) {
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		::CreateThread(0, 0, HTDLL::MainThread, hModule, 0, 0);
		break;
	}

	return TRUE;
}