/**
 * Count number of words and characters
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int words, characters;
    words = characters = 0;
    printf("Enter a string: ");
    gets(str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        characters++;
        if (str[i] == ' ' && str[i + 1] != '\0' && i != 0 && str[i - 1] != ' ')
            words++;
    }
    printf("Number of words: %d\nNumber of characters: %d", words + 1, characters);
    return 0;
}