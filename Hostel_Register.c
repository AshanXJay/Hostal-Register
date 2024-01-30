//header files
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

//include additional codes
#include "additionals/splash.c"
//#include "additionals/print.c"
#include "additionals/encrypt.c"
#include "Frontend/Frontend.c"

//defining global variables


//defining functions


// main function
int main() {
    splash();
    char* role = main_login();
    if (strcmp(role, "FRONT") == 0) {
        front();
    } else if (strcmp(role, "BOYS"||"GIRLS") == 0) {
        hostal();
    }
    free(role);
    return 0;
}