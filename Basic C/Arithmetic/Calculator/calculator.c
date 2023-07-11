/**
 * Calculator
 */

#include <stdio.h>

int main()
{
    int a, b;
    char op;
    printf("Enter an operation (eg: 5+1): ");
    scanf("%d%c%d", &a, &op, &b);
    switch (op)
    {
    case '+':
        printf("%d", a + b);
        break;
    case '-':
        printf("%d", a - b);
        break;
    case '*':
    case 'x':
    case 'X':
        printf("%d", a * b);
        break;
    case '/':
        printf("%d", a / b);
        break;
    case '%':
        printf("%d", a % b);
        break;
    default:
        printf("Invalid operation");
    }
    return 0;
}