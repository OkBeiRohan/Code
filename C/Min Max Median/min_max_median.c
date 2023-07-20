/**
 * Accept ten numbers and print its average, total, minimum, maximum and median value
 */

#include <stdio.h>

int main()
{
    int n = 10, arr[10], i, min, max, sum = 0;
    double avg, median;
    printf("Enter 10 numbers: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    avg = sum / n;
    min = arr[0];
    max = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }
    if (n % 2 == 0)
        median = (arr[n / 2] + arr[n / 2 - 1]) / 2.0;
    else
        median = arr[n / 2];
    printf("Average = %.2lf\n", avg);
    printf("Total = %d\n", sum);
    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);
    printf("Median = %.2lf\n", median);
    return 0;
}