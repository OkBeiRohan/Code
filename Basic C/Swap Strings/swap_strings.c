/**
 * Display string lengths and swap two strings without using strlen() and strcpy()
 *
 * Algorithm:
 * 1. Start
 * 2. Input the first string
 * 3. Input the second string
 * 4. Find the length of the strings
 *      4.1 Initialise length to 0
 *      4.2 Repeat steps 4.3 and 4.4 while the character at the current position of the string is not equal to '\0'
 *      4.3 Increment length by 1
 *      4.4 Increment the current position of the string by 1
 * 5. Display the lengths of the strings
 * 6. Swap the strings
 *      6.1 Initialise temp to '\0'
 *      6.2 Repeat steps 6.3 and 6.4 while the character at the current position of the first string is not equal to '\0' or the character at the current position of the second string is not equal to '\0'
 *      6.3 Store the character at the current position of the first string in temp
 *      6.4 Store the character at the current position of the second string in the current position of the first string and the character stored in temp in the current position of the second string
 * 7. Display the strings after swapping
 * 8. Stop
 */

#include <stdio.h>

int find_length(char *);
void swap_strings(char *, char *);

int main()
{
    char a[100], b[100];

    printf("Enter the first string: ");
    gets(a);
    printf("Enter the second string: ");
    gets(b);

    printf("Length of the first string = %d\n", find_length(a));
    printf("Length of the second string = %d\n", find_length(b));

    swap_strings(a, b);

    printf("The first string after swapping is: %s\n", a);
    printf("The second string after swapping is: %s\n", b);

    return 0;
}

int find_length(char *a)
{
    int length = 0;

    while (*(a + length) != '\0')
        length++;

    return length;
}

void swap_strings(char *a, char *b)
{
    char temp;

    while (*a != '\0' || *b != '\0')
    {
        temp = *a;
        *a = *b;
        *b = temp;

        a++;
        b++;
    }
}