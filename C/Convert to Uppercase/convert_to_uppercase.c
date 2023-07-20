/**
 * To Uppercase
 *
 * Algorithm:
 * 1. Take a string as input
 * 2. Loop through the string
 * 3. If the character is lowercase, subtract 32 from it
 * 4. Print the string
 * 5. Stop
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