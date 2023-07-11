/**
 * Calculate Gross Salary
 */

#include <stdio.h>

int main()
{
    double basic_salary, gross_salary, da, hra;
    printf("Enter basic salary: ");
    scanf("%lf", &basic_salary);
    if (basic_salary <= 10000)
    {
        da = basic_salary * 0.8;
        hra = basic_salary * 0.2;
    }
    else if (basic_salary <= 20000)
    {
        da = basic_salary * 0.9;
        hra = basic_salary * 0.25;
    }
    else
    {
        da = basic_salary * 0.95;
        hra = basic_salary * 0.3;
    }
    gross_salary = basic_salary + da + hra;
    printf("Gross Salary: %.2lf\n", gross_salary);
    return 0;
}