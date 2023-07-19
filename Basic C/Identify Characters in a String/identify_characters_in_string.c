/**
 * Identify the type of characters in a strings
 *
 * Algorithm:
 * 1. Start
 * 2. Take a string as input
 * 3. Iterate through the string
 * 4. If the character falls between 'a' (97) and 'z' (122), it is a lowercase alphabet
 * 5. If the character falls between 'A' (65) and 'Z' (90), it is an uppercase alphabet
 * 6. If the character falls between '0' (48) and '9' (57), it is a digit
 * 7. If the character does not fall in any of the above, it is a special character
 * 8. Display the type of character and its ASCII value
 * 9. Stop
 */

#include <stdio.h>

enum type
{
    LOWERCASE,
    UPPERCASE,
    DIGIT,
    SPECIAL
};

enum type identify(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return LOWERCASE;
    else if (ch >= 'A' && ch <= 'Z')
        return UPPERCASE;
    else if (ch >= '0' && ch <= '9')
        return DIGIT;
    else
        return SPECIAL;
}

int main()
{
    char str[100];
    int i = 0;
    enum type t;
    printf("Enter a string: ");
    gets(str);
    printf("\n\nCharacter Types\n");
    printf("Character\tASCII Value\tType\n");
    while (str[i] != '\0')
    {
        t = identify(str[i]);
        switch (t)
        {
        case LOWERCASE:
            printf("%c\t\t%d\t\tLowercase Alphabet\n", str[i], str[i]);
            break;
        case UPPERCASE:
            printf("%c\t\t%d\t\tUppercase Alphabet\n", str[i], str[i]);
            break;
        case DIGIT:
            printf("%c\t\t%d\t\tDigit\n", str[i], str[i]);
            break;
        case SPECIAL:
            printf("%c\t\t%d\t\tSpecial\n", str[i], str[i]);
            break;
        default:
            printf("%c\t\t%d\t\tUnknown\n", str[i], str[i]);
        }
        i++;
    }
    return 0;
}