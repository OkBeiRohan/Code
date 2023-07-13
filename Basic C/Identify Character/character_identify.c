/**
 * Program to categorise the character
 */

#include <stdio.h>

int main()
{
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);           // Input a character
    if (ch >= 'a' && ch <= 'z') // Check if the character is lowercase alphabet
        printf("%c is a lowercase alphabet.", ch);
    else if (ch >= 'A' && ch <= 'Z') // Check if the character is uppercase alphabet
        printf("%c is an uppercase alphabet.", ch);
    else if (ch >= '0' && ch <= '9') // Check if the character is a digit
        printf("%c is a digit.", ch);
    else // If the character is not from any of the above, it is a special character
        printf("%c is a special character.", ch);
    return 0;
}