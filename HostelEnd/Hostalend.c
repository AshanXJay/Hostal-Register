
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char hostel_name[100], enroll_num[100];
    printf("Enter the hostel name: ");
    scanf("%s", hostel_name);

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

int new_records_exist()
{
    
    return 1;
}

void get_enrollment_number(char *enroll_num)
{
    
    strcpy(enroll_num, "12345");
}

char *fetch_student_details(char *enroll_num)
{
    
    return "enroll_num=12345&name=John&hostel=hostelA";
}

int student_belongs_to_hostel_A(char *student_details)
{
   
    return strstr(student_details, "hostel=hostelA") != NULL;
}