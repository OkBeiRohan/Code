#include <stdio.h>
#include <string.h>

void reverse(char *str, int start, int end)
{
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    gets(str);

    int start = 0;
    int end = 0;

    while (str[end] != '\0')
    {
        if (str[end] == ' ')
        {
            reverse(str, start, end - 1);
            start = end + 1;
        }

        end++;
    }

    reverse(str, start, end - 1);

    printf("%s\n", str);

    return 0;
}