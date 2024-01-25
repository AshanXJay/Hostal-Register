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

// Define a struct to hold the student details
typedef struct {
    char enroll_num[15];
    char destination[32];
    long time;
} RecordDetails;

// Get enrollment number
RecordDetails get_enrollment_number() {
    FILE *records = fopen("D:/GitHub/Hostal-Register/data/Records.txt", "r");
    if (records == NULL) {
        printf("Cannot open file\n");
        return(RecordDetails){"", "", 0};
    }

    RecordDetails record = {"", "", 0};
    char line[256];
    while (fgets(line, sizeof(line), records)) {
        // This loop will read the file line by line until the end, 
        // so at the end of the loop, 'line' will contain the last line of the file
    }

    // Assuming the line is in the format "enrollment_number destination time"
    sscanf(line, "%s %s %ld", record.enroll_num, record.destination, &record.time);

    fclose(records);
    return record;
}

// Define a struct to hold the student details
typedef struct {
    char lastname[50];
    char initials[50];
    char hostel[50];
} StudentDetails;

// Fetch student details
StudentDetails fetch_student_details(char* enroll_num) {
    FILE *file = fopen("D:/GitHub/Hostal-Register/data/Students.txt", "r");
    if (file == NULL) {
        printf("Cannot open file\n");
        return (StudentDetails){"", "", ""};
    }

    StudentDetails student = {"", "", ""};
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Assuming the line is in the format "enrollment_number name hostel"
        char temp_enroll_num[16];
        sscanf(line, "%s", temp_enroll_num);

        // If the enrollment number in the line matches the input enrollment number
        if (strcmp(temp_enroll_num, enroll_num) == 0) {
            sscanf(line, "%*s %s %s %s", student.lastname, student.initials, student.hostel);
            break;
        }
    }

    fclose(file);
    return student;
}

int main()
{
    char hostel_name[5]; 

    while (1)
    {
        if (new_records_exist())
        {
           RecordDetails record = get_enrollment_number();
           StudentDetails student = fetch_student_details(record.enroll_num);

           if (strcmp(hostel_name, student.hostel) == 0)
           {
               printf("Enrollment number: %s, Destination: %s, Time: %ld\n", record.enroll_num, record.destination, record.time);
           }
        }
        else
        {
            continue;
        }
    }

    return 0;
}