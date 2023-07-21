/**
 * Sum of n numbers
 *
 * Algorithm:
 * 1. Start
 * 2. Read the value of n
 * 3. Allocate memory for n numbers
 * 4. Read n numbers
 * 5. Calculate sum of n numbers by adding each number to sum
 * 6. Print sum
 * 7. Free memory
 * 8. Stop
 */

#include <stdio.h>
#include <stdlib.h>

double sum(unsigned int, double *);

int main()
{
    unsigned int count;
    printf("Enter the number of elements: ");
    scanf("%u", &count);
    double *numbers = (double *)malloc(count * sizeof(double));
    printf("Enter the elements: ");
    for (unsigned int i = 0; i < count; i++)
        scanf("%lf", &numbers[i]);
    printf("Sum = %lf\n", sum(count, numbers));
    free(numbers);
    return 0;
}

double sum(unsigned int count, double *numbers)
{
    double result = 0;
    for (unsigned int i = 0; i < count; i++)
        result += numbers[i];
    return result;
}
