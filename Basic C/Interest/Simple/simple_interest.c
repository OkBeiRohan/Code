/**
 * Simple Interest
 */

#include <stdio.h>

int main()
{
    double principle, rate, time, SI;

    printf("Enter principle (amount): ");
    scanf("%lf", &principle);

    printf("Enter time: ");
    scanf("%lf", &time);

    printf("Enter rate: ");
    scanf("%lf", &rate);

    SI = (principle * time * rate) / 100;

    printf("Simple Interest = %lf", SI);

    return 0;
}