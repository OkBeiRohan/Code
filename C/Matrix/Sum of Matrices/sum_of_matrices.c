/**
 * Sum of two matrices
 * 
 * Algorithm:
 * 1. Start
 * 2. Input the number of rows and columns of the matrices
 * 3. Input the elements of the first matrix
 * 4. Input the elements of the second matrix
 * 5. Add each element of the first matrix with the corresponding element of the second matrix and store the sum in another matrix
 * 6. Display all three matrices
 * 7. Stop
 */

#include <stdio.h>

void input(int m, int n, int a[m][n])
{
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}

void display(int m, int n, int a[m][n])
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void sum(int m, int n, int a[m][n], int b[m][n], int c[m][n])
{
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            c[i][j] = a[i][j] + b[i][j];
}

void print_space(int col)
{
    int i, limit;
    limit = col % 2 == 0 ? col / 2 : (col / 2) + 1;
    for (i = 0; i <= limit; i++)
        printf(" ");
}

int main()
{
    int m, n;
    printf("Enter the number of rows and columns of the matrices:\n");
    scanf("%d%d", &m, &n);
    int a[m][n], b[m][n], c[m][n];
    printf("Enter the elements of the first matrix:\n");
    input(m, n, a);
    printf("Enter the elements of the second matrix:\n");
    input(m, n, b);
    sum(m, n, a, b, c);
    printf("The sum of the matrices is:\n");
    display(m, n, a);
    print_space(n);
    printf("+\n");
    display(m, n, b);
    print_space(n);
    printf("=\n");
    display(m, n, c);
    return 0;
}