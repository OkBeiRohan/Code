/**
 * Program to find power of a number
 */

#include <stdio.h>
#include <math.h>

int main()
{
    double base, exponent;
    printf("Enter base: ");
    scanf("%lf", &base);
    printf("Enter exponent: ");
    scanf("%lf", &exponent);
    printf("Result: %lf", pow(base, exponent));
    return 0;
}