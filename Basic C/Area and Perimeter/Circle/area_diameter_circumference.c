/**
 * Program to find the area, diameter and circumference of a circle
 */

#include <stdio.h>

int main()
{
    double r;
    printf("Enter radius of the circle: ");
    scanf("%lf", &r);
    printf("Area: %lf\nDiameter: %lf\nCircumference: %lf", 3.14 * r * r, 2 * r, 2 * 3.14 * r);
    return 0;
}