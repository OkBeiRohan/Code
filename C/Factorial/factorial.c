/**
 * Factorial
 */

#include <stdio.h>

int factorial(int number)
{
    if (number == 0)
        return 1;
    else
        return number * factorial(number - 1);
}

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("Factorial of %d is %d", number, factorial(number));
    return 0;
}