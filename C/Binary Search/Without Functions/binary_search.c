/**
 * Binary Search without using functions
 */

#include <stdio.h>
#include <stdlib.h>

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
    int low = 0, high = count - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (numbers[mid] == key)
        {
            printf("Key found at index %d\n", mid);
            return 0;
        }
        else if (numbers[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    printf("Key not found\n");
    free(numbers);
    return 0;
}