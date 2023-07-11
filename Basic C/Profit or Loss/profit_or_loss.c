/**
 * Calculate Profit or Loss
 */

#include <stdio.h>

int main()
{
    int cp, sp, profit, loss;
    printf("Enter cost price: ");
    scanf("%d", &cp);
    printf("Enter selling price: ");
    scanf("%d", &sp);
    if (sp > cp)
    {
        profit = sp - cp;
        printf("Profit = %d", profit);
    }
    else if (cp > sp)
    {
        loss = cp - sp;
        printf("Loss = %d", loss);
    }
    else
    {
        printf("No Profit No Loss.");
    }
    return 0;
}