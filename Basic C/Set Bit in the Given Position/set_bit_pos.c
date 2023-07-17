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
    int num, pos, res;

    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Enter the position: ");
    scanf("%d", &pos);

    res = num | (0x01 << pos);

    printf("Result: %d\n\n", res);

    printf("Number: %d\n", toBinary(num));
    printf("Position: %d\n", pos);
    printf("Result: %d\n", toBinary(res));
}