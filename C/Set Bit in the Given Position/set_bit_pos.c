/**
 * Set Bit in the Given Position
 */

#include <stdio.h>

int toBinary(int num)
{
    int bin = 0, rem, i = 1;

    while (num != 0)
    {
        rem = num % 2;
        num /= 2;
        bin += rem * i;
        i *= 10;
    }

    return bin;
}

int main()
{
    int num, pos, res, res_neg;

    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Enter the position: ");
    scanf("%d", &pos);

    /**
     * The bitwise OR operator (|) sets the bit to 1 if either of the bits is 1.
     *
     * 0x01 is 0000 0001.
     * Left shifting to required position will set the bit to 1. (Eg: If position is 3, 0x01 << 3 = 0000 1000)
     * Now ORing the number with the shifted value will set the bit to 1.
     * (Eg: If number is 5, 0000 0101 | 0000 1000 = 0000 1101)
     */

    int consective_bits = 0x01;
    res = num | (consective_bits << pos);
    res_neg = num & ~(consective_bits << pos);

    /**
     * For setting two consecutive bits, use 0x03 instead of 0x01. For setting three consecutive bits, use 0x07 instead of 0x01.
     */

    printf("Decimal Result: %d\nNegation Result: %d\n\nBinary\n", res, res_neg);

    printf("Number: %d\n", toBinary(num));
    printf("Position: %d\n", toBinary(consective_bits << pos));
    printf("Result: %d\n", toBinary(res));
    printf("Negation Result: %d\n", toBinary(res_neg));
}