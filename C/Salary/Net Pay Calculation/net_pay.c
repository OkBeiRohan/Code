/**
 * Create a structure for employee with empno, name, basicpay. Calculate HRA as 15% of basic pay and DA as 70% of basic pay. Calculate the gross pay and deduct tax of 20% to calculate netpay
 * 
 * Algorithm:
 * 1. Start
 * 2. Declare structure employee with empno, name, basicpay
 * 3. Declare variables hra, da, grosspay, netpay
 * 4. Read empno, name, basicpay
 * 5. Calculate hra, da, grosspay, netpay
 * 6. Display empno, name, basicpay, hra, da, grosspay, netpay
 * 7. Stop
 */

#include <stdio.h>
#include <string.h>

struct employee
{
    int empno;
    char name[20];
    float basicpay;
};

int main()
{
    struct employee emp;
    float hra, da, grosspay, netpay;
    printf("Enter the employee number: ");
    scanf("%d", &emp.empno);
    printf("Enter the employee name: ");
    scanf("%s", emp.name);
    printf("Enter the basic pay: ");
    scanf("%f", &emp.basicpay);
    hra = 0.15 * emp.basicpay;
    da = 0.7 * emp.basicpay;
    grosspay = emp.basicpay + hra + da;
    netpay = grosspay - 0.2 * grosspay;
    printf("Employee number: %d\n", emp.empno);
    printf("Employee name: %s\n", emp.name);
    printf("Basic pay: %f\n", emp.basicpay);
    printf("HRA: %f\n", hra);
    printf("DA: %f\n", da);
    printf("Gross pay: %f\n", grosspay);
    printf("Net pay: %f\n", netpay);
    return 0;
}