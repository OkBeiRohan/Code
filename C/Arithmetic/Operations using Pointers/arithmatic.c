/**
 * Write a C program to accept two positive numbers from user and output the addition, multiplication, subtraction, and reminder. This should be achieved using pointers and only one function call from the “main”.
 * MISRA C Guidelines Must Be Followed
 *
 * Algorithm:
 * 1. Accept two numbers from the user
 * 2. Pass the two numbers and addresses of the variables to store the results to a function
 * 3. The function should calculate the sum, product, difference, remainder, and quotient of the two numbers
 * 4. The function should store the results in the addresses passed to it
 * 5. Print the results in the main function
 */

#include <stdio.h>

void perform_arithmatic(int, int, int *, int *, int *, int *, int *);
void find_sum(int, int, int *);
void find_product(int, int, int *);
void find_difference(int, int, int *);
void find_remainder(int, int, int *);
void find_quotient(int, int, int *);

int main()
{
    int number1, number2, sum_result, product_result, difference_result, remainder_result, quotient_result;

    printf("Enter two numbers: ");
    scanf("%d %d", &number1, &number2);

    perform_arithmatic(number1, number2, &sum_result, &product_result, &difference_result, &remainder_result, &quotient_result);

    printf("Sum (%d+%d): %d\n", number1, number2, sum_result);
    printf("Product (%dx%d): %d\n", number1, number2, product_result);
    printf("Difference (%d-%d): %d\n", number1, number2, difference_result);
    printf("Remainder (%d%%%d): %d\n", number1, number2, remainder_result);
    printf("Quotient (%d/%d): %d\n", number1, number2, quotient_result);

    return 0;
}

/**
 * Performs arithmatic operations on the given numbers
 *
 * @param number1 The first number
 * @param number2 The second number
 * @param sum_result Pointer to the variable to store the sum of the two numbers
 * @param product_result Pointer to the variable to store the product of the two numbers
 * @param difference_result Pointer to the variable to store the difference of the two numbers
 * @param remainder_result Pointer to the variable to store the remainder of the two numbers
 */

void perform_arithmatic(int number1, int number2, int *sum_result, int *product_result, int *difference_result, int *remainder_result, int *quotient_result)
{
    find_sum(number1, number2, sum_result);
    find_product(number1, number2, product_result);
    find_difference(number1, number2, difference_result);
    find_quotient(number1, number2, quotient_result);
    find_remainder(number1, number2, remainder_result);
}

/**
 * Calculates the sum of the two numbers
 *
 * @param number1 The first number
 * @param number2 The second number
 * @param sum_result Pointer to the variable to store the sum of the two numbers
 */

void find_sum(int number1, int number2, int *sum_result)
{
    *sum_result = number1 + number2;
}

/**
 * Calculates the product of the two numbers
 *
 * @param number1 The first number
 * @param number2 The second number
 * @param product_result Pointer to the variable to store the product of the two numbers
 */

void find_product(int number1, int number2, int *product_result)
{
    *product_result = number1 * number2;
}

/**
 * Calculates the difference of the two numbers
 *
 * @param number1 The first number
 * @param number2 The second number
 * @param difference_result Pointer to the variable to store the difference of the two numbers
 */

void find_difference(int number1, int number2, int *difference_result)
{
    *difference_result = number1 - number2;
}

/**
 * Calculates the remainder of the two numbers
 *
 * @param number1 The first number
 * @param number2 The second number
 * @param remainder_result Pointer to the variable to store the remainder of the two numbers
 */

void find_remainder(int number1, int number2, int *remainder_result)
{
    *remainder_result = number1 % number2;
}

/**
 * Calculates the quotient of the two numbers
 *
 * @param number1 The first number
 * @param number2 The second number
 * @param quotient_result Pointer to the variable to store the quotient of the two numbers
 */

void find_quotient(int number1, int number2, int *quotient_result)
{
    if (number2 == 0) // Division by zero is not allowed
    {
        *quotient_result = 0; // Set the quotient to 0
        return;
    }
    *quotient_result = number1 / number2;
}