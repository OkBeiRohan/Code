#include <stdio.h>
#include <stdlib.h>

struct node_s
{
    int data;
    struct node_s *next;
    struct node_s *prev;
} *head = NULL, *tail = NULL;
typedef struct node_s node;

void create_node(int);
void delete_node(int);
void insert_node(int, int);
void display_list();
void display_list_reverse();
int find_node(int);

int main()
{
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the data for %d nodes: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        create_node(data);
    }

    printf("\nThe linked list is: ");
    display_list();

    printf("\n\nThe linked list in reverse is: ");
    display_list_reverse();

    printf("\n\nEnter the position of the node to search: ");
    scanf("%d", &n);
    printf("Data in position %d is: %d", n, find_node(n));

    printf("\n\nEnter the position of the node to delete: ");
    scanf("%d", &n);
    delete_node(n);
    printf("The linked list after deletion is: ");
    display_list();

    printf("\n\nEnter the position of the node to insert: ");
    scanf("%d", &n);
    printf("Enter the data to insert: ");
    scanf("%d", &data);
    insert_node(n, data);
    printf("The linked list after insertion is: ");
    display_list();

    return 0;
}

void create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

void delete_node(int pos)
{
    node *temp = head;
    if (pos == 1)
    {
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;
        node *temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next->prev = temp;
        free(temp2);
    }
}

void insert_node(int pos, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (pos == 1)
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    else
    {
        node *temp = head;
        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;
        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next = new_node;
        new_node->next->prev = new_node;
    }
}

void display_list()
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;

        if (temp != NULL)
            printf(" <-> ");
    }
}

void display_list_reverse()
{
    node *temp = tail;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->prev;

        if (temp != NULL)
            printf(" <-> ");
    }
}

int find_node(int pos)
{
    node *temp = head;
    for (int i = 1; i < pos; i++)
        temp = temp->next;
    return temp->data;
}