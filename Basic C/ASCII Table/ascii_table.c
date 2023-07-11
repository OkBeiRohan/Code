/**
 * Program to print ASCII table from 'a' to 'z'
 */

#include <stdio.h>

int main()
{
    char c;
    printf("\tASCII table from 'a' to 'z'\n\n");
    printf("Decimal\t\tASCII\t\tHexadecimal\n");
    for (c = 'a'; c <= 'z'; c++)
        printf("%d\t\t%c\t\t%x\n", c, c, c);
    return 0;
}