#include <stdio.h>

int main()
{
    printf("Hello World!\n");
    printf("Hello\tWorld!\n");
    printf("Hello\bWorld!\n");
    printf("Hello\rWorld!\n");
    printf("Hello\fWorld!\n");
    printf("Hello\aWorld!\n");
    printf("Hello\\World!\n");
    printf("Hello\'World!\n");
    printf("Hello\"World!\n");
    printf("Hello\?World!\n");
    printf("Hello\0World!\n");
    printf("Hello\vWorld!\n");
    printf("Hello\nWorld!\n");
    printf("\xf1\n");
    printf("\x1f\n");
    return 0;
}