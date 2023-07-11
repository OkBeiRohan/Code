/**
 * Convert a string into coded with +3 ASCII character
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i;
    printf("Enter a string: ");
    gets(str);
    for (i = 0; str[i] != '\0'; i++)
    {
        str[i] = str[i] + 3;
    }
    printf("Encoded string: %s", str);
    return 0;
}