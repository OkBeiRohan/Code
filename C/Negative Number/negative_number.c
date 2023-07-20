/**
 * Check whether a number is negative
 */

#include <stdio.h>

int main()
{
    double num;
    printf("Enter a number: ");
    scanf("%lf", &num);
    if (num < 0)
        printf("The number is negative.");
    else if (num == 0)
        printf("The number is zero");
    else
        printf("The number is positive");
    return 0;
}