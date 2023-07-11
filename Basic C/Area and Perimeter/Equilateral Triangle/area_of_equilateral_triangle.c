/**
 * Area of Equilateral Triangle
 */

#include <stdio.h>
#include <math.h>

int main()
{
    double side, area;
    printf("Enter side of the triangle: ");
    scanf("%lf", &side);
    area = (sqrt(3) / 4) * side * side;
    printf("Area of the triangle: %lf", area);
    return 0;
}