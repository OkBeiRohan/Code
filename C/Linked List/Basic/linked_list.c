#include <stdio.h>
#include <stdlib.h>

struct node_s
{
    int data;
    struct node_s *next;
} *head = NULL, *tail = NULL;
typedef struct node_s node;

void create_node(int);
void delete_node(int);
void display_list();
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

    printf("\n\nEnter the position of the node to search: ");
    scanf("%d", &n);
    printf("Data in position %d is: %d", n, find_node(n));

    printf("\n\nEnter the position of the node to delete: ");
    scanf("%d", &n);
    delete_node(n);
    printf("The linked list after deletion is: ");
    display_list();

    return 0;
}

void create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
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
            printf(" -> ");
    }
}

int find_node(int n)
{
    node *temp = head;
    for (int i = 1; i < n; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

void delete_node(int n)
{
    node *temp = head;
    for (int i = 1; i < n - 1; i++)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
}