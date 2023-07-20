#include <stdio.h>

/**
 * Here y*y*y is not a single token, it is three tokens.
 * So, x(1+2) is expanded as 1+2*1+2*1+2
 * Which is 1+2+2+2 = 7
 */
#define x(y) y *y *y

int main(void)
{
    printf("%d", x(1 + 2));
}