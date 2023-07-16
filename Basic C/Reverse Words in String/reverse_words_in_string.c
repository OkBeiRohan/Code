/**
 * Reverse each word in a string
 */

#include <stdio.h>
#include <string.h>

void reverse(char *, int, int);
void reverse_words(char *);

/**
 * Main Function
 *
 * Algorithm:
 * 1. Read a string from the user
 * 2. Call the reverse_words function
 * 3. Print the reversed string
 */

int main()
{
    char str[100];
    printf("Enter a string: ");
    gets(str);

    reverse_words(str);

    printf("%s\n", str);

    return 0;
}

/**
 * Function to reverse a string
 * @param str String to be reversed
 * @param start Starting index of the string
 * @param end Ending index of the string
 * @return Reversed string
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * where n is the length of the string
 *
 * Algorithm:
 * 1. Swap the characters at the start and end index
 * 2. Increment the start index and decrement the end index
 * 3. Repeat steps 1 and 2 until start < end
 */

void reverse(char *str, int start, int end)
{
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

/**
 * Function to reverse each word in a string
 *
 * Algorithm:
 * 1. Iterate over the string
 * 2. If a space is encountered, reverse the word
 * 3. Repeat steps 1 and 2 until the end of the string
 * 4. Reverse the last word
 */

void reverse_words(char *str)
{
    int start = 0;
    int end = 0;

    while (str[end] != '\0')
    {
        if (str[end] == ' ')
        {
            reverse(str, start, end - 1);
            start = end + 1;
        }

        end++;
    }

    reverse(str, start, end - 1);
}