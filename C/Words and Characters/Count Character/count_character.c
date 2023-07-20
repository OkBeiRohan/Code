/**
 * Count a character in string
 *
 * Algorithm:
 * 1. Take a string and a character as input
 * 2. Loop through the string
 * 3. If the character is found, increment count
 * 4. Print count
 * 5. Stop
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