/**
 * Print Week Day
 */

#include <stdio.h>

enum week
{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

int main()
{
    enum week day;
    printf("Enter day number (0-6): ");
    scanf("%d", &day);
    switch (day)
    {
    case Monday:
        printf("Monday");
        break;
    case Tuesday:
        printf("Tuesday");
        break;
    case Wednesday:
        printf("Wednesday");
        break;
    case Thursday:
        printf("Thursday");
        break;
    case Friday:
        printf("Friday");
        break;
    case Saturday:
        printf("Saturday");
        break;
    case Sunday:
        printf("Sunday");
        break;
    default:
        printf("Invalid input! Please enter day number between 0-6.");
    }
    return 0;
}