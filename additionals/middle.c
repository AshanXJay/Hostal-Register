#include <windows.h>
#include <stdio.h>
#include <string.h>

// Function prototypes
void print_centered(char *str);
int get_console_width();
int get_console_height();

int get_console_width() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

int get_console_height() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void print_centered(char *str) {
    int width = get_console_width();
    int height = get_console_height();
    int length = strlen(str);
    int padding_left = (width - length) / 2;
    int padding_top = height / 2;

    for (int i = 0; i < padding_top; i++) printf("\n");

    printf("%*s%s\n", padding_left, "", str);
}

int main() {
    while (1) {
        system("cls"); // Clear the console
        char str[] = "Hello, World!";
        print_centered(str);
        Sleep(500); // Wait for 500 milliseconds
    }
    return 0;
}