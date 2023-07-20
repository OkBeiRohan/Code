/**
 * Swap 3 numbers in cyclic order using call by reference
 *
 * Algorithm:
 * 1. Start
 * 2. Input the values of a, b and c
 * 3. Call the function cyclic_swap() by passing the addresses of a, b and c
 * 4. The function cyclic_swap() receives the addresses of a, b and c
 * 5. Swap the values of a, b and c
 *    5.1 Store the value of b in a temporary variable temp
 *    5.2 Store the value of a in b
 *    5.3 Store the value of c in a
 *    5.4 Store the value of temp in c
 * 6. Display the values of a, b and c
 * 7. Stop
 */

#include <stdio.h>

void cyclic_swap(int *, int *, int *);

int main()
{
    int a, b, c;

    printf("Enter the values of a, b and c: ");
    scanf("%d %d %d", &a, &b, &c);

    printf("Before swapping:\n");
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    cyclic_swap(&a, &b, &c);

    printf("After swapping:\n");
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    return 0;
}

void cyclic_swap(int *a, int *b, int *c)
{
    int temp;

    temp = *b;
    *b = *a;
    *a = *c;
    *c = temp;
}