#include <stdio.h>
#include <Windows.h>


int main() {

	HMODULE hModule = GetModuleHandleA("MiPrimerDLL.dll");
	if (hModule == NULL) {
		hModule = LoadLibraryA("MiPrimerDLL.dll");
		if (hModule == NULL) {
			printf("No se ha podido argar el modulo...");
			return -1;
		}
	}

	PVOID pFunc = GetProcAddress(hModule, "HolaMundo");
	if (pFunc == NULL) {
		printf("No se ha podido encontrar la funcion...");
		return -1;
	}
	typedef void (*HolaMundoFunc)();

	HolaMundoFunc HolaMundo = (HolaMundoFunc)pFunc;
	HolaMundo();


	return 0;
}