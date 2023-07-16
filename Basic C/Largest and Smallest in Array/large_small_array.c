/**
 * Largest and smallest in an integer array
 *
 * Algorithm:
 * 1. Take number of elements as input
 * 2. Take elements as input
 * 3. Initialize large and small with first element
 * 4. Loop from 1 to n
 * 5. If element is greater than large, assign element to large
 * 6. If element is smaller than small, assign element to small
 * 7. Print large and small
 * 8. Stop
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