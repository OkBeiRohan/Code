/**
 * Print prime numbers between two numbers
 * 
 * Algorithm:
 * 1. Start
 * 2. Input two numbers
 * 3. If first number is less than second number, goto step 4, else goto step 9
 * 4. Increment first number by 1
 * 5. If first number is less than second number, goto step 6, else goto step 9
 * 6. If first number is divisible by any number from 2 to first number/2, goto step 4, else goto step 7
 * 7. Print first number
 * 8. Goto step 4
 * 9. Stop
 */

#include <stdio.h>

int check_prime(int n);

int main()
{
    int n1, n2, i, flag;

    printf("Enter two numbers(intervals): ");
    scanf("%d %d", &n1, &n2);

    printf("Prime numbers between %d and %d are: ", n1, n2);

    for (i = n1 + 1; i < n2; ++i)
    {
        // flag will be equal to 1 if i is prime
        flag = check_prime(i);

        if (flag == 1)
            printf("%d ", i);
    }

    return 0;
}

int check_prime(int n)
{
    int j, flag = 1;

    for (j = 2; j <= n / 2; ++j)
    {
        if (n % j == 0)
        {
            flag = 0;
            break;
        }
    }

    return flag;
}