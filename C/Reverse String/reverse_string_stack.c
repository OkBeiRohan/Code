/**
 * Reverse a string using stack
 *
 * Follow MISRA C Guidelines
 *
 * Algorithm:
 * 1. Start
 * 2. Declare a character stack
 * 3. Input a string
 * 4. Repeat for i = 0 to length of string
 *      4.1 Push the character at index i into the stack
 * 5. Repeat for i = 0 to length of string
 *      5.1 Pop the character from the stack and store it at index i
 * 6. Display the reversed string
 * 7. Stop
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char);
char pop();

int main()
{
    char str[MAX];
    int i;

    printf("Enter a string: ");
    gets(str);

    for (i = 0; i < strlen(str); i++)
    {
        push(str[i]);
    }

    for (i = 0; i < strlen(str); i++)
    {
        str[i] = pop();
    }

    printf("The reversed string is: %s\n", str);

    return 0;
}

void push(char c)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        stack[top] = c;
    }
}

char pop()
{
    char c;

    if (top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        c = stack[top];
        top--;
        return c;
    }
}