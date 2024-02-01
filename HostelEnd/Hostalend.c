#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "../additionals/print.c"  


// Function to count the number of lines in a file
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

// Function to check if new records exist in the file
int new_records_exist() {
    static int prevCount = 0;
    int newCount;
    FILE *records = fopen("//DESKTOP-QE6QOLV/data/Records.txt", "r");

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

// Struct to hold the record details
typedef struct {
    char enroll_num[15];
    char destination[32];
    long time;
} RecordDetails;

// Function to get the last record's details from the file
RecordDetails get_enrollment_number() {
    FILE *records = fopen("//DESKTOP-QE6QOLV/data/Records.txt", "r");
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

    // Assuming the line is in the format "enrollment_number,destination,time"
    char *token = strtok(line, "`");
    if (token != NULL) {
        strncpy(record.enroll_num, token, sizeof(record.enroll_num));
        token = strtok(NULL, "`");
    }
    if (token != NULL) {
        strncpy(record.destination, token, sizeof(record.destination));
        token = strtok(NULL, "`");
    }
    if (token != NULL) {
        record.time = atol(token);
    }

    fclose(records);
    return record;
}

// Struct to hold the student details
typedef struct {
    char name[100];
    char hostel[50];
} StudentDetails;

// Function to fetch the student details based on the enrollment number
StudentDetails fetch_student_details(char* enroll_num) {
    FILE *file = fopen("//DESKTOP-QE6QOLV/data/Students.txt", "r");
    if (file == NULL) {
        printf("Cannot open file\n");
        return (StudentDetails){"", ""};
    }

    StudentDetails student = {"", ""};
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Assuming the line is in the format "enrollment_number,name,hostel"
        char *temp_enroll_num = strtok(line, "`");
        char *name = strtok(NULL, "`");
        char *hostel = strtok(NULL, "\n");

        // If the enrollment number in the line matches the input enrollment number
        if (temp_enroll_num != NULL && strcmp(temp_enroll_num, enroll_num) == 0) {
            if (name != NULL) {
                strncpy(student.name, name, sizeof(student.name));
            }
            if (hostel != NULL) {
                strncpy(student.hostel, hostel, sizeof(student.hostel));
            }
            break;
        }
    }

    fclose(file);
    return student;
}

// Main function
int main(){
    int hostel_no; // Variable to hold the hostel number
    char hostel[6];

        system("cls");
        printf("\n\n");
        printc("Select hostel on Duty");

        printf("\n\n\n\n\n\n\n");

        printf("\n\t1.BOYS Hostel\n\t2.GIRLS Hostel\n\n\tEnter Hostel Number:");
        scanf("%d", &hostel_no); // Read the input from the user

        if(hostel_no==1){
            system("cls");
            strcpy(hostel, "BOYS");
            printcm("BOYS Hostel Selected!\n");
            sleep(2);
        }
        else if(hostel_no == 2) {
            strcpy(hostel, "GIRLS");
            system("cls");
            printcm("GIRLS Hostel Selected!\n");
            sleep(2);        
            }
        else{
            system("cls");
            printcm("Wrong Selection!\n");
            printcm("Please select correct hostel");
            sleep(2);
            main();
        }
    
    while (1)
    {
        while (new_records_exist()) {
            // Fetch the last record and the corresponding student details
            RecordDetails record = get_enrollment_number();
            StudentDetails student = fetch_student_details(record.enroll_num);

            // Convert the timestamp to a human-readable format
            char time_str[20]; // Buffer to hold the formatted time
            time_t time = (time_t)record.time; // Convert long to time_t
            struct tm *tm_info = localtime(&time);
            strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", tm_info);

            system("cls");
            printf("\n\n");
            printc("Signouts");
            printf("\n\n");

            if(strcmp(student.hostel, hostel) == 0) {
                static int count = 1;
                printf("%d) Enrollment number: %s, Student Name: %s, Destination: %s, Time: %s\n\n", count, record.enroll_num, student.name, record.destination, time_str);
                count++;
            }
        }

    }

    return 0;
}
