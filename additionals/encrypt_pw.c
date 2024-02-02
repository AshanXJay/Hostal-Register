#include <stdio.h>
#include <ctype.h>
#include <string.h>

void caesar_cipher(char* str, int shift) {
    for(int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if(isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            str[i] = ((c - base + shift) % 26) + base;
        } else if(isdigit(c)) {
            str[i] = ((c - '0' + shift) % 10) + '0';
        }
    }
}

int main() {
    FILE* file = fopen("D:/GitHub/Hostal-Register/data/Users.txt", "r");
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    char line[256];
    char new_content[1024] = ""; // Buffer to hold the new file content

    while (fgets(line, sizeof(line), file)) {
        caesar_cipher(line, 3);

        strcat(new_content, line);
    }

    fclose(file);

    // Write the new content to the file
    file = fopen("D:/GitHub/Hostal-Register/data/Users_Encrypt.txt", "w");
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }
    fputs(new_content, file);
    fclose(file);

    return 0;
}