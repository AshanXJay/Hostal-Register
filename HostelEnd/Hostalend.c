#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Check if new records exist
int countLines(FILE *records) {
    int count = 0;
    char c;

    // Extract characters from the file and store in character c
    for (c = getc(records); c != EOF; c = getc(records)) {
        if (c == '\n') { // Increment count if this character is newline
            count = count + 1;
        }
    }

    return count;
}

int new_records_exist() {
    static int prevCount = 0;
    int newCount;
    FILE *records = fopen("D:/GitHub/Hostal-Register/data/Records.txt", "r");

    if (records == NULL) {
        printf("Cannot open file \n");
        exit(0);
    }

    newCount = countLines(records);
    fclose(records);

    if (newCount > prevCount) {
        prevCount = newCount;
        return 1; // new records exist
    }

    return 0; // no new records
}

// Get enrollment number
void get_enrollment_number(char* enroll_num) {
    // Replace with your actual logic
    strcpy(enroll_num, "123456"); // Assuming enrollment number is 123456 for this example
}

// Fetch student details
char* fetch_student_details(char* enroll_num) {
    
    return "Student Details"; // Assuming student details are "Student Details" for this example
}

// Check if student belongs to hostel A
int student_belongs_to_hostel_A(char* student_details) {
    // Replace with your actual logic
    return 1; // Assuming student always belongs to hostel A for this example
}

int main()
{
    FILE *file;
    char hostel_name[100], enroll_num[100];
    /* printf("Enter the hostel name: ");
    scanf("%s", hostel_name); */

    while (1)
    {
        if (new_records_exist())
        {
            get_enrollment_number(enroll_num);
        }
        else
        {
            continue;
        }

        char *student_details = fetch_student_details(enroll_num);

        if (student_belongs_to_hostel_A(student_details))
        {
            printf("Enrollment number: %s, Destination: %s, Time: %s\n", enroll_num, "hostel_name", "time");
        }
        else
        {
            printf("Enrollment number: %s, Destination: %s, Time: %s\n", enroll_num, "hostel_name", "time");
        }
    }

    return 0;
}