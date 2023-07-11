/**
 * Calculate Electricity Bill
 */

#include <stdio.h>

int main()
{
    int units;
    double amount, total_amount, surcharge;
    printf("Enter total units consumed: ");
    scanf("%d", &units);
    if (units <= 50)
        amount = units * 0.5;
    else if (units <= 150)
        amount = 25 + ((units - 50) * 0.75);
    else if (units <= 250)
        amount = 100 + ((units - 150) * 1.2);
    else
        amount = 220 + ((units - 250) * 1.5);
    surcharge = amount * 0.2;
    total_amount = amount + surcharge;
    printf("Electricity Bill = Rs. %.2lf", total_amount);
    return 0;
}