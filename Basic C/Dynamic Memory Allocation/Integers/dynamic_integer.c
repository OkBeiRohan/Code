/**
 * Dynamic memory allocation
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *n = (int *)malloc(4 * sizeof(int));

    printf("MALLOC\nSize of n: %d\n", sizeof(*n));
    printf("Address of n: %p\n", &n); // %p is used to print address in hexadecimal, %x can also be used. %u or %d can be used to print address in decimal.
    printf("Value of n: %d\n", *n);
    printf("Pointer n = %d\n\n", n);

    int *m = (int *)calloc(4, sizeof(int));

    printf("CALLOC\nSize of m: %d\n", sizeof(*m));
    printf("Address of m: %p\n", &m);
    printf("Value of m: %d\n", *m);
    printf("Pointer m = %d\n", m);
}