#include <stdio.h>

struct date
{
    int dd : 5;
    int mm : 4;
    // int yy;
};

union test
{
    int a;
    float b;
} t;

int main()
{
    printf("Size of date: %d\n", sizeof(struct date));
    printf("Size of test: %d\n", sizeof(union test));

    t.a = 10;
    printf("t.a = %d\n", t.a);
    t.b = 20.5;
    printf("t.b = %f\n", t.b);
    printf("t.a = %d\n", t.a);
}