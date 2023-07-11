/**
 * Program to find the area of a triangle
 */

#include <stdio.h>

int main()
{
    double base, height, area;
    printf("Enter base of the triangle: ");
    scanf("%lf", &base);
    printf("Enter height of the triangle: ");
    scanf("%lf", &height);
    area = 0.5 * base * height;
    printf("Area of the triangle: %lf", area);
    return 0;
}