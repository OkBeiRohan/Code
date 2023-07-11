/**
 * Program to print
 * 1
 * 2 2
 * 3 3 3
 * 4 4 4 4
 */

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the value of n (single digit): ");
    scanf("%d", &n);
    if (n > 9)
    {
        printf("Enter a single digit number, changing to default value of 5.\n");
        n = 5;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            printf("%d ", i);
        printf("\n");
    }
    return 0;
}
