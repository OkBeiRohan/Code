/**
 * Program to generate salary slip
 */

#include <stdio.h>
#include <string.h>

enum designations
{
    E0,
    E1,
    E2,
    E3,
};

struct salary
{
    double basic_salary;
    double hra;
    double da;
    double pf;
    double gross_salary;
    double net_pay;
};

struct tax
{
    double tax_rate;
    double exempted_income;
    double taxable_income;
    double yearly_tax;
    double monthly_tax;
};

struct employee
{
    int employee_code;
    char name[100];
    enum designations designation;
    struct salary salary;
    struct tax tax;
};

double calculate_hra(double basic_salary, enum designations designation)
{
    double hra;
    switch (designation)
    {
    case E0:
        hra = 0.55 * basic_salary;
        break;
    case E1:
        hra = 0.6 * basic_salary;
        break;
    case E2:
        hra = 0.65 * basic_salary;
        break;
    case E3:
        hra = 0.7 * basic_salary;
        break;
    default:
        hra = 0;
    }

    return hra;
}

double calculate_da(double basic_salary, enum designations designation)
{
    double da;
    switch (designation)
    {
    case E0:
        da = 0;
        break;
    case E1:
    case E2:
    case E3:
        da = 0.9 * basic_salary;
        break;
    default:
        da = 0;
    }

    return da;
}

double calculate_pf(double basic_salary)
{
    return 0.05 * basic_salary;
}

double calculate_gross_salary(double basic_salary, double hra, double da)
{
    return basic_salary + hra + da;
}

double calculate_taxable_income(double gross_salary, double pf, double exempted_income)
{
    return gross_salary - pf - exempted_income;
}

double calculate_yearly_salary(double taxable_income, double tax_rate)
{
    return taxable_income * tax_rate;
}

double calculate_monthly_salary(double yearly_salary)
{
    return yearly_salary / 12;
}

double calculate_net_pay(double gross_salary, double monthly_tax)
{
    return (gross_salary / 12) - monthly_tax;
}

void print_designation(enum designations designation)
{
    switch (designation)
    {
    case E0:
        printf("E0\n");
        break;
    case E1:
        printf("E1\n");
        break;
    case E2:
        printf("E2\n");
        break;
    case E3:
        printf("E3\n");
        break;
    default:
        printf("Unknown\n");
    }
}
void print_salary_slip(struct employee employee)
{
    printf("\n\n");
    printf("\tSALARY SLIP\n\n");
    printf("Employee Details\n");
    printf("Employee Code: %d\n", employee.employee_code);
    printf("Name: %s\n", employee.name);
    printf("Designation: ");
    print_designation(employee.designation);
    printf("\n\nSalary Details\n");
    printf("Basic Salary: %.2lf\n", employee.salary.basic_salary);
    printf("HRA: %.2lf\n", employee.salary.hra);
    printf("DA: %.2lf\n", employee.salary.da);
    printf("PF: %.2lf\n", employee.salary.pf);
    printf("Gross Salary: %.2lf\n", employee.salary.gross_salary);
    printf("\n\nTax Details\n");
    printf("Exempted Income: %.2lf\n", employee.tax.exempted_income);
    printf("Tax Rate: %.2lf\n", employee.tax.tax_rate);
    printf("Taxable Income: %.2lf\n", employee.tax.taxable_income);
    printf("Yearly Tax: %.2lf\n", employee.tax.yearly_tax);
    printf("Monthly Tax: %.2lf\n", employee.tax.monthly_tax);
    printf("\n\nTAKE HOME SALARY\n");
    printf("Net Pay: %.2lf\n", employee.salary.net_pay);
}

int main()
{
    struct employee employee;
    printf("Enter employee code: ");
    scanf("%d", &employee.employee_code);
    printf("Enter name: ");
    getchar();
    gets(employee.name);
    printf("Enter designation: ");
    scanf("%d", &employee.designation);
    printf("Enter basic salary: ");
    scanf("%lf", &employee.salary.basic_salary);

    employee.tax.exempted_income = 150000;
    employee.tax.tax_rate = 0.25;

    employee.salary.hra = calculate_hra(employee.salary.basic_salary, employee.designation);
    employee.salary.da = calculate_da(employee.salary.basic_salary, employee.designation);
    employee.salary.pf = calculate_pf(employee.salary.basic_salary);
    employee.salary.gross_salary = calculate_gross_salary(employee.salary.basic_salary, employee.salary.hra, employee.salary.da);
    employee.tax.taxable_income = calculate_taxable_income(employee.salary.gross_salary, employee.salary.pf, employee.tax.exempted_income);
    employee.tax.yearly_tax = calculate_yearly_salary(employee.tax.taxable_income, employee.tax.tax_rate);
    employee.tax.monthly_tax = calculate_monthly_salary(employee.tax.yearly_tax);
    employee.salary.net_pay = calculate_net_pay(employee.salary.gross_salary, employee.tax.monthly_tax);

    print_salary_slip(employee);

    return 0;
}