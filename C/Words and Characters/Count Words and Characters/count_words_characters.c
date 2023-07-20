/**
 * Count number of words and characters
 * 
 * Algorithm:
 * 1. Take a string as input
 * 2. If a space is encountered and the next character is not null and the previous character is not a space, increment word count
 * 3. Increment character count
 * 4. Print word count and character count
 * 5. Stop
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