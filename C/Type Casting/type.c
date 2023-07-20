#include <stdio.h>

int main()
{
    char c = 127;
    char c1 = c + 2;
    printf("%d\n", c1);
    char p = 127;
    printf("%d\n", p + 2);
    return 0;
}