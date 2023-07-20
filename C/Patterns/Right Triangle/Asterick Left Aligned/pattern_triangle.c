/**
 * Program to print
 * *
 * * *
 * * * *
 * * * * *
 * * * * * *
 * 
 * Algorithm:
 * 1. Take a number as input
 * 2. Loop from 1 to n
 * 3. Loop from 1 to i
 * 4. Print *
 * 5. Print newline
 * 6. Stop
 */

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }
    return 0;
}
