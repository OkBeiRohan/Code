/**
 * Program to check whether a character is vowel or consonant.
 */

#include <stdio.h>

int main()
{
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);
    if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U')
        printf("%c is a vowel.", ch);
    else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        printf("%c is a consonant.", ch);
    else
        printf("%c is not an alphabet.", ch);
    return 0;
}