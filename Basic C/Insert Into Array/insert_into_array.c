/**
 * Insert a value to a position in an array and shift the rest of the values to the right
 * 
 * Algorithm:
 * 1. Take number of elements as input
 * 2. Take elements as input
 * 3. Take position to insert as input
 * 4. Take value to insert as input
 * 5. Loop from number of elements to position to insert (i.e. n to pos) (reverse loop)
 * 6. Shift elements to the right
 * 7. Insert value at position
 * 8. Increment number of elements
 * 9. Loop from 0 to number of elements
 * 10. Print elements
 * 11. Stop
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