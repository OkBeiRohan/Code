/**
 * Reverse a number using stack
 *
 * Algorithm:
 * 1. Take a number as input
 * 2. Store the number in a temporary variable
 * 3. Repeat the following steps until the temporary variable is greater than 0
 *   a. Push the last digit of the temporary variable to the stack
 * b. Remove the last digit of the temporary variable
 * 4. Repeat the following steps until the stack is empty
 *  a. Pop the top element of the stack
 * b. Multiply the popped element with 10 raised to the power of the index of the popped element
 * c. Add the result to the reverse variable
 * 5. Print the reverse variable
 * 6. Stop
 */

#include <stdio.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    return 0;
}

void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
        printf("Stack Overflow! Cannot push %d to the stack\n", value);
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

void display(struct stack *ptr)
{
    for (int i = 0; i <= ptr->top; i++)
        printf("%d ", ptr->arr[i]);
    printf("\n");
}

int pow(int base, int exponent)
{
    int result = 1;
    for (int i = 0; i < exponent; i++)
        result *= base;
    return result;
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    int number, temp;
    printf("Enter a number: ");
    scanf("%d", &number);
    temp = number;
    while (temp > 0)
    {
        push(sp, temp % 10);
        temp /= 10;
    }
    int reverse = 0;
    for (int i = 0; !isEmpty(sp); i++)
        reverse = reverse + (pop(sp) * pow(10, i));
    printf("Reverse of %d is %d", number, reverse);
    return 0;
}