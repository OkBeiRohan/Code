/**
 * Largest and smallest in an integer array
 */

#include <stdio.h>

int main()
{
    int i, n, large, small;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    large = small = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] > large)
            large = arr[i];
        if (arr[i] < small)
            small = arr[i];
    }
    printf("Largest = %d\nSmallest = %d", large, small);
    return 0;
}