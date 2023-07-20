/**
 * Insert string into another string
 *
 * Algorithm:
 * 1. Start
 * 2. Input the string
 * 3. Input the position where the string has to be inserted
 * 4. Input the string to be inserted
 * 5. Find the length of the string
 * 6. Repeat step 6.1 for i = length of the string to the position
 *    6.1 Move the characters to the right by one position
 * 7. Repeat step 7.1 for i = position to position + length of the string to be inserted
 *   7.1 Insert the characters of the string to be inserted into the string
 * 8. Display the string after insertion
 * 9. Stop
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char a[100], b[100];
    int position, i, length;

    printf("Enter a string: ");
    gets(a);

    printf("Enter the position where the string has to be inserted: ");
    scanf("%d", &position);

    printf("Enter the string to be inserted: ");
    fflush(stdin); // flushes the input buffer
    gets(b);

    length = strlen(a);

    for (i = length; i >= position; i--)
        a[i + strlen(b)] = a[i];

    for (i = position; i < position + strlen(b); i++)
        a[i] = b[i - position];

    printf("The string after insertion is: ");
    puts(a);

    return 0;
}