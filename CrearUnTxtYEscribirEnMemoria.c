#include <Windows.h>
#include <stdio.h>


int main() {

	LPCWSTR path = L"C:\\Users\\'$User'\\Desktop\\MyLab\\nuevo.txt";
	HANDLE hFile = INVALID_HANDLE_VALUE;

	hFile = CreateFileW(path, GENERIC_ALL, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		printf("\n[!] Error al crear el txt... \n");
		return -1;
	}

	BOOL cHandle = CloseHandle(hFile);

	if (!cHandle) {
		printf("\n[!] Error al cerrar handle: %lu \n", GetLastError());
		return -1;
	}

	printf("\n[+] El archivo se ha creado correctamente! \n");

	PVOID pAddress = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 100);
	CHAR* cString = "Escribiendo en memoria justo despues de haber creado un archivo...";

	memcpy(pAddress, cString, strlen(cString));

	BOOL hFree = HeapFree(GetProcessHeap(), 0, pAddress);

	if (!hFree) {
		printf("Error al liberar el HEAP: %lu", GetLastError());
		return -1;
	}
	return 0;
}
