/**
 * Multiply two matrices
 *
 * Algorithm:
 * 1. Start
 * 2. Input the order of the first matrix
 * 3. Input the order of the second matrix
 * 4. If the number of columns of the first matrix is not equal to the number of rows of the second matrix, then
 *     4.1 Print "The matrices cannot be multiplied with each other."
 *    4.2 Stop
 * 5. Input the elements of the first matrix
 * 6. Input the elements of the second matrix
 * 7. Multiply the two matrices
 *     7.1 Multiply the elements of the first row of the first matrix with the elements of the first column of the second matrix and add them
 *    7.2 Store the sum in the first row and first column of the resultant matrix
 *   7.3 Repeat steps 7.1 and 7.2 for all the elements of the resultant matrix
 * 8. Display the resultant matrix
 * 9. Stop
 */

#include <stdio.h>

void input(int, int, int[][10]);
void multiply(int, int, int, int[][10], int[][10], int[][10]);
void display(int, int, int[][10]);

int main()
{
    int a[10][10], b[10][10], c[10][10], m, n, p, q;

    printf("Enter the order of the first matrix: ");
    scanf("%d %d", &m, &n);
    printf("Enter the order of the second matrix: ");
    scanf("%d %d", &p, &q);

    if (n != p)
    {
        printf("The matrices cannot be multiplied with each other.\n");
        return 0;
    }

    printf("Enter the elements of the first matrix:\n");
    input(m, n, a);
    printf("Enter the elements of the second matrix:\n");
    input(p, q, b);

    multiply(m, n, q, a, b, c);

    printf("The resultant matrix is:\n");
    display(m, q, c);

    return 0;
}

void input(int m, int n, int a[][10])
{
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}

void multiply(int m, int n, int q, int a[][10], int b[][10], int c[][10])
{
    int i, j, k;

    for (i = 0; i < m; i++)
        for (j = 0; j < q; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
}

void display(int m, int n, int a[][10])
{
    int i, j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}