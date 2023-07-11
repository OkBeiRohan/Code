/**
 * Compound Interest
 */

#include <stdio.h>
#include <math.h>

int main()
{
    double principle, rate, time, CI;

    printf("Enter principle (amount): ");
    scanf("%lf", &principle);

    printf("Enter time: ");
    scanf("%lf", &time);

    printf("Enter rate: ");
    scanf("%lf", &rate);

    CI = principle * (pow((1 + rate / 100), time));

    printf("Compound Interest = %lf", CI);

    return 0;
}