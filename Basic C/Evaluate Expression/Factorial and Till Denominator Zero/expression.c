/**
 * Program to evaluate
 * 1!/n + 2!/(n-1) + 3!/(n-2) + .... till the denominator becomes zero
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
        sum += factorial(i) / (n - i + 1);
    printf("Sum = %lf", sum);
    return 0;
}