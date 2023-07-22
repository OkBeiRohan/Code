/**
 * Print fibonacci series from 1 to n
 * 
 * Algorithm:
 * 1. Input the last number
 * 2. Initialize t1 = 0, t2 = 1
 * 3. Print t1
 * 4. nextTerm = t1 + t2
 * 5. t1 = t2
 * 6. t2 = nextTerm
 * 7. Repeat step 3 to 6 until t1 > n
 * 8. Stop
 */

#include <stdio.h>

int main()
{
    int n, i, t1 = 0, t2 = 1, nextTerm;

    printf("Enter the last number: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    for (i = 1;; ++i)
    {
        if (t1 > n)
        {
            break;
        }
        if (i != 1)
        {
            printf(", ");
        }
        printf("%d", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    return 0;
}