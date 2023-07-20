/**
 * Check if number is prime using recursion
 */

#include <stdio.h>
#include <stdbool.h>

bool prime(int n, int i)
{
    if (n <= 2)
        return (n == 2) ? true : false;
    if (n % i == 0)
        return false;
    if (n == (i + 1))
        return true;
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