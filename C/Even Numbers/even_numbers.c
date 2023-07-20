/**
 * Print even numbers
 */

#include <stdio.h>

int main()
{
    int n, i = 2;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    while (i <= n)
    {
        printf("%d ", i);
        i += 2;
    }
    return 0;
}