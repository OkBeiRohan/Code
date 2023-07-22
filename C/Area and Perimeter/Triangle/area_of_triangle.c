/**
 * Program to find the area of a triangle
 *
 * Algorithm:
 * 1. Start
 * 2. Input base and height of the triangle
 * 3. area = 0.5 * base * height
 * 4. Print area
 * 5. Stop
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