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
    int num, pos, res, consective_bits = 0x01;

    printf("Enter the number: ");
    scanf("%d", &num);

    printf("Enter the position to swap bit: ");
    scanf("%d", &pos);

    /**
     * Check if the bit in position is set or not.
     */

    if (num & (consective_bits << pos))
    {
        /**
         * If the bit is set, clear the bit.
         *
         * The bitwise XOR operator (^) sets the bit to 0 if either of the bits is 1.
         *
         * 0x01 is 0000 0001.
         * Left shifting to required position will set the bit to 1. (Eg: If position is 3, 0x01 << 3 = 0000 1000)
         * Now negating the shifted value will set the bit to 0.
         * (Eg: If number is 5, 0000 0101 ^ ~(0000 1000) = 0000 0101 ^ 1111 0111 = 0000 0101 ^ 1111 0111 = 0000 0010)
         */
        res = num ^ (consective_bits << pos);
    }
    else
    {
        /**
         * If the bit is not set, set the bit.
         *
         * The bitwise OR operator (|) sets the bit to 1 if either of the bits is 1.
         *
         * 0x01 is 0000 0001.
         * Left shifting to required position will set the bit to 1. (Eg: If position is 3, 0x01 << 3 = 0000 1000)
         * Now ORing the shifted value will set the bit to 1.
         * (Eg: If number is 5, 0000 0101 | (0000 1000) = 0000 0101 | 0000 1000 = 0000 1101)
         */
        res = num | (consective_bits << pos);
    }

    printf("Decimal Result: %d\n\nBinary\n", res);
    printf("Number: %d\n", toBinary(num));
    printf("Position: %d\n", toBinary(consective_bits << pos));
    printf("Result: %d\n", toBinary(res));
}