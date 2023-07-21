/**
 * Generate a diagonal matrix with the given order and initialise diagonal elements as 1 and non-diagonal elements as 0.
 *
 * Algorithm:
 * 1. Start
 * 2. Input the order of the matrix
 * 3. Check if the order is equal, if not, display an error message and stop
 * 4. Generate the diagonal matrix
 *      4.1. For each element of the matrix, check if the row number is equal to the column number
 *      4.2. If yes, set the element as 1
 *      4.3. If no, set the element as 0
 * 5. Display the matrix
 * 6. Stop
 */

#include <stdio.h>

void input(int, int, int[*][*]);
void display(int, int, int[*][*]);
void diagonal_matrix(int, int, int[*][*]);

int main()
{
    int m, n;
    printf("Enter the order of the matrix: ");
    scanf("%d%d", &m, &n);
    if (m != n)
    {
        printf("The order of the matrix must be equal.\n");
        return 1;
    }
    int a[m][n];
    diagonal_matrix(m, n, a);
    printf("The diagonal matrix is:\n");
    display(m, n, a);
    return 0;
}

void input(int m, int n, int a[m][n])
{
    int i, j;
    printf("Enter the elements of the matrix:\n");
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

void diagonal_matrix(int m, int n, int a[m][n])
{
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            a[i][j] = i == j ? 1 : 0;
}