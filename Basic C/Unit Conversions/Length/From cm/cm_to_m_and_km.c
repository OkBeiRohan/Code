/**
 * Program to convert cm to m and km
 */

#include <stdio.h>

int main()
{
    double cm;
    printf("Enter length in cm: ");
    scanf("%lf", &cm);
    printf("Length in m: %lf\nLength in km: %lf", cm / 100, cm / 100000);
    return 0;
}