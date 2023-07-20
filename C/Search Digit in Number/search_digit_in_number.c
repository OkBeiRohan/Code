/**
 * Search for a digit in a number
 *
 * Algorithm:
 * 1. Get the number and digit to be searched
 * 2. Store the number in a temporary variable
 * 3. Repeat the following steps until the temporary variable is greater than 0
 *    a. Check if the last digit of the temporary variable is equal to the digit to be searched
 *   b. If yes, print the digit is found and stop the program
 *  c. If no, remove the last digit of the temporary variable
 * 4. If the program is not stopped in the above step, print the digit is not found
 * 5. Stop
 */

#include <stdio.h>

int main()
{
    int number, digit, temp;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("Enter the digit to be searched: ");
    scanf("%d", &digit);
    temp = number;
    while (temp > 0)
    {
        if (temp % 10 == digit)
        {
            printf("Digit %d found in number %d", digit, number);
            return 0;
        }
        temp /= 10;
    }
    printf("Digit %d not found in number %d", digit, number);
    return 0;
}