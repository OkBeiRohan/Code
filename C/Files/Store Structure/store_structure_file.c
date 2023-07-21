/**
 * Store content in structure in file
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define file_name "structure_file.txt"

struct student
{
    int roll_no;
    int marks;
    char name[100];
};

int main()
{
    struct student student1, student2;
    printf("Enter name: ");
    gets(student1.name);
    printf("Enter roll no: ");
    scanf("%d", &student1.roll_no);
    printf("Enter marks: ");
    scanf("%d", &student1.marks);
    FILE *file_ptr = fopen(file_name, "w");
    if (file_ptr == NULL)
    {
        printf("Error opening file\n");
        exit(0);
    }
    fwrite(&student1, sizeof(student1), 1, file_ptr);
    fclose(file_ptr);
    file_ptr = fopen(file_name, "r");
    if (file_ptr == NULL)
    {
        printf("Error opening file\n");
        exit(0);
    }
    fread(&student2, sizeof(student2), 1, file_ptr);
    printf("Name: %s\n", student2.name);
    printf("Roll No: %d\n", student2.roll_no);
    printf("Marks: %d\n", student2.marks);
    fclose(file_ptr);
    return 0;
}