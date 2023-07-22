/**
 * Check if a number is prime or composite
 *
 * Follow MISRA C
 *
 * Algorithm:
 * 1. Start
 * 2. Input a number
 * 3. If number is less than or equal to 1, goto step 9, else goto step 4
 * 4. If number is divisible by any number from 2 to number/2, goto step 7, else goto step 5
 * 5. Print number is prime
 * 6. Goto step 10
 * 7. Print number is composite
 * 8. Goto step 10
 * 9. Print number is neither prime nor composite
 * 10. Stop
 */

#include <stdio.h>

int check_prime(int n);

int main()
{
    int n, flag;

    printf("Enter the number: ");
    scanf("%d", &n);

    if (n <= 1)
    {
        printf("%d is neither prime nor composite", n);
        return 0;
    }

    flag = check_prime(n);

    if (flag == 1)
    {
        printf("%d is a prime number\n", n);
    }
    else
    {
        printf("%d is a composite number\n", n);
    }

    return 0;
}

int check_prime(int n)
{
    int i, flag = 1;

    for (i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            flag = 0;
            break;
        }
    }

    return flag;
}