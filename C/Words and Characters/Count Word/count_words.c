/**
 * Count number of words
 * 
 * Algorithm:
 * 1. Take a string as input
 * 2. If a space is encountered and the next character is not null and the previous character is not a space, increment word count
 * 3. Print word count
 * 4. Stop
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int words;
    words = 0;
    printf("Enter a string: ");
    gets(str);
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ' && str[i + 1] != '\0' && i != 0 && str[i - 1] != ' ')
            words++;
    printf("Number of words: %d\n", words + 1);
    return 0;
}