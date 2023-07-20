/**
 * Calculator
 * 
 * Algorithm:
 * 1. Clear the screen
 * 2. Print menu
 * 3. Take choice as input
 * 4. If choice is 5, exit
 * 5. If choice is invalid, print error and goto step 1
 * 6. Take two numbers as input
 * 7. If choice is 1, add the numbers and print
 * 8. If choice is 2, subtract the numbers and print
 * 9. If choice is 3, multiply the numbers and print
 * 10. If choice is 4, divide the numbers and print
 * 11. Goto step 1
 * 12. Stop
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