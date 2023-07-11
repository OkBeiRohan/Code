/**
 * Count number of words
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