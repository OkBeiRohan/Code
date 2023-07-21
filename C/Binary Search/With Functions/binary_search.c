/**
 * Binary Search
 *
 * Algorithm:
 * 1. Start
 * 2. Read the number of elements
 * 3. Allocate memory for n numbers
 * 4. Read n numbers
 * 5. Read the key to search for
 * 6. If the low index is greater than the high index, then the key is not found
 * 7. Calculate the mid index
 * 8. If the key is found at the mid index, then return the mid index
 * 9. If the key is less than the mid element, then search in the left half
 * 10. If the key is greater than the mid element, then search in the right half
 * 11. Stop
 */

#include <stdio.h>
#include <stdlib.h>

int binary_search(int *, int, int, int);

int main()
{
    int count;
    printf("Enter the number of elements: ");
    scanf("%d", &count);
    int *numbers = (int *)malloc(count * sizeof(int));
    printf("Enter the elements in ascending order: ");
    for (int i = 0; i < count; i++)
        scanf("%d", &numbers[i]);
    int key;
    printf("Enter the key: ");
    scanf("%d", &key);
    int index = binary_search(numbers, 0, count - 1, key);
    if (index == -1)
        printf("Key not found\n");
    else
        printf("Key found at index %d\n", index);
    free(numbers);
    return 0;
}

int binary_search(int *numbers, int low, int high, int key)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (numbers[mid] == key)
        return mid;
    else if (numbers[mid] > key)
        return binary_search(numbers, low, mid - 1, key);
    else
        return binary_search(numbers, mid + 1, high, key);
}