/**
 * Program to print
 * 4 4 4 4
 *  3 3 3
 *   2 2
 *    1
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