/**
 * Check if whether the matrix is sparse
 *
 * Algorithm:
 * 1. Take the matrix as input
 * 2. Count the number of zeros in the matrix
 *      2.1 Iterate through the matrix
 *      2.2 If the element is zero, increment the count
 * 3. If the count is greater than the threshold value, print that the matrix is sparse
 * 4. Else print that the matrix is not sparse
 */

#include <stdio.h>

#define ROW 3
#define COL 3
#define THRESHOLD 6

int main()
{
    int m = ROW, n = COL, i, j, count = 0;
    int a[m][n];
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    printf("The matrix is:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] == 0)
                count++;
    if (count > THRESHOLD)
        printf("The matrix is sparse\n");
    else
        printf("The matrix is not sparse\n");
    return 0;
}