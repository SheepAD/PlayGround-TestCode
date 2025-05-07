#include <stdio.h>
#include <windows.h>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "user32.lib")

int main() {
	DWORD lower = 0x00000000;
	DWORD current = 0;
	printf("\nPulsa 'M' para mutear y 'ESC' para salir del programa\n");
	while (1) {
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			printf("\nSaliendo del programa...\n");
			break;
		}
		if (GetAsyncKeyState('M') & 0x8000) {
			waveOutSetVolume(NULL, lower);
			printf("Muteaste el Volumen!");
			Sleep(200);
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			if (waveOutGetVolume(NULL, &current) == MMSYSERR_NOERROR) {
				WORD left = current & 0xFFFF;
				WORD right = (current >> 16) & 0xFFFF;

				left = (left + 0x0100 > 0xFFFF) ? 0xFFFF : left + 0x0100;
				right = (right + 0x0100 > 0xFFFF) ? 0xFFFF : right + 0x100;

				current = (DWORD)right << 16 | (DWORD)left;
				waveOutSetVolume(NULL, current);
				printf("Current Volume: 0x%08X\n", current);
			}
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			if (waveOutGetVolume(NULL, &current) == MMSYSERR_NOERROR) {
				WORD left = current & 0xFFFF;
				WORD right = (current >> 16) & 0xFFFF;

				left = (left <= 0x0100) ? 0x0000 : left - 0x0100;
				right = (right <= 0x0100) ? 0x0000 : right - 0x100;

				current = (DWORD)right << 16 | (DWORD)left;
				waveOutSetVolume(NULL, current);
				printf("Current Volume: 0x%08X\n", current);
			}
		}
		Sleep(200);
		
	}
	return 0;
}
