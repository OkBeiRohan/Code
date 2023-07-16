/**
 * Input: Hello
 * Output:
 * Character    ASCII    Binary    1s
 * H            72       1001000   2
 * e            101      1100101   4
 * l            108      1101100   3
 * l            108      1101100   3
 * o            111      1101111   5
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

int char_to_binary(char);
int count_ones(int);

int main()
{
    char str[100];

    printf("Enter a string: ");
    gets(str);

    printf("Character\tASCII\t\tBinary\t\t1s\n");

    for (int i = 0; i < strlen(str); i++)
    {
        printf("%c\t\t%d\t\t%d\t\t%d\n", str[i], str[i], char_to_binary(str[i]), count_ones(char_to_binary(str[i])));
    }

    return 0;
}

/**
 * Function to convert a character to binary
 * @param c Character to be converted
 * @return Binary representation of the character
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 *
 * Algorithm:
 * 1. Iterate over the character from the left (MSB) to right (LSB) (i = 7 to 0) and get the bit at each position (c >> i) & 1 (right shift the character by i and AND it with 1)
 * 2. If the bit is 1, add 10^i to the binary number
 * 3. Repeat steps 1 and 2 until the end of the character
 * 4. Return the binary number
 */

int char_to_binary(char c)
{
    int binary = 0;

    for (int i = 7; i >= 0; i--)
    {
        binary += ((c >> i) & 1) * pow(10, i);
    }

    return binary;
}

/**
 * Function to count the number of 1s in a binary number
 * @param binary Binary number
 * @return Number of 1s in the binary number
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 *
 * Algorithm:
 * 1. Iterate over the binary number from the right
 * 2. If the bit is 1, increment the count
 * 3. Repeat steps 1 and 2 until the end of the binary number
 * 4. Return the count
 */

int count_ones(int binary)
{
    int count = 0;

    while (binary > 0)
    {
        count += binary % 10;
        binary /= 10;
    }

    return count;
}
