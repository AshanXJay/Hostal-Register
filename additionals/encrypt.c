#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>


#define MAX_SIZE 100

// Function to encrypt a password using Caesar cipher
void encrypt_password(char* password) {
    for (int i = 0; password[i] != '\0'; i++) {
        char c = password[i];
        if (c >= 'a' && c <= 'z') {
            password[i] = (c - 'a' + 3) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            password[i] = (c - 'A' + 3) % 26 + 'A';
        } else if (c >= '0' && c <= '9') {
            password[i] = (c - '0' + 3) % 10 + '0';
        }
    }
}

void encrypt_username(char* username){
    for (int j = 0; username[j] != '\0'; j++) {
        char c = username[j];
        if (c >= 'a' && c <= 'z') {
            username[j] = (c - 'a' + 3) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            username[j] = (c - 'A' + 3) % 26 + 'A';
        } else if (c >= '0' && c <= '9') {
            username[j] = (c - '0' + 3) % 10 + '0';
        }
    }
}

void decrypt_username(char* username){
    for (int j = 0; username[j] != '\0'; j++) {
        char c = username[j];
        if (c >= 'a' && c <= 'z') {
            username[j] = (c - 'a' - 3 + 26) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            username[j] = (c - 'A' - 3 + 26) % 26 + 'A';
        } else if (c >= '0' && c <= '9') {
            username[j] = (c - '0' - 3 + 10) % 10 + '0';
        }
    }
}

void decrypt_role(char* role){
    for (int j = 0; role[j] != '\0'; j++) {
        char c = role[j];
        if (c >= 'a' && c <= 'z') {
            role[j] = (c - 'a' - 3 + 26) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            role[j] = (c - 'A' - 3 + 26) % 26 + 'A';
        } else if (c >= '0' && c <= '9') {
            role[j] = (c - '0' - 3 + 10) % 10 + '0';
        }
    }
}

char* login(char* entered_username, char* entered_password) {
    FILE* file = fopen("D:/GitHub/Hostal-Register/data/Users_Encrypt.txt", "r");
    if (file == NULL) {
        printf("Could not open file\n");
        return NULL;
    }

    // Encrypt the entered password
    encrypt_password(entered_password);

    // Encrypt the entered username
    encrypt_username(entered_username);

    char line[MAX_SIZE];
    while (fgets(line, sizeof(line), file)) {
        char *username = strtok(line, "`");
        char *password = strtok(NULL, "`");
        char *role = strtok(NULL, "\n");

        if (username != NULL && password != NULL && role != NULL &&
            strcmp(username, entered_username) == 0 && strcmp(password, entered_password) == 0) {
            fclose(file);
            return strdup(role);
        }
    }

    fclose(file);
    system("cls");
    printcm("Invalid username or password\n");
    return NULL;
}

void get_password(char *password) {
    char ch;
    int i = 0;
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') { // handle backspace
            if (i > 0) {
                i--;
                printf("\b \b"); // erase previous *
            }
            continue;
        }
        printf("*");
        password[i++] = ch;
    }
    password[i] = '\0'; // null terminate string
}

char* main_login() {
    char username[MAX_SIZE];
    char password[MAX_SIZE];
    system("cls");
    printf("\n");
    printc("Welcome to UWU Hostel Registry System!");    
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");

    printf("\n\tEnter username: ");
    scanf("%s", username);

    printf("\n\tEnter password: ");
    get_password(password);

    char* role = login(username, password);
    if (role != NULL) {
        decrypt_username(username);
        decrypt_role(role);
        system("cls");
        if (strcmp(role, "FRONT") == 0) {
            printcm("You are successfully logged in to frontend!\n");
        } else if (strcmp(role, "BOYS") == 0) {
            printcm("You are successfully logged in to Boys hostelend!\n");
        } else if (strcmp(role, "GIRLS") == 0) {
            printcm("You are successfully logged in to Girls hostelend!\n");
        }
        sleep(3);
        return role;
    }
    else {
        printcm("Login failed!\n");
        sleep(3);
        return NULL;
    }
}