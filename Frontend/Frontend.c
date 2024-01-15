#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Assuming a function that checks the enrollment number in the database
int check_enrollment(char *enroll_no) {
    FILE *s_data = fopen("D:/GitHub/Hostal-Register/Students.txt", "r");
    if (s_data == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    char enroll_data[15];
    while (fscanf(s_data, "%s", enroll_data) != EOF) {
        if (strcmp(enroll_data, enroll_no) == 0) {
            fclose(s_data);
            return 1;
        }
    }

    fclose(s_data);
    return 0;
}

// Assuming a function that adds a record to the database
void add_record(char *enroll_no, char *destination, time_t time) {
    // Implement the function to add a record to the database
}

int main() {
    char enroll_input[8];
    char enroll_no[15];
    char destination[50];
    time_t t;

    while(1) {
        printf("Enter student's enrollment number: ");
        scanf("%s", enroll_input);

        // Convert to uppercase
        for(int i = 0; enroll_input[i]; i++){
            enroll_input[i] = toupper(enroll_input[i]);
        }

        char degree[4], year[3], number[4];
        sscanf(enroll_input, "%3s%2s%3s", degree, year, number);
        sprintf(enroll_no, "UWU/%s/%s/%s", degree, year, number);
        printf("%s\n", enroll_no); 
              
        if(check_enrollment(enroll_no)) {
            printf("Enter destination: ");
            scanf("%s", destination);

            // Get the current time
            t = time(NULL);

            add_record(enroll_no, destination, t);

            printf("Successfully updated\n");
            break;
        } else {
            printf("Invalid Enrollment number\n");
        }
    }

    return 0;
}