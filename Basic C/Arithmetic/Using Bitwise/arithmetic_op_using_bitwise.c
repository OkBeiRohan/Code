/**
 * Arithmetic operations using bitwise (without using arithmetic operators)
 */

#include <stdio.h>

int main()
{
    int num1, num2, res;

    printf("Enter the two numbers: ");
    scanf("%d%d", &num1, &num2);

    /**
     * Sum of numbers using bitwise operators
     *
     * 1. XOR the numbers
     * 2. AND the numbers
     * 3. Left shift the ANDed result by 1
     * 4. XOR the numbers
     * 5. Repeat steps 2 to 4 until ANDed result is 0
     */

    while (num2 != 0)
    {
        res = num1 ^ num2;
        num2 = (num1 & num2) << 1;
        num1 = res;
    }
    printf("Sum: %d\n", res);

    /**
     * Difference of numbers using bitwise operators
     */

    res = 0;
    while (num2 != 0)
    {
        res = num1 ^ num2;
        num2 = (~num1 & num2) << 1;
        num1 = res;
    }
    printf("Difference: %d\n", res);

    /**
     * Product of numbers using bitwise operators
     */

    res = 0;
    while (num2 != 0)
    {
        if (num2 & 1)
        {
            res = res + num1;
        }
        num1 <<= 1;
        num2 >>= 1;
    }
    printf("Product: %d\n", res);

    /**
     * Quotient of numbers using bitwise operators
     */

    res = 0;
    while (num1 >= num2)
    {
        num1 = num1 - num2;
        res++;
    }
    printf("Quotient: %d\n", res);

    /**
     * Remainder of numbers using bitwise operators
     */

    res = 0;
    while (num1 >= num2)
    {
        num1 = num1 - num2;
        res++;
    }
    printf("Remainder: %d\n", num1);

    return 0;
}