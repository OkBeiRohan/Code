/**
 * Insertion Sort
 * Follow MISRA C Guidelines
 *
 * Algorithm:
 * 1. Start
 * 2. Declare an integer array of size 100 and an integer variable n
 * 3. Input the number of elements
 * 4. Input the elements
 * 5. Loop through the array from i = 1 to n - 1
 *   5.1 Set key to the element at index i
 *  5.2 Loop through the array from j = i - 1 to 0
 *   5.2.1 If the element at index j is greater than key, then
 *      5.2.1.1 Set the element at index j + 1 to the element at index j
 * 5.3 Set the element at index j + 1 to key
 * 6. Display the sorted array
 * 7. Stop
 */

#include <stdio.h>

#define MAX 100

void insertion_sort(int *, int);

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

    insertion_sort(arr, n);

    printf("The sorted array is: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void insertion_sort(int *arr, int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];

        for (j = i - 1; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
        }

        arr[j + 1] = key;
    }
}