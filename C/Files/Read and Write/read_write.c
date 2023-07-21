/**
 * Read and rewrite in a file
 */

#include <stdio.h>

int main()
{
    char file_buffer[100];
    printf("Opening File...\n");
    FILE *file_ptr = fopen("read_write.txt", "r");
    if (file_ptr == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    fgets(file_buffer, 100, file_ptr);
    fclose(file_ptr);
    printf("The content in the file is %s\n\n", file_buffer);
    printf("Enter the content to rewrite in the file: ");
    gets(file_buffer);
    file_ptr = fopen("read_write.txt", "w");
    fputs(file_buffer, file_ptr);
    fclose(file_ptr);
    printf("\nThe content in the file after rewriting is: ");
    file_ptr = fopen("read_write.txt", "r");
    rewind(file_ptr);
    fgets(file_buffer, 100, file_ptr);
    printf("%s", file_buffer);
    fclose(file_ptr);
}