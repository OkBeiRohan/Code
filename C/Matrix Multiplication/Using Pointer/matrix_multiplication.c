/**
 * Matrix multiplication using pointers
 *
 * Algorithm:
 * 1. Read the number of rows and columns of the first matrix
 * 2. Read the number of rows and columns of the second matrix
 * 3. If the number of columns of the first matrix is not equal to the number of rows of the second matrix, print an error message and exit
 * 4. Read the elements of the first matrix
 * 5. Read the elements of the second matrix
 * 6. Multiply the two matrices
 *      1. Initialize the product matrix with 0
 *      2. Iterate over the rows of the first matrix
 *      3. Iterate over the columns of the second matrix
 *      4. Iterate over the columns of the first matrix
 *      5. Multiply the corresponding elements of the two matrices and add it to the product matrix
 *      6. Repeat steps 2 to 5 until the end of the first matrix
 * 7. Print the product matrix
 *
 */

#include <stdio.h>

int main()
{
    int m, n, p, q, i, j, k;

    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &m, &n);

    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &p, &q);

    if (n != p)
    {
        printf("The matrices cannot be multiplied with each other\n");
        return 0;
    }

    int a[m][n], b[p][q], c[m][q];

    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", (*(a + i) + j));

    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < p; i++)
        for (j = 0; j < q; j++)
            scanf("%d", (*(b + i) + j));

    for (i = 0; i < m; i++)
        for (j = 0; j < q; j++)
            *(*(c + i) + j) = 0;

    for (i = 0; i < m; i++)
        for (j = 0; j < q; j++)
            for (k = 0; k < n; k++)
                *(*(c + i) + j) += (*(*(a + i) + k)) * (*(*(b + k) + j));

    printf("The product of the two matrices is:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < q; j++)
            printf("%d ", *(*(c + i) + j));
        printf("\n");
    }

    return 0;
}