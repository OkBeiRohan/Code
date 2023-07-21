/**
 * Calculator
 *
 * Algorithm:
 * 1. Clear the screen
 * 2. Print menu
 * 3. Take choice as input
 * 4. If choice is 5, Go to step 12
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
#include <stdlib.h>

void print_menu();
void input_choice(int *);
int check_choice(int);
void input(double *, double *);
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double operate(int, double, double);

int main()
{
    int choice;
    double a, b;
CALC:
    print_menu();
    input_choice(&choice);
    if (!check_choice(choice))
        goto CALC;
    input(&a, &b);
    printf("\nResult: %lf", operate(choice, a, b));
    printf("\nPress any key to return to menu...");
    getch();
    goto CALC;
}

void print_menu()
{
    printf("\e[1;1H\e[2J"); // Clear the screen
    printf("\tCALCULATOR\n\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n");
    printf("\nEnter your option (1-5): ");
}

void input_choice(int *choice)
{
    scanf("%d", choice);
}

int check_choice(int choice)
{
    if (choice > 5 || choice < 1)
    {
        printf("\nInvalid option!\n\nPress any key to return to menu...");
        getch();
        return 0;
    }
    else if (choice == 5)
        exit(0);
    else
        return 1;
}

void input(double *a, double *b)
{
    printf("\nEnter the two numbers: ");
    scanf("%lf%lf", a, b);
}

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    return a / b;
}

double operate(int choice, double a, double b)
{
    switch (choice)
    {
    case 1:
        return add(a, b);
    case 2:
        return subtract(a, b);
    case 3:
        return multiply(a, b);
    case 4:
        return divide(a, b);
    default:
        printf("\nError Occurred");
        return 0;
    }
}