/**
 * Count total number of notes in the amount
 */

#include <stdio.h>

int main()
{
    int amount, notes;
    printf("Enter amount: ");
    scanf("%d", &amount);
    printf("\n");
    printf("Total number of notes:\n");
    printf("----------------------\n");
    notes = amount / 2000;
    printf("Rs. 2000 = %d\n", notes);
    amount = amount - notes * 2000;
    notes = amount / 500;
    printf("Rs. 500 = %d\n", notes);
    amount = amount - notes * 500;
    notes = amount / 100;
    printf("Rs. 100 = %d\n", notes);
    amount = amount - notes * 100;
    notes = amount / 50;
    printf("Rs. 50 = %d\n", notes);
    amount = amount - notes * 50;
    notes = amount / 20;
    printf("Rs. 20 = %d\n", notes);
    amount = amount - notes * 20;
    notes = amount / 10;
    printf("Rs. 10 = %d\n", notes);
    amount = amount - notes * 10;
    notes = amount / 5;
    printf("Rs. 5 = %d\n", notes);
    amount = amount - notes * 5;
    notes = amount / 2;
    printf("Rs. 2 = %d\n", notes);
    amount = amount - notes * 2;
    notes = amount / 1;
    printf("Rs. 1 = %d\n", notes);
    return 0;
}