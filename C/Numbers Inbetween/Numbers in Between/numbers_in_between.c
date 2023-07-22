/**Accept two number, Snum and Lnum and print all numbers between them. “Snum should be greater than Lnum” checking should be done and print should be carried out only if Snum is less than Lnum.
 * MISRA C Guidelines followed
 *
 * Algorithm:
 * 1. Start
 * 2. Declare two integer variables Snum and Lnum
 * 3. Input Snum
 * 4. Input Lnum
 * 5. If Snum is greater than or equal to Lnum, then
 *      5.1 Print "Invalid input"
 * 6. Else
 *      6.1 Loop through the numbers from Snum + 1 to Lnum - 1
 *          6.1.1 Print the number
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

    if (Snum >= Lnum)
    {
        printf("Invalid input");
    }
    else
    {
        for (i = Snum + 1; i < Lnum; i++)
        {
            printf("%d ", i);
        }
    }

    return 0;
}