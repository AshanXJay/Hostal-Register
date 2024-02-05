//header files
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

//include additional codes
#include "additionals/splash.c"
#include "additionals/encrypt.c"
#include "Frontend/Frontend.c"
#include "HostelEnd/Hostalend.c"

//defining global variables
char* userrole;

// main function
int main() {
    splash();
    log_in: char* userrole = login();
    if (strcmp(userrole, "FRONT") == 0) {
        frontf();
    } else if (strcmp(userrole, "BOYS") == 0 || strcmp(userrole, "GIRLS") == 0) {
        hostelf(userrole);
    }
    else{
        goto log_in;
    }
    free(userrole);
    return 0;
}