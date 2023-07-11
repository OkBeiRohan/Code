/**
 * Check if the number is divisible by two another numbers
 */

#include <stdio.h>

int main()
{
    double num, divisor1, divisor2;
    printf("Enter a number: ");
    scanf("%lf", &num);
    printf("Enter first divisor: ");
    scanf("%lf", &divisor1);
    printf("Enter second divisor: ");
    scanf("%lf", &divisor2);
    if (num / divisor1 == (int)(num / divisor1) && num / divisor2 == (int)(num / divisor2))
        printf("The number is divisible by both %lf and %lf", divisor1, divisor2);
    else if (num / divisor1 == (int)(num / divisor1))
        printf("The number is divisible by %lf", divisor1);
    else if (num / divisor2 == (int)(num / divisor2))
        printf("The number is divisible by %lf", divisor2);
    else
        printf("The number is not divisible by %lf and %lf", divisor1, divisor2);
}