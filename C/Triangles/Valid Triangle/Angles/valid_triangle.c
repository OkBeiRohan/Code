/**
 * Check if triangle is valid from angles
 */

#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Enter three angles of triangle: ");
    scanf("%d%d%d", &a, &b, &c);
    if (a + b + c == 180)
        printf("Triangle is valid.");
    else
        printf("Triangle is not valid.");
    return 0;
}