#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

char* login(char* entered_username, char* entered_password) {
    FILE* file = fopen("D:/SYSTEM/Desktop/users.txt", "r");
    if (file == NULL) {
        printf("Could not open file\n");
        return NULL;
    }

    char line[MAX_SIZE];
    while (fgets(line, sizeof(line), file)) {
        char username[MAX_SIZE], password[MAX_SIZE], role[MAX_SIZE];
        sscanf(line, "%s %s %s", username, password, role);

        if (strcmp(username, entered_username) == 0 && strcmp(password, entered_password) == 0) {
            fclose(file);
            return strdup(role);
        }
    }

    fclose(file);
    printf("Invalid username or password\n");
    return NULL;
}

int main() {
        char username[MAX_SIZE];
        char password[MAX_SIZE];

        printf("Enter username: ");
        scanf("%s", username);

        printf("Enter password: ");
        scanf("%s", password);

        char* role = login(username, password);
        if (role != NULL) {
            printf("Logged in as role: %s\n", role);
            free(role);
        }
        return 0;
}