/**
 * Selection Sort
 * Follow MISRA C Guidelines
 *
 * Algorithm:
 * 1. Start
 * 2. Declare an integer array of size 100 and an integer variable n
 * 3. Input the number of elements
 * 4. Input the elements
 * 5. Loop through the array from i = 0 to n - 1
 *    5.1 Set min_idx to i
 *   5.2 Loop through the array from j = i + 1 to n
 *     5.2.1 If the element at index j is less than the element at index min_idx, then
 *      5.2.1.1 Set min_idx to j
 *  5.3 Swap the elements at index i and min_idx
 * 6. Display the sorted array
 * 7. Stop
 */

#include <stdio.h>

#define MAX 100

void selection_sort(int *, int);
void swap(int *, int *);

int main()
{
    int arr[MAX], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    selection_sort(arr, n);

    printf("The sorted array is: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void selection_sort(int *arr, int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        swap(&arr[min_idx], &arr[i]);
    }
}

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}