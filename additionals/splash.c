#include <stdio.h>
#include <unistd.h>
#include "middle.c"

void splash_screen() {
    printcm("Loading...\n");
    for (int i = 0; i < 10; i++) {
        printcm(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
}

int main() {
    splash_screen();
    // Your program starts here
    return 0;
}