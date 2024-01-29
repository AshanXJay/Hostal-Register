//header files
#include <windows.h>
#include <string.h>
#include<stdio.h>
#include <unistd.h>

//defining functions                                                
int get_console_width();
int get_console_height();
void printc(char *str);
void printcm(char *str);

//get_console_width() function
int get_console_width() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

//get_console_height() function
int get_console_height() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

//printc() function for Centered Printing
void printc(char *str) {
    int width = get_console_width();
    int length = strlen(str);
    int padding_left = (width - length) / 2;
    printf("%*s%s\n", padding_left, "", str);
}

//printcm() function for Centered Printing with Padding to middle
void printcm(char *str) {
    int width = get_console_width();
    int height = get_console_height();
    int length = strlen(str);
    int padding_left = (width - length) / 2;
    int padding_top = height / 2;

    for (int i = 0; i < padding_top; i++) printf("\n");
    printf("%*s%s\n", padding_left, "", str);
}
