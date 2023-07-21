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

union test2
{
    int a;
    int b;
} t2;

int main()
{
    printf("Size of date: %d\n", sizeof(struct date));
    printf("Size of test: %d\n", sizeof(union test));
    printf("Size of test2: %d\n", sizeof(union test2));

    t.a = 1500000000;
    printf("t.a = %d\n", t.a);
    t.b = 20.5;
    printf("t.b = %f\n", t.b);
    printf("t.a = %d\n", t.a);
    t.a = 30;
    printf("t.a = %d\n", t.a);
    printf("t.b = %f\n", t.b);

    t2.a = 50;
    t2.b = 20;
    printf("t2.a = %d\n", t2.a);
    printf("t2.b = %d\n", t2.b);
}