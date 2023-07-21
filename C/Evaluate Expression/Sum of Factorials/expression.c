/**
 * Program to evaluate
 * 1! + 2! + 3! + 4! + ... + n!
 *
 * Algorithm:
 * 1. Start
 * 2. Take the value of n as input
 * 3. Initialize sum = 0
 * 4. Run a loop from i = 1 to n
 *    a. Print i!
 *    b. Find factorial of i and add it to sum
 * 5. Print sum
 * 6. Stop
 */

#include <stdio.h>

unsigned int factorial(unsigned int);

int main()
{
    unsigned int n, sum = 0;
    printf("Enter the value of n: ");
    scanf("%u", &n);
    for (unsigned int i = 1; i <= n; i++)
    {
        if (i != 1)
            printf(" + ");
        printf("%u!", i);
        sum += factorial(i);
    }
    printf(" = %u", sum);
    return 0;
}

unsigned int factorial(unsigned int n)
{
    unsigned int fact = 1;
    for (unsigned int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}