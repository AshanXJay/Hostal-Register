#include <stdio.h>
#include <time.h>

// Assuming a function that checks the enrollment number in the database
int check_enrollment(char *enroll_no) {
    // Implement the function to check the enrollment number in the database
    // Return 1 if the enrollment number is in the database, otherwise return 0
    return 1;
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