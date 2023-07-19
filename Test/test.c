#include <stdio.h>

struct status
{
    int ON;
    int OFF;
};

struct name
{
    int ON : 1;
    int OFF : 1;
};

int main(void)
{
    printf("%ld\n", sizeof(struct status));
    printf("%ld", sizeof(struct name));
}