/**
 * Reverse a string using stack
 */

#include <stdio.h>

int main()
{
    char str[100], rev[100];
    int top = -1;
    printf("Enter a string: ");
    gets(str);
    for (int i = 0; str[i] != '\0'; i++)
        top++;
    for (int i = 0; i <= top; i++)
        rev[i] = str[top - i];
    printf("Reversed string: %s", rev);
    return 0;
}