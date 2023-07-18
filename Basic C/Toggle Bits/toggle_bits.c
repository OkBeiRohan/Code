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

    res = num ^ (consective_bits << pos);

    printf("Decimal Result: %d\n\nBinary\n", res);
    printf("Number: %d\n", toBinary(num));
    printf("Position: %d\n", toBinary(consective_bits << pos));
    printf("Result: %d\n", toBinary(res));
}