/**
 * Number of days in the month
 */

#include <stdio.h>

enum month
{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December = 12
};

int main()
{
    enum month m;
    int year;
    printf("Enter month number (1-12): ");
    scanf("%d", &m);
    if (m <= 0 || m > 12)
    {
        printf("Invalid input! Please enter month number between 1-12.");
        return 0;
    }
    if (m == 2)
    {
        printf("Enter year: ");
        scanf("%d", &year);
    }
    switch (m)
    {
    case January:
        printf("31 days");
        break;
    case February:
        if (year % 4 == 0)
            printf("29 days");
        else
            printf("28 days");
        break;
    case March:
        printf("31 days");
        break;
    case April:
        printf("30 days");
        break;
    case May:
        printf("31 days");
        break;
    case June:
        printf("30 days");
        break;
    case July:
        printf("31 days");
        break;
    case August:
        printf("31 days");
        break;
    case September:
        printf("30 days");
        break;
    case October:
        printf("31 days");
        break;
    case November:
        printf("30 days");
        break;
    case December:
        printf("31 days");
        break;
    default:
        printf("Invalid input! Please enter month number between 1-12.");
    }
    return 0;
}