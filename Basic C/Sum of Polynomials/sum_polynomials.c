/**
 * Sum of two polynomials
 */

#include <stdio.h>

struct polynomial
{
    int coeff;
    int degree;
};

void input_terms(int *n)
{
    printf("Enter the number of terms: ");
    scanf("%d", n);
}

void input_polynomial(struct polynomial *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficient of term %d: ", i + 1);
        scanf("%d", &p[i].coeff);
        printf("Enter the degree of term %d: ", i + 1);
        scanf("%d", &p[i].degree);
    }
}

void display_polynomial(struct polynomial *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (p[i].coeff == 0)
            continue;
        if (p[i].coeff != 1 && p[i].coeff != -1)
            printf("%d", p[i].coeff);
        if (p[i].coeff == 1 && p[i].degree == 0)
            printf("1");
        if (p[i].coeff == -1 && p[i].degree != 0)
            printf("-");
        if (p[i].degree != 0 && p[i].degree != 1)
            printf("x^%d", p[i].degree);
        if (p[i].degree == 1)
            printf("x");
        if (i != n - 1)
            printf(" + ");
    }
}

void sort_polynomial(struct polynomial *p, int n)
{
    struct polynomial temp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (p[j].degree < p[j + 1].degree)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
}

int main()
{
    int n1, n2, n3 = 0, flag = 0, k = 0;

    printf("Enter the first polynomial:\n");
    input_terms(&n1);
    struct polynomial p1[n1];
    input_polynomial(p1, n1);
    sort_polynomial(p1, n1);

    printf("\n\nEnter the second polynomial:\n");
    input_terms(&n2);
    struct polynomial p2[n2];
    input_polynomial(p2, n2);
    sort_polynomial(p2, n2);

    for (int i = 0; i < n1; i++)
    {
        flag = 0;
        for (int j = 0; j < n2; j++)
            if (p1[i].degree == p2[j].degree)
            {
                n3++;
                flag = 1;
            }
        if (flag == 0)
            n3++;
    }
    for (int i = 0; i < n2; i++)
    {
        flag = 0;
        for (int j = 0; j < n1; j++)
            if (p2[i].degree == p1[j].degree)
                flag = 1;
        if (flag == 0)
            n3++;
    }
    struct polynomial p3[n3];

    for (int i = 0; i < n1; i++)
    {
        flag = 0;
        for (int j = 0; j < n2; j++)
            if (p1[i].degree == p2[j].degree)
            {
                p3[k].coeff = p1[i].coeff + p2[j].coeff;
                p3[k].degree = p1[i].degree;
                k++;
                flag = 1;
            }
        if (flag == 0)
        {
            p3[k].coeff = p1[i].coeff;
            p3[k].degree = p1[i].degree;
            k++;
        }
    }
    for (int i = 0; i < n2; i++)
    {
        flag = 0;
        for (int j = 0; j < n1; j++)
            if (p2[i].degree == p3[j].degree)
                flag = 1;
        if (flag == 0)
        {
            p3[k].coeff = p2[i].coeff;
            p3[k].degree = p2[i].degree;
            k++;
        }
    }
    sort_polynomial(p3, n3);

    printf("\n\nThe sum of the two polynomials is:\n");
    display_polynomial(p1, n1);
    printf("\n+\n");
    display_polynomial(p2, n2);
    printf("\n=\n");
    display_polynomial(p3, n3);
    printf("\n\n");

    return 0;
}