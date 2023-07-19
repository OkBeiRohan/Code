/**
 * Distance between two points
 */

#include <stdio.h>
#include <math.h>

struct point
{
    double x;
    double y;
};

int main()
{
    struct point p1, p2;
    double dist;

    printf("Enter the coordinates of point 1: ");
    scanf("%lf%lf", &p1.x, &p1.y);

    printf("Enter the coordinates of point 2: ");
    scanf("%lf%lf", &p2.x, &p2.y);

    dist = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));

    printf("Distance between the points: %lf\n", dist);

    return 0;
}
