#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

//#include "print.c"

// Function to check if the enrollment number exists in the database
int check_enrollment(char *enroll_no) {
    // Open the file that contains student data
    FILE *s_data = fopen("D:/GitHub/Hostal-Register/data/Students.txt", "r");
    if (s_data == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    char enroll_data[15];
    // Read each line from the file
    while (fscanf(s_data, "%s", enroll_data) != EOF) {
        // If the read enrollment number matches the input enrollment number
        if (strcmp(enroll_data, enroll_no) == 0) {
            // Close the file and return 1 (true)
            fclose(s_data);
            return 1;
        }
    }

    // Close the file and return 0 (false) if no match was found
    fclose(s_data);
    return 0;
}

// Function to add a record to the database
void add_record(char *enroll_no, char *destination, time_t t){
    CURL *curl;
    CURLcode res;
    FILE *fp;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        fp = fopen("Records.txt","w+");
        if (fp == NULL) {
            printf("Failed to open the file.\n");
            return;
        }

        // Write the enrollment number, destination, and current time to the file
        // Use commas as separators
        fprintf(fp,"%s`",enroll_no);
        fprintf(fp,"%s`",destination);
        fprintf(fp, "%ld\n", (long)t);
        fclose(fp);

        curl_easy_setopt(curl, CURLOPT_URL, "ftpupload.net/Records.txt");
        curl_easy_setopt(curl, CURLOPT_USERNAME, "if0_35883868");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "M5CrjBlJHCogh");
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        fp = fopen("Records.txt", "rb");
        if (fp == NULL) {
            printf("Failed to open the file.\n");
            return;
        }

        curl_easy_setopt(curl, CURLOPT_READDATA, fp);
        res = curl_easy_perform(curl);

        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        fclose(fp);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

int main() {
    char enroll_input[8];
    char enroll_no[15];
    char destination[50];
    time_t t;

    while(1) {
        printf("Enter student's enrollment number: ");
        scanf("%s", enroll_input);

        // Convert the input enrollment number to uppercase
        for(int i = 0; enroll_input[i]; i++){
            enroll_input[i] = toupper(enroll_input[i]);
        }

        // Split the input enrollment number into degree, year, and number
        char degree[4], year[3], number[4];
        sscanf(enroll_input, "%3s%2s%3s", degree, year, number);
        // Format the enrollment number
        sprintf(enroll_no, "UWU/%s/%s/%s", degree, year, number);
        printf("%s\n", enroll_no); 

        // If the enrollment number exists in the database
        if(check_enrollment(enroll_no)) {
            printf("Enter destination: ");
            scanf("%s", destination);

            // Get the current time
            t = time(NULL);

            // Add a record to the database
            add_record(enroll_no, destination, t);

            printf("Successfully updated\n");
        } else {
            printf("Invalid Enrollment number\n");
        }
    }

    return 0;
}
