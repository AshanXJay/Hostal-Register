#include <stdio.h>
#include <unistd.h>

void display_splash_screen() {
    printf("Loading...\n");
    for (int i = 0; i < 10; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
}

int main() {
    display_splash_screen();
    // Your program starts here
    return 0;
}