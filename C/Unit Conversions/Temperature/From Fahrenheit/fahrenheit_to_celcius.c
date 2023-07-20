/**
 * Program to convert temperature in Fahrenheit to Celcius
 */

#include <stdio.h>

int main()
{
    double fahrenheit;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit);
    printf("Temperature in Celcius: %lf", (fahrenheit - 32) * 5 / 9);
    return 0;
}