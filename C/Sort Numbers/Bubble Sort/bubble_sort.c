/**
 * Bubble Sort
 * Follow MISRA C Guidelines
 *
 * Algorithm:
 * 1. Start
 * 2. Declare an integer array of size 100 and an integer variable n
 * 3. Input the number of elements
 * 4. Input the elements
 * 5. Loop through the array from i = 0 to n - 1
 *     5.1 Loop through the array from j = 0 to n - i - 1
 *        5.1.1 If the element at index j is greater than the element at index j + 1, then
 *              5.1.1.1 Swap the elements
 * 6. Display the sorted array
 * 7. Stop
 */

#include <stdio.h>

#define MAX 100

void bubble_sort(int *, int);
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

    bubble_sort(arr, n);

    printf("The sorted array is: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void bubble_sort(int *arr, int n)
{
    int i, j, swapped;

    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;

        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        if (swapped == 0)
        {
            break;
        }
    }
}

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}