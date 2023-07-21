/**
 * Print lines
 *
 * Algorithm:
 * 1. Start
 * 2. Input the number of lines
 * 3. Print a underscore (_) for each column till the width is reached
 * 4. Print a new line
 * 5. Repeat steps 3 and 4 till the number of lines is reached
 * 6. Stop
 */

#include <stdio.h>
#define width 40

void print_line();
void print_lines(int);

int main()
{
    int n;
    printf("Enter the number of lines: ");
    scanf("%d", &n);
    print_lines(n);
    return 0;
}

void print_line()
{
    for (int i = 0; i < width; i++)
        printf("_");
    printf("\n");
}

void print_lines(int n)
{
    for (int i = 0; i < n; i++)
        print_line();
}