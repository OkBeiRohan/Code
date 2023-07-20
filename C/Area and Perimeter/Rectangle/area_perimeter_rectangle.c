/**
 * Program to find the area and perimeter of a rectangle
 */

#include <stdio.h>

int main()
{
    double l, b;
    printf("Enter length and breadth of the rectangle: ");
    scanf("%lf%lf", &l, &b);
    printf("Area: %lf\nPerimeter: %g", l * b, 2 * (l + b));
    return 0;
}