/**
 * Program to convert temperature in Celcius to Fahrenheit
 */

#include <stdio.h>

int main()
{
    double celcius;
    printf("Enter temperature in Celcius: ");
    scanf("%lf", &celcius);
    printf("Temperature in Fahrenheit: %lf", (celcius * 9 / 5) + 32);
    return 0;
}