/**
 * Program to count the first largest occurrence of a character in a string
 * Example:
 * Input: safafsfa
 * Output: f, count = 3
 */

#include <stdio.h>
#include <string.h>

int isInString(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (c == str[i])
            return i;
    return 0;
}

int main()
{
    char str[100], maxCount[26], max_char;
    int count[26] = {0}, max = 0, k = 0, pos = 0, maxC[26] = {0};

    printf("Enter a string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
        count[str[i] - 'a']++;

    for (int i = 0; i < 26; i++)
        if (count[i] > max)
        {
            max = count[i];
            max_char = i + 'a';
        }
    for (int i = 0; i < 26; i++)
        if (max == count[i])
        {
            maxCount[k] = i + 'a';
            k++;
        }
    for (int i = 0; str[i] != '\0'; i++)
    {
        pos = isInString(str[i], maxCount);
        if (pos)
        {
            maxC[pos]++;
            if (maxC[pos] == max)
            {
                max_char = str[i];
                break;
            }
        }
    }

    printf("%c, count = %d\n", max_char, max);
    return 0;
}