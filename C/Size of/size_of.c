/**
 * Write a program to print the size of bytes allotted for int, char, double, int *, char * and double *. Also print the size of character array of 80 characters.
 *
 * Algorithm:
 * 1. Start
 * 2. Print the size of int
 * 3. Print the size of char
 * 4. Print the size of double
 * 5. Print the size of int *
 * 6. Print the size of char *
 * 7. Print the size of double *
 * 8. Print the size of character array of 80 characters
 * 9. Stop
 */

#include <stdio.h>

int main()
{
    printf("Size of int: %d\n", sizeof(int));
    printf("Size of char: %d\n", sizeof(char));
    printf("Size of double: %d\n", sizeof(double));
    printf("Size of int *: %d\n", sizeof(int *));
    printf("Size of char *: %d\n", sizeof(char *));
    printf("Size of double *: %d\n", sizeof(double *));
    printf("Size of character array of 80 characters: %d\n", sizeof(char[80]));
    return 0;
}