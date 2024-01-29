#include <stdio.h>
#include <unistd.h>
#include "print.c"

void splash_screen() {
    for (int i = 0; i <= 100; i++) {
        system("cls"); // Clear the console
        char str[128];
        printcm("Loading %d%%",i);
        //printcm("%d",i);
        fflush(stdout);
        Sleep(10); // Wait for 20 milliseconds
    }
    printf("\n");
}

void welcome_screen() {
    printf("\n");
    printc("Welcome to the UWU Hostal Registry System!");
    printf("\n");
    printc("Press any key to login...");
    
    getc(stdin);
    }

int main() {
    //splash_screen();
    system("cls");
    welcome_screen();
    return 0;
}