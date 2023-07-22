/**
 * Write a program to simulate stack operations such as push, pop and display using an integer array as stack. Menu must be used for the stack operations.
 * Follow all MISRA C Guidelines
 *
 * Algorithm:
 * 1. Start
 * 2. Declare an integer array of size 5 and an integer variable top and initialize it to -1
 * 3. Display the menu
 * 4. Read the choice
 * 5. If choice is 1, then
 *      5.1 If top is equal to 4, then
 *          5.1.1 Display stack overflow
 *      5.2 Else
 *          5.2.1 Increment top by 1
 *          5.2.2 Read the value to be pushed
 *          5.2.3 Store the value in the array at the index top
 * 6. Else if choice is 2, then
 *      6.1 If top is equal to -1, then
 *          6.1.1 Display stack underflow
 *      6.2 Else
 *          6.2.1 Store the value at the index top in a variable val
 *          6.2.2 Decrement top by 1
 *          6.2.3 Display the value popped
 * 7. Else if choice is 3, then
 *      7.1 If top is equal to -1, then
 *          7.1.1 Display stack is empty
 *      7.2 Else
 *          7.2.1 Display stack elements are
 *          7.2.2 Repeat for i = top to 0
 *          7.2.3 Display the value at the index i
 * 8. Else if choice is 4, then
 *      8.1 Exit
 * 9. Else
 *      9.1 Display invalid choice
 * 10. Repeat from step 3
 * 11. Stop
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int);
int pop();
void display();

int main()
{
    int choice, val;

    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be pushed: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            val = pop();
            if (val != -1)
            {
                printf("The value popped is %d\n", val);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}

void push(int val)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        stack[top] = val;
    }
}

int pop()
{
    int val;

    if (top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        val = stack[top];
        top--;
        return val;
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}