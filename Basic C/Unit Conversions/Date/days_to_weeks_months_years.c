/**
 * Program to convert days into weeks, months, years and decades
 */

#include <stdio.h>

int main()
{
    int days;
    printf("Enter number of days: ");
    scanf("%d", &days);
    printf("Weeks: %d\nMonths: %d\nYears: %d\nDecades: %d", days / 7, days / 30, days / 365, days / 3650);
    return 0;
}