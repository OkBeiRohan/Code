/**
 * To Uppercase
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    printf("Enter a string: ");
    gets(str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
    printf("String in uppercase: %s", str);
    return 0;
}