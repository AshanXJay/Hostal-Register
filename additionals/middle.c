#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

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

void printc(const char *format, ...) {
    char str[1024];
    va_list args;
    va_start(args, format);
    vsprintf(str, format, args);
    va_end(args);

    int width = get_console_width();
    int length = strlen(str);
    int padding_left = (width - length) / 2;
    printf("%*s%s\n", padding_left, "", str);
}

void printm(const char *format, ...) {
    char str[1024];
    va_list args;
    va_start(args, format);
    vsprintf(str, format, args);
    va_end(args);

    int height = get_console_height();
    int padding_top = height / 2;

    for (int i = 0; i < padding_top; i++) printf("\n");

    printf("%s\n", str);
}

void printcm(const char *format, ...) {
    char str[1024];
    va_list args;
    va_start(args, format);
    vsprintf(str, format, args);
    va_end(args);

    int width = get_console_width();
    int height = get_console_height();
    int length = strlen(str);
    int padding_left = (width - length) / 2;
    int padding_top = height / 2;

    for (int i = 0; i < padding_top; i++) printf("\n");

    printf("%*s%s\n", padding_left, "", str);
}