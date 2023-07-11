/**
 * Program to find the third angle of a triangle
 */

#include <stdio.h>

int main()
{
    int angle1, angle2, angle3;
    printf("Enter first angle: ");
    scanf("%d", &angle1);
    printf("Enter second angle: ");
    scanf("%d", &angle2);
    angle3 = 180 - (angle1 + angle2);
    printf("Third angle: %d", angle3);
    return 0;
}