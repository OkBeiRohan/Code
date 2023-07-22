/**
 * Command line arguments
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    printf("%d command line arguments were passed. They are:\n", argc);

    for (i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    return 0;
}