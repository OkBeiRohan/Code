/**
 * Accept two numbers and print all odd numbers between them. If the first numbers is even the printing should always start with odd number.
 *
 * Algorithm:
 * 1. Start
 * 2. Declare two integer variables Snum and Lnum
 * 3. Input Snum
 * 4. Input Lnum
 * 5. If Snum is even, then
 *     5.1 Loop through the numbers from Snum + 1 to Lnum - 1 with a step of 2
 *       5.1.1 Print the number
 * 6. Else
 *   6.1 Loop through the numbers from Snum to Lnum - 1 with a step of 2
 *    6.1.1 Print the number
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

    if (Snum % 2 == 0)
    {
        for (i = Snum + 1; i < Lnum; i += 2)
        {
            printf("%d ", i);
        }
    }
    else
    {
        for (i = Snum; i < Lnum; i += 2)
        {
            printf("%d ", i);
        }
    }

    return 0;
}