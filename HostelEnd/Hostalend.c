#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

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

// Struct to hold the record details
typedef struct {
    char enroll_num[15];
    char destination[32];
    long time;
} RecordDetails;

// Function to get the last record's details from the file
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

// Struct to hold the student details
typedef struct {
    char lastname[50];
    char initials[50];
    char hostel[50];
} StudentDetails;

// Function to fetch the student details based on the enrollment number
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

// Main function
int main()
{
    int hostel_no; // Variable to hold the hostel number
    char hostel[5];

    printf("Enter the number of the hostel in duty"\n);
    printf("1.Boys\n");
    printf("2.girls\n");

    int hostel_no; // Variable to hold the hostel number
    char hostel[5];

    printf("Enter the number of the hostel in duty (1 for Boys hostel, 2 for Girls' hostel): ");
    scanf("%d", &hostel_no); // Read the input from the user


    
    int hostel_no; // Variable to hold the hostel number
    char hostel[5];

    printf("Enter the number of the hostel in duty (1 for Boys hostel, 2 for Girls' hostel): ");
    scanf("%d", &hostel_no); // Read the input from the user
    printf("int hostel_no; // Variable to hold the hostel number
    char hostel[5];

    printf("Enter the number of the hostel in duty (1 for Boys hostel, 2 for Girls' hostel): ");
    scanf("%d", &hostel_no); // Read the input from the user
    scanf("%d", &hostel_no); // Read the input from the user

    // Validation loop
    while(hostel_no < 1 || hostel_no > 2) {
        printf("Invalid input. Please enter 1 for Boys hostel or 2 for Girls' hostel.\n");
        scanf("%d", &hostel_no);
    }

    // Display the selected hostel
    printf("You selected hostel number: %d\n", hostel_no);
    if(hostel_no == 1) {
        strcpy(hostel, "BOYS");
        printf("You selected Boys hostel.\n");
    } else if(hostel_no == 2) {
        strcpy(hostel, "GIRLS");
        printf("You selected Girls' hostel.\n");
    }
    
    while (1)
    {
        if (new_records_exist())
        {
           // Fetch the last record and the corresponding student details
           RecordDetails record = get_enrollment_number();
           StudentDetails student = fetch_student_details(record.enroll_num);

           // Convert the timestamp to a human-readable format
           char time_str[20]; // Buffer to hold the formatted time
           time_t time = (time_t)record.time; // Convert long to time_t
           struct tm *tm_info = localtime(&time);
           strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", tm_info);

            if(strcmp(student.hostel,hostel)==0){
            printf("Student Name: %s %s, Enrollment number: %s, Destination: %s, Time: %s\n", student.lastname, student.initials, record.enroll_num, record.destination, time_str);
            }
        }
    }

    return 0;
}
