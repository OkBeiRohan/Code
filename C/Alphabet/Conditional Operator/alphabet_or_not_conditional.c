/**
 * Program to check whether a character is an alphabet or not using conditional operator
 */

#include <stdio.h>

int main()
{
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);
    (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ? printf("%c is an alphabet", c) : printf("%c is not an alphabet", c);
    return 0;
}