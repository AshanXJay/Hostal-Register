#include <stdio.h>
#include <unistd.h>
#include "middle.c"

void splash_screen() {
    for (int i = 0; i <= 100; i++) {
        system("cls"); // Clear the console
        char str[128];
        printcm("Loading...");
        //printcm("%d",i);
        fflush(stdout);
        Sleep(50); // Wait for 100 milliseconds
    }
    printf("\n");
}

int main() {
    splash_screen();
    // Your program starts here
    return 0;
}