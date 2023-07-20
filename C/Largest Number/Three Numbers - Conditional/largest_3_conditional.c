/**
 * Program to find the largest of 3 numbers using conditional operator
 */

#include <stdio.h>

int main()
{
    int num1, num2, num3, max;
    printf("Enter three numbers: ");
    scanf("%d%d%d", &num1, &num2, &num3);
    max = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3);
    printf("Largest number: %d", max);
    return 0;
}