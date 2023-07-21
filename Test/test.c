#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("no of arguments are:%d", argc);
    printf("\narguments are:");
    for (int i = 0; i < argc; i++)
    {
        printf("\n%s", argv[i]);
    }
    return 0;
}