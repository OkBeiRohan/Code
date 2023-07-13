/**
 * Encode a string
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i;
    printf("Enter a string: ");
    gets(str);
    for (i = 0; str[i] != '\0'; i++) // Iterate till the string ends
    {
        str[i] = str[i] + 3; // Add 3 to each character
    }
    printf("Encoded string: %s", str); // Print the encoded string
    return 0;
}