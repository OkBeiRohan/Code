/**
 * Accept two numbers, Snum and Lnum and print all numbers between them. If Snum is lesser than Lnum and all the numbers between should be printed in increasing order of 2. If Snum is greater than Lnum then the numbers should be printed in decreasing order of 1
 * MISRA C Should be followed
 *
 * Algorithm:
 * 1. Start
 * 2. Declare two integer variables Snum and Lnum
 * 3. Input Snum
 * 4. Input Lnum
 * 5. If Snum is lesser than Lnum, then
 *     5.1 Loop through the numbers from Snum + 1 to Lnum - 1 with a step of 2
 *        5.1.1 Print the number
 * 6. Else
 *    6.1 Loop through the numbers from Snum - 1 to Lnum + 1
 *      6.1.1 Print the number
 * 7. Stop
 */

#include <stdio.h>

int main()
{
    int Snum, Lnum, i;

    printf("Enter the smaller number: ");
    scanf("%d", &Snum);

    printf("Enter the larger number: ");
    scanf("%d", &Lnum);

    if (Snum < Lnum)
    {
        for (i = Snum + 1; i < Lnum; i += 2)
        {
            printf("%d ", i);
        }
    }
    else
    {
        for (i = Snum - 1; i > Lnum; i--)
        {
            printf("%d ", i);
        }
    }

    return 0;
}