#include <stdio.h>
#include <unistd.h>
#include "middle.c"

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

int main() {
    splash_screen();
    // Your program starts here
    return 0;
}