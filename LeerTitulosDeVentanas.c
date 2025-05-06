#include <stdio.h>
#include <windows.h>



BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lparam) {
	wchar_t title[256];
	DWORD pid;
	if (!IsWindowVisible(hwnd)) {
		return TRUE;
	}
	GetWindowTextW(hwnd, title, sizeof(title) / sizeof(wchar_t));
	if (title[0] != '\0') {
		GetWindowThreadProcessId(hwnd, &pid);
		wprintf(L"HWND: %p | Title: %s | PID: %lu", hwnd, title, pid);
	}
	return TRUE;
}

int main(){
	EnumWindows(EnumWindowsProc, 0);
	return 0;
}
