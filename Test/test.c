#include <stdio.h>

int main()
{
    volatile int i = 4, x;
    x = i++ + i++ + i++ + i++;
    printf("%d", x);
}