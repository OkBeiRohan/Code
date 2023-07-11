/**
 * Calculator
 */

#include <stdio.h>
#include <conio.h>

int main()
{
    int a, b, choice;
CALC:
    printf("\e[1;1H\e[2J"); // Clear the screen
    printf("\tCALCULATOR\n\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n");
    printf("\nEnter your option (1-5): ");
    scanf("%d", &choice);
    if (choice == 5)
        return 0;
    if (choice > 5 || choice < 1)
    {
        printf("\nInvalid option!\n\nPress any key to return to menu...");
        getch();
        goto CALC;
    }
    printf("\nEnter the two numbers: ");
    scanf("%d %d", &a, &b);
    switch (choice)
    {
    case 1:
        printf("\n%d + %d = %d", a, b, a + b);
        printf("\n\nPress any key to return to menu...");
        getch();
        goto CALC;
    case 2:
        printf("\n%d - %d = %d", a, b, a - b);
        printf("\n\nPress any key to return to menu...");
        getch();
        goto CALC;
    case 3:
        printf("\n%d * %d = %d", a, b, a * b);
        printf("\n\nPress any key to return to menu...");
        getch();
        goto CALC;
    case 4:
        printf("\n%d / %d = %d", a, b, a / b);
        printf("\n\nPress any key to return to menu...");
        getch();
        goto CALC;
    default:
        break;
    }
}