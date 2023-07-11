/**
 * Search for a digit in a number
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