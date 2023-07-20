/**
 * Program to find the largest of two numbers using conditional operator
 */

#include <stdio.h>

int main()
{
    int num1, num2, max;
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    max = (num1 > num2) ? num1 : num2;
    printf("Largest number: %d", max);
    return 0;
}