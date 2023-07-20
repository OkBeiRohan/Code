/**
 * Program to print fibonacci series using recursion
 * Fibonacci series: 0 1 1 2 3 5 8 13 21 ...
 *
 * Algorithm:
 * 1. Read the number of terms to be printed from the user
 * 2. Call the fibonacci function for each term
 * 3. Print the fibonacci number
 * 4. Repeat steps 2 and 3 until the number of terms are printed
 * 5. Exit
 */

#include <stdio.h>

int fibonacci(int);

int main()
{
    int n, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    for (i = 0; i < n; i++)
        printf("%d ", fibonacci(i));
    return 0;
}

/**
 * Function to calculate the nth fibonacci number
 * @param n The number
 * @return The nth fibonacci number
 *
 * Time Complexity: O(2^n)
 * Space Complexity: O(n)
 *
 * Algorithm:
 * 1. If n is 0 or 1, return n
 * 2. Else, return the sum of the previous two fibonacci numbers (n - 1) and (n - 2)
 */

int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}