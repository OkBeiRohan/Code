/**
 * Program using all the operators in C
 */

#include <stdio.h>

int main()
{
    int a = 10, b = 5;
    printf("Values\na = %d, b = %d\n", a, b);

    // Arithmetic Operators
    printf("\nArithmetic Operators\n");
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("a %% b = %d\n", a % b);

    // Relational Operators
    printf("\nRelational Operators\n");
    printf("a == b = %d\n", a == b);
    printf("a != b = %d\n", a != b);
    printf("a > b = %d\n", a > b);
    printf("a < b = %d\n", a < b);
    printf("a >= b = %d\n", a >= b);
    printf("a <= b = %d\n", a <= b);

    // Logical Operators
    printf("\nLogical Operators\n");
    printf("a && b = %d\n", a && b);
    printf("a || b = %d\n", a || b);
    printf("!a = %d\n", !a);
    printf("!b = %d\n", !b);

    // Bitwise Operators
    printf("\nBitwise Operators\n");
    printf("a & b = %d\n", a & b);
    printf("a | b = %d\n", a | b);
    printf("a ^ b = %d\n", a ^ b);
    printf("~a = %d\n", ~a);
    printf("a << 1 = %d\n", a << 1);
    printf("a >> 1 = %d\n", a >> 1);

    // Assignment Operators
    printf("\nAssignment Operators\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("a += b = %d\n", a += b);
    printf("a -= b = %d\n", a -= b);
    printf("a *= b = %d\n", a *= b);
    printf("a /= b = %d\n", a /= b);
    printf("a %%= b = %d\n", a %= b);
    printf("a &= b = %d\n", a &= b);
    printf("a |= b = %d\n", a |= b);
    printf("a ^= b = %d\n", a ^= b);
    printf("a <<= 1 = %d\n", a <<= 1);
    printf("a >>= 1 = %d\n", a >>= 1);

    // Increment and Decrement Operators
    printf("\nIncrement and Decrement Operators\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("a++ = %d\n", a++);
    printf("++a = %d\n", ++a);
    printf("b-- = %d\n", b--);
    printf("--b = %d\n", --b);

    // Sizeof Operator
    printf("\nSizeof Operator\n");
    printf("sizeof(a) = %d\n", sizeof(a));
    printf("sizeof(b) = %d\n", sizeof(b));

    // Ternary Operator
    printf("\nTernary Operator\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("a > b ? a : b = %d\n", a > b ? a : b);

    return 0;
}