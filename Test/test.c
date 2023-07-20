#include <stdio.h>

struct test
{
    int id;
    char name[13];
};

int main()
{
    struct test t, *t_ptr;
    t_ptr = &t;
    printf("%d\n", sizeof(t));
    printf("%d\n", t_ptr);
    printf("%d\n", ++t_ptr);
}