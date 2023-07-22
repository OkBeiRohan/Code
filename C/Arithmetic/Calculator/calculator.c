/**
 * Calculator
 *
 * This program takes two numbers and an operator as input and performs the operation on the numbers.
 * Algorithm:
 * 1. Start
 * 2. Declare two double variables a and b and a character variable op
 * 3. Input the operation
 * 4. Check if the operation is +, -, *, / or %
 *   4.1 If yes, then
 *    4.1.1 print the result of the operation
 *  4.2 Else
 *   4.2.1 print "Invalid operation"
 * 5. Stop
 */

#include <stdio.h>

int main()
{
    double a, b;
    char op;
    printf("Enter an operation (eg: 5+1): ");
    scanf("%lf%c%lf", &a, &op, &b);
    switch (op)
    {
    case '+':
        printf("%lf %c %lf = %lf", a, op, b, a + b);
        break;
    case '-':
        printf("%lf %c %lf = %lf", a, op, b, a - b);
        break;
    case '*':
    case 'x':
    case 'X':
        printf("%lf %c %lf = %lf", a, op, b, a * b);
        break;
    case '/':
        printf("%lf %c %lf = %lf", a, op, b, a / b);
        break;
    case '%':
        printf("%lf %c %lf = %d", a, op, b, (int)a % (int)b);
        break;
    default:
        printf("Invalid operation");
    }
    return 0;
}