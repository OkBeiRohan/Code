/**
 * Write a C program to accept ten numbers in an array and output the “count” of even and odd numbers present. Also design a function to check there should be at least one even and at least one odd number should be present. If all the numbers are even or all the numbers are odd, then “Invalid Inputs” should be printed.
 * MISRA C Guidelines Must Be Followed
 *
 * Algorithm:
 * 1. Accept 10 numbers in an array
 * 2. Check if there is at least one odd and one even number in the array (Even numbers are divisible by 2 and can be checked by checking the remainder of the number when divided by 2)
 * 3. If there is not, print "Invalid Inputs" and exit
 * 4. If there is, count the number of odd and even numbers in the array (Count the number of odd numbers by checking if the remainder of the number when divided by 2 is 1. Count the number of even numbers by checking if the remainder of the number when divided by 2 is 0)
 * 5. Print the number of odd and even numbers in the array
 */

#include <stdio.h>

int check_if_odd_or_even(int);
int count_odds(int[]);
int count_evens(int[]);
int check_if_atleast_one_odd_and_even_present(int[]);

int main()
{
    int numbers[10], input_counter, odd_count, even_count;

    printf("Enter 10 numbers: ");
    for (input_counter = 0; input_counter < 10; input_counter++)
    {
        scanf("%d", &numbers[input_counter]);
    }

    if (check_if_atleast_one_odd_and_even_present(numbers) == 0)
    {
        printf("Invalid Inputs.\n");
        return 0;
    }

    odd_count = count_odds(numbers);
    even_count = count_evens(numbers);

    printf("Number of odd numbers: %d\n", odd_count);
    printf("Number of even numbers: %d\n", even_count);

    return 0;
}

/**
 * Checks if the given number is odd or even
 * If the number is even, function returns 0. If the number is odd, function returns 1
 *
 * @param number The number to be checked
 * @return 0 if the number is even, 1 if the number is odd
 */

int check_if_odd_or_even(int number)
{
    if (number % 2 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/**
 * Counts the number of odd numbers in the given array
 *
 * @param numbers The array of numbers
 * @return The number of odd numbers in the array
 */

int count_odds(int numbers[])
{
    int counter, odd_count = 0;

    for (counter = 0; counter < 10; counter++)
    {
        if (check_if_odd_or_even(numbers[counter]) == 1)
        {
            odd_count++;
        }
    }

    return odd_count;
}

/**
 * Counts the number of even numbers in the given array
 *
 * @param numbers The array of numbers
 * @return The number of even numbers in the array
 */

int count_evens(int numbers[])
{
    int counter, even_count = 0;

    for (counter = 0; counter < 10; counter++)
    {
        if (check_if_odd_or_even(numbers[counter]) == 0)
        {
            even_count++;
        }
    }

    return even_count;
}

/**
 * Checks if there is at least one odd and one even number in the given array
 *
 * @param numbers The array of numbers
 * @return 1 if there is at least one odd and one even number in the array, 0 if there is not
 */

int check_if_atleast_one_odd_and_even_present(int numbers[])
{
    int counter, odd_count = 0, even_count = 0;

    for (counter = 0; counter < 10; counter++)
    {
        if (check_if_odd_or_even(numbers[counter]) == 1)
        {
            odd_count++;
            if (even_count > 0) // If the there are atleast one even number, then the condition is satisfied. And can return 1 or exit from the loop
            {
                break;
            }
        }
        else
        {
            even_count++;
            if (odd_count > 0) // If the there are atleast one odd number, then the condition is satisfied. And can return 1 or exit from the loop
            {
                break;
            }
        }
    }

    if (odd_count > 0 && even_count > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}