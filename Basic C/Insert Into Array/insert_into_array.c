/**
 * Insert a value to a position in an array and shift the rest of the values to the right
 */

#include <stdio.h>

int main()
{
    int arr[50], n, pos, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter position to insert: ");
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &val);
    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = val;
    n++;
    printf("Array after insertion: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}