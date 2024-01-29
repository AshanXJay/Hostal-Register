//header files
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

//include additional codes
#include "additionals/splash.c"
#include "additionals/print.c"
#include "additionals/encrypt.c"

//defining global variables


//defining functions
void splash_screen();

// main function
int main() {
    splash_screen();
    login();
    return 0;
}

