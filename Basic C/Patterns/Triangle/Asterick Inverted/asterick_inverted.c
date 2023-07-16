/**
 * Program to print
 * * * * *
 *  * * *
 *   * *
 *    *
 * 
 * Algorithm:
 * 1. Take a number as input
 * 2. Loop from n to 1
 * 3. Loop from 1 to n-i
 * 4. Print space
 * 5. Loop from 1 to i
 * 6. Print *
 * 7. Print newline
 * 8. Stop
 */

#include <stdio.h>

int main()
{
    int i, j, k, n;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    for (i = n; i >= 1; i--)
    {
        for (j = 1; j <= n - i; j++)
            printf(" ");
        for (k = 1; k <= i; k++)
            printf("* ");
        printf("\n");
    }
    return 0;
}