#include <stdio.h>
#include <time.h>
#include <string.h>

// Assuming a function that checks the enrollment number in the database
int check_enrollment(char *enroll_no) {
    FILE *file = fopen("D:/GitHub/Hostal-Register/Students.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    char part[50];
    while (fscanf(file, " %[^,\n]", part) != EOF) {
        if (strcmp(part, enroll_no) == 0) {
            fclose(file);
            return 1;
        }
        // Skip to the next line
        fscanf(file, "%*[^\n]\n");
    }

    fclose(file);
    return 0;
}

// Assuming a function that adds a record to the database
void add_record(char *enroll_no, char *destination, time_t time) {
    // Implement the function to add a record to the database
}

int main() {
    char enroll_no[50];
    char destination[50];
    time_t t;

    while(1) {
        printf("Enter student's enrollment number: ");
        scanf("%s", enroll_no);

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