/**
 * Read and append in a file
 */

#include <stdio.h>

int main()
{
    char file_buffer[100];
    printf("Opening File...\n");
    FILE *file_ptr = fopen("read_append.txt", "r+");
    if (file_ptr == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    fgets(file_buffer, 100, file_ptr);
    printf("The content in the file is %s\n\n", file_buffer);
    printf("Enter the content to append in the file: ");
    gets(file_buffer);
    fputs(file_buffer, file_ptr);
    printf("\nThe content in the file after appending is: ");
    rewind(file_ptr);
    fgets(file_buffer, 100, file_ptr);
    printf("%s", file_buffer);
    fclose(file_ptr);
}