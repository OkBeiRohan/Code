/**
 * Swap two numbers
 * 
 * Algorithm:
 * 1. Start
 * 2. Input two numbers
 * 3. Print the numbers before swapping
 * 4. Store the value of first number in a temporary variable
 * 5. Store the value of second number in the first number
 * 6. Store the value of temporary variable in the second number
 * 7. Print the numbers after swapping
 * 8. Stop
 */

#include <stdio.h>

void swap(int *, int *);

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);
    printf("Before swapping:\n");
    printf("a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swapping:\n");
    printf("a = %d, b = %d\n", a, b);
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}