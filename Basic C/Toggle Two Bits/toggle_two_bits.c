/**
 * Toggle 2 bits
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
    int num, pos1, pos2, res, consective_bits = 0x01;

    printf("Enter the number: ");
    scanf("%d", &num);

    printf("Enter the position to swap bit: ");
    scanf("%d", &pos1);

    printf("Enter the position to swap bit: ");
    scanf("%d", &pos2);

    res = num ^ ((consective_bits << pos1) | (consective_bits << pos2));

    printf("Number before toggling bits: %d (%d)\n", num, toBinary(num));
    printf("Number after toggling bits: %d (%d)\n", res, toBinary(res));

    return 0;
}