/**
 * Check if number is prime using recursion
 */

#include <stdio.h>

int prime(int n, int i)
{
    if (n <= 2)
        return (n == 2) ? 1 : 0;
    if (n % i == 0)
        return 0;
    if (n == (i + 1))
        return 1;
    return prime(n, i + 1);
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("The number is ");
    prime(n, 2) ? printf("prime.") : printf("not prime.");
    return 0;
}