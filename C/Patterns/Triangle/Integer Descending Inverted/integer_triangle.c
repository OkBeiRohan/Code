/**
 * Program to print
 * 4 4 4 4
 *  3 3 3
 *   2 2
 *    1
 *
 * Algorithm:
 * 1. Take a number as input
 * 2. Loop from n to 1
 * 3. Loop from 1 to n-i
 * 4. Print space
 * 5. Loop from 1 to i
 * 6. Print i
 * 7. Print newline
 * 8. Stop
 */

#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n - i; j++)
            printf(" ");
        for (int j = i; j >= 1; j--)
            printf("%d ", i);
        printf("\n");
    }
    return 0;
}