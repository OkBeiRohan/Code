/**
 * Find Average, Total and Percentage of Five Subjects
 */

#include <stdio.h>

int main()
{
    int sub1, sub2, sub3, sub4, sub5;
    double total, average, percentage;

    printf("Enter marks of five subjects: ");
    scanf("%d%d%d%d%d", &sub1, &sub2, &sub3, &sub4, &sub5);

    total = sub1 + sub2 + sub3 + sub4 + sub5;
    average = total / 5.0;
    percentage = (total / 500.0) * 100;

    printf("Total marks = %.2lf\n", total);
    printf("Average marks = %.2lf\n", average);
    printf("Percentage = %.2lf", percentage);

    return 0;
}