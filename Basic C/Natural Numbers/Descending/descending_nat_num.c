/**
 * Print natural numbers from n to 1
 */

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    for (int i = n; i >= 1; i--)
        printf("%d ", i);
    return 0;
}