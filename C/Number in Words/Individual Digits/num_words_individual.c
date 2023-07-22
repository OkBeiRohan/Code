/**
 * Numbers in Words
 * Input 1234
 * Output One Two Three Four
 *
 * Algorithm:
 * 1. Input the number
 * 2. Reverse the number
 * 3. Iterate through the reversed number
 * 4. Print the word for each digit
 * 5. Iterate through the original number and print zero for each zero at the end
 * 6. Stop
 */

#include <stdio.h>

int main()
{
    int n, digit, rev = 0, copy;

    printf("Enter the number: ");
    scanf("%d", &n);

    copy = n;

    while (n != 0)
    {
        digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    }

    while (rev != 0)
    {
        digit = rev % 10;
        switch (digit)
        {
        case 0:
            printf("Zero ");
            break;
        case 1:
            printf("One ");
            break;
        case 2:
            printf("Two ");
            break;
        case 3:
            printf("Three ");
            break;
        case 4:
            printf("Four ");
            break;
        case 5:
            printf("Five ");
            break;
        case 6:
            printf("Six ");
            break;
        case 7:
            printf("Seven ");
            break;
        case 8:
            printf("Eight ");
            break;
        case 9:
            printf("Nine ");
            break;
        default:
            break;
        }
        rev /= 10;
    }

    // If last digit is zero
    while (copy > 0)
    {
        if (copy % 10 == 0)
        {
            printf("Zero ");
            copy /= 10;
        }
        else
        {
            break;
        }
    }

    return 0;
}