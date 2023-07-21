/**
 * Use MISRA C Guidelines
 * Create a student structure with rno, name, dob, five subject marks. Date of birth has to be a structure with dd, mm and yy members. Accept five student details and print the marks summary of all students as follows.
 * Roll No	Name	Date of Birth	M1	M2	M3	M4	M5	Total
 *
 * Pass Count:
 * Fail Count:
 * Total Percentage:
 *
 * Algorithm:
 * 1. Start
 * 2. Declare structure date with dd, mm, yy
 * 3. Declare structure student with rno, name, dob, marks
 * 4. Declare variables i, j, pass_count, fail_count, total_percentage
 * 5. Read rno, name, dob, marks
 * 6. Calculate pass_count, fail_count, total_percentage
 * 7. Display rno, name, dob, marks, total
 * 8. Display pass_count, fail_count, total_percentage
 * 9. Stop
 */

#include <stdio.h>
#include <string.h>

struct date
{
    int dd;
    int mm;
    int yy;
};

struct student
{
    int rno;
    char name[20];
    struct date dob;
    int marks[5];
};

int main()
{
    struct student s[5];
    int i, j, pass_count, fail_count;
    float total_percentage;
    for (i = 0; i < 5; i++)
    {
        printf("Enter the roll number: ");
        scanf("%d", &s[i].rno);
        printf("Enter the name: ");
        scanf("%s", s[i].name);
        printf("Enter the date of birth (dd mm yy): ");
        scanf("%d %d %d", &s[i].dob.dd, &s[i].dob.mm, &s[i].dob.yy);
        printf("Enter the marks of five subjects: ");
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &s[i].marks[j]);
        }
    }
    printf("Roll No\tName\t\tDate of Birth\tM1\tM2\tM3\tM4\tM5\tTotal\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d\t%s\t\t%d/%d/%d\t", s[i].rno, s[i].name, s[i].dob.dd, s[i].dob.mm, s[i].dob.yy);
        for (j = 0; j < 5; j++)
        {
            printf("%d\t", s[i].marks[j]);
        }
        printf("%d\n", s[i].marks[0] + s[i].marks[1] + s[i].marks[2] + s[i].marks[3] + s[i].marks[4]);
    }
    pass_count = 0;
    fail_count = 0;
    for (i = 0; i < 5; i++)
    {
        if (s[i].marks[0] >= 50 && s[i].marks[1] >= 50 && s[i].marks[2] >= 50 && s[i].marks[3] >= 50 && s[i].marks[4] >= 50)
        {
            pass_count++;
        }
        else
        {
            fail_count++;
        }
    }
    total_percentage = (pass_count / 5.0) * 100;
    printf("Pass Count: %d\n", pass_count);
    printf("Fail Count: %d\n", fail_count);
    printf("Total Percentage: %f\n", total_percentage);
    return 0;
}