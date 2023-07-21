/**
 * Do all file operations in the folder ./files with a user menu
 * Create, read, write, append, delete
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum choices
{
    CREATE = 1,
    READ,
    WRITE,
    APPEND,
    INSERT,
    DELETE,
    REMOVE,
    LIST,
    EXIT
};

void menu();
void create_file(char *);
void read_file(char *);
void write_file(char *);
void append_file(char *);
void insert_in_file(char *, char *, unsigned);
void delete_file(char *);
void delete_from_file(char *, unsigned, unsigned);
void operate_choice(enum choices);

int main()
{
MENU:
    menu();
    goto MENU;
}

void menu()
{
    int choice;
    system("cls");
    printf("\n\n1. Create a file\n");
    printf("2. Read a file\n");
    printf("3. Write in a file\n");
    printf("4. Append in a file\n");
    printf("5. Insert in a file\n");
    printf("6. Delete a file\n");
    printf("7. Remove from a file\n");
    printf("8. List files\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();
    operate_choice((enum choices)choice);
}

void create_file(char *file_name)
{
    char path[100] = "./files/";
    strcat(path, file_name);

    printf("Creating file %s\n", path);
    FILE *file_ptr = fopen(path, "w");
    if (file_ptr == NULL)
    {
        printf("Error creating file\n");
        return;
    }
    fclose(file_ptr);

    printf("File created successfully.\nPress any key to continue...");
    getchar();
}

void read_file(char *file_name)
{
    char file_buffer[100], path[100] = "./files/";
    strcat(path, file_name);
    printf("Reading file %s\n", path);

    FILE *file_ptr = fopen(path, "r");
    if (file_ptr == NULL)
    {
        printf("Error opening file. The file probably doesn't exist.\n");
        return;
    }
    fgets(file_buffer, 100, file_ptr);
    printf("%s", file_buffer);
    fclose(file_ptr);

    printf("\n\nPress any key to continue...");
    getchar();
}

void write_file(char *file_name)
{
    char file_buffer[100], path[100] = "./files/";
    strcat(path, file_name);
    printf("Writing file %s\n", path);

    FILE *file_ptr = fopen(path, "w");
    if (file_ptr == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    printf("Enter the text to write: ");
    gets(file_buffer);
    fputs(file_buffer, file_ptr);
    fclose(file_ptr);

    printf("File written successfully.\nPress any key to continue...");
    getchar();
}

void append_file(char *file_name)
{
    char file_buffer[100], path[100] = "./files/";
    strcat(path, file_name);
    printf("Appending file %s\n", path);

    FILE *file_ptr = fopen(path, "a");
    if (file_ptr == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    printf("Enter the text to append: ");
    gets(file_buffer);
    fputs(file_buffer, file_ptr);
    fclose(file_ptr);

    printf("File appended successfully.\nPress any key to continue...");
    getchar();
}

void insert_in_file(char *file_name, char *text, unsigned position)
{
    char file_buffer[100], path[100] = "./files/";
    strcat(path, file_name);
    printf("Inserting in file %s in position %d\n", path, position);

    FILE *file_ptr = fopen(path, "r");
    if (file_ptr == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    fgets(file_buffer, 100, file_ptr);
    fclose(file_ptr);
    file_ptr = fopen(strcat("./files/", file_name), "w");
    if (file_ptr == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    for (unsigned i = 0; i < position; i++)
    {
        fputc(file_buffer[i], file_ptr);
    }
    fputs(text, file_ptr);
    for (unsigned i = position; i < strlen(file_buffer); i++)
    {
        fputc(file_buffer[i], file_ptr);
    }
    fclose(file_ptr);

    printf("File inserted successfully.\nPress any key to continue...");
    getchar();
}

void delete_file(char *file_name)
{
    char path[100] = "./files/";
    strcat(path, file_name);
    printf("Deleting file %s\n", path);

    if (remove(path) == 0)
        printf("File deleted successfully\n");
    else
        printf("Error deleting file\n");

    printf("Press any key to continue...");
    getchar();
}

void delete_from_file(char *file_name, unsigned position, unsigned length)
{
    char file_buffer[100], path[100] = "./files/";
    strcat(path, file_name);
    printf("Deleting from file %s from position %d for length %d\n", path, position, length);

    FILE *file_ptr = fopen(path, "r");
    if (file_ptr == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    fgets(file_buffer, 100, file_ptr);
    fclose(file_ptr);
    file_ptr = fopen(strcat("./files/", file_name), "w");
    if (file_ptr == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    for (unsigned i = 0; i < position; i++)
    {
        fputc(file_buffer[i], file_ptr);
    }
    for (unsigned i = position + length; i < strlen(file_buffer); i++)
    {
        fputc(file_buffer[i], file_ptr);
    }
    fclose(file_ptr);

    printf("File deleted successfully.\nPress any key to continue...");
    getchar();
}

void operate_choice(enum choices choice)
{
    unsigned position, length;
    char file_name[100];

    switch (choice)
    {
    case CREATE:
        printf("Enter the name of the file to create: ");
        gets(file_name);
        create_file(file_name);
        break;
    case READ:
        printf("Enter the name of the file to read: ");
        gets(file_name);
        read_file(file_name);
        break;
    case WRITE:
        printf("Enter the name of the file to write: ");
        gets(file_name);
        write_file(file_name);
        break;
    case APPEND:
        printf("Enter the name of the file to append: ");
        gets(file_name);
        append_file(file_name);
        break;
    case INSERT:
        printf("Enter the name of the file to insert: ");
        gets(file_name);
        printf("Enter the position to insert: ");
        scanf("%u", &position);
        insert_in_file(file_name, "Hello World", position);
        break;
    case DELETE:
        printf("Enter the name of the file to delete: ");
        gets(file_name);
        delete_file(file_name);
        break;
    case REMOVE:
        printf("Enter the name of the file to remove: ");
        gets(file_name);
        printf("Enter the position to remove: ");
        scanf("%u", &position);
        printf("Enter the length to remove: ");
        scanf("%u", &length);
        delete_from_file(file_name, position, length);
        break;
    case LIST:
        system("dir ./files");
        break;
    case EXIT:
        printf("Exiting...\n");
        exit(0);
    default:
        printf("Invalid choice\n");
    }
}