/**
 * Program to evaluate
 * 1!/n + 2!/(n-1) + 3!/(n-2) + .... till the denominator becomes zero
 *
 * Algorithm:
 * 1. Start
 * 2. Take the value of n as input
 * 3. Initialize sum = 0
 * 4. Run a loop from i = 1 to n
 *     a. Print i!/(n - (i - 1))
 *     b. Find factorial of i and divide it by (n - (i - 1))
 *     c. Add the result to sum
 * 5. Print sum
 * 6. Stop
 */

#include <stdio.h>

double factorial(int n)
{
    float fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

int main()
{
    int n;
    double sum = 0;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if (i != 1)
            printf(" + ");
        printf("%d!/(%d - %d)", i, n, i - 1);
        sum += factorial(i) / (n - (i - 1));
    }
    printf(" = %lf", sum);
    return 0;
}