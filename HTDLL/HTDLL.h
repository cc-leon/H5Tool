namespace HTDLL {
	DWORD jmpBackAddy = 0;
	DWORD currHeroAddr = 0;

	BOOL hookFunc(_In_ LPVOID CONST toHook, _In_ LPVOID CONST ourFunct, _In_ size_t CONST len);
	DWORD WINAPI MainThread(_In_ LPVOID param);
	void asmFunc();
}
