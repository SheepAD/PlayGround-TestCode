#include <stdio.h>
#include <windows.h>

int main() {
    while (1) {
        for (int letra = 'A'; letra <= 'Z'; ++letra) {
            if (GetAsyncKeyState(letra) & 0x8000) {
                printf("%c\n", letra); 
            }
        }

        for (int numero = '0'; numero <= '9'; ++numero) {
            if (GetAsyncKeyState(numero) & 0x8000) {
                printf("%c\n", numero);
            }
        }
        
        int s_char[] = { 186, 187, 188, 189, 190, 191, 219, 220, 221, 222 };
        int cantidad_de_char = sizeof(s_char) / sizeof(s_char[0]);

        for (int special = 0; special < cantidad_de_char; ++special) {
            if (GetAsyncKeyState(s_char[special]) & 0x8000) {
                switch (s_char[special]) {
                case 186:
                    printf("; :\n");
                    break;
                case 187:
                    printf("= +\n");
                    break;
                case 188:
                    printf(", <\n");
                    break;
                case 189:
                    printf("- _\n");
                    break;
                case 190:
                    printf(". >\n");
                    break;
                case 191:
                    printf("/ ?\n");
                    break;
                case 219:
                    printf("[ {\n");
                    break;
                case 220:
                    printf("\\ |\n");
                    break;
                case 221:
                    printf("] }\n");
                    break;
                case 222:
                    printf("' \"\n");
                    break;
                }
            }
        }
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            printf("ESC presionado. Saliendo...\n");
            break;
        }

        Sleep(100);


    }

    return 0;
}
