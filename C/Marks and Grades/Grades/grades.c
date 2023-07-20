/**
 * Program to generate a structured grade card with individual marks, grades and total marks, grade, gpa, percentage, average
 */

#include <stdio.h>

enum subjects
{
    MATHS,
    PHYSICS,
    CHEMISTRY,
    BIOLOGY,
    ENGLISH,
    COMPUTER
};

struct subject
{
    enum subjects subject;
    int marks;
    char grade;
};

int main()
{
    struct subject subjects[6];
    int total_marks = 0;
    float percentage = 0.0;
    float average = 0.0;
    float gpa = 0.0;
    for (int i = 0; i < 6; i++)
    {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%d", &subjects[i].marks);
        total_marks += subjects[i].marks;
    }
    percentage = (float)total_marks / 6;
    average = (float)total_marks / 6;
    gpa = (float)total_marks / 600 * 10;
    printf("Total Marks: %d\n", total_marks);
    printf("Percentage: %.2f\n", percentage);
    printf("Average: %.2f\n", average);
    printf("GPA: %.2f\n", gpa);
    printf("Grade Card\n");
    printf("Subject\t\tMarks\t\tGrade\n");
    for (int i = 0; i < 6; i++)
    {
        if (subjects[i].marks >= 90)
            subjects[i].grade = 'A';
        else if (subjects[i].marks >= 80)
            subjects[i].grade = 'B';
        else if (subjects[i].marks >= 70)
            subjects[i].grade = 'C';
        else if (subjects[i].marks >= 60)
            subjects[i].grade = 'D';
        else if (subjects[i].marks >= 50)
            subjects[i].grade = 'E';
        else
            subjects[i].grade = 'F';
        printf("%d\t\t%d\t\t%c\n", i + 1, subjects[i].marks, subjects[i].grade);
    }
    return 0;
}