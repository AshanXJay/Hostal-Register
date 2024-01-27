#include <windows.h>
#include <stdio.h>
#include <string.h>

// Function prototype
void print_centered(char *str);

int get_console_width() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

void print_centered(char *str) {
    int width = get_console_width();
    int length = strlen(str);
    int padding = (width - length) / 2;
    printf("%*s%s\n", padding, "", str);
}

int main() {
    while (1) {
        system("cls"); // Clear the console
        int width = get_console_width();
        char str[100];
        sprintf(str, "Console width: %d", width);
        print_centered(str);
        Sleep(500); // Wait for 500 milliseconds
    }
    return 0;
}