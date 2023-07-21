/**
 * Use MISRA C Guidelines
 *
 * Accept a string and print its length. If accepted string is “Hello”, then print the message as “Correct” or else print the message as “Incorrect”.
 *
 * Algorithm:
 * 1. Start
 * 2. Input a string
 * 3. Calculate the length of the string
 * 4. If the string is “Hello”, then print “Correct” or else print “Incorrect”
 * 5. Stop
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char str[20];
    int len;
    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);
    printf("Length of the string: %d\n", len);
    if (strcmp(str, "Hello") == 0)
    {
        printf("Correct\n");
    }
    else
    {
        printf("Incorrect\n");
    }
    return 0;
}