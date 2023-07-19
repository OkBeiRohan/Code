/**
 * Sort an array using pointers
 *
 * Algorithm:
 * 1. Start
 * 2. Input the number of elements in the array
 * 3. Input the elements of the array
 * 4. Repeat steps 4.1 and 4.2 for i = 0 to n - 1
 *      4.1 Repeat steps 4.1.1 and 4.1.2 for j = 0 to n - 1 - i
 *          4.1.1 If the element at the current position of the array is greater than the element at the next position, then swap the elements
 *          4.1.2 Increment j by 1
 *      4.2 Increment i by 1
 * 5. Display the sorted array
 * 6. Stop
 */

#include <stdio.h>

int main()
{
    int a[100], n, i, j, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", a + i);

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (*(a + j) > *(a + j + 1))
            {
                temp = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = temp;
            }

    printf("The sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", *(a + i));

    return 0;
}