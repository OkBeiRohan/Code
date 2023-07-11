/**
 * Count a character in string
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], ch;
    int count = 0;
    printf("Enter a string: ");
    gets(str);
    printf("Enter a character to find its occurrences: ");
    scanf("%c", &ch);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (ch == str[i])
            count++;
    }
    printf("Number of occurrences of %c = %d", ch, count);
    return 0;
}