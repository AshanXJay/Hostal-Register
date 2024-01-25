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
void get_enrollment_number(char* enroll_num[15], char* destination[32], double* time) {
    FILE *records = fopen("D:/GitHub/Hostal-Register/data/Records.txt", "r");
    if (records == NULL) {
        printf("Cannot open file\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), records)) {
        // This loop will read the file line by line until the end, 
        // so at the end of the loop, 'line' will contain the last line of the file
    }

    // Assuming the line is in the format "enrollment_number destination time"
    sscanf(line, "%s %s %ld", enroll_num[15], destination[32], time);

    fclose(records);
}

// Fetch student details
// Define a struct to hold the student details
typedef struct {
    char name[50];
    char hostel[50];
} StudentDetails;

// Fetch student details
StudentDetails fetch_student_details(char* enroll_num) {
    FILE *file = fopen("Students.txt", "r");
    if (file == NULL) {
        printf("Cannot open file\n");
        return (StudentDetails){"", ""};
    }

    StudentDetails details = {"", ""};
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Assuming the line is in the format "enrollment_number name hostel"
        char temp_enroll_num[16];
        sscanf(line, "%15s", temp_enroll_num);

        // If the enrollment number in the line matches the input enrollment number
        if (strcmp(temp_enroll_num, enroll_num) == 0) {
            sscanf(line, "%*s %49[^0-9] %49s", details.name, details.hostel);
            break;
        }
    }

    fclose(file);
    return details;
}

int main()
{
    FILE *file;
    char enroll_num[15], destination[32], hostel_name[5]; 
    double time;
    printf("Enter the hostel name: ");
    scanf("%s", hostel_name);

    while (1)
    {
        if (new_records_exist())
        {
            get_enrollment_number(enroll_num, destination, &time);
        }
        else
        {
            continue;
        }

        char *student_details = fetch_student_details(enroll_num);

        if (student_belongs_to_hostel_A(student_details))
        {
            printf("Enrollment number: %s, Destination: %s, Time: %ld\n", enroll_num, "hostel_name", time);
        }
        else
        {
            printf("Enrollment number: %s, Destination: %s, Time: %ld\n", enroll_num, "hostel_name", time);
        }
    }

    return 0;
}