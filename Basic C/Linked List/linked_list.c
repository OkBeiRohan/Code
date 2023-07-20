#include <stdio.h>
#include <stdlib.h>

struct node_s
{
    int data;
    struct node_s *next;
} *head = NULL, *tail = NULL;
typedef struct node_s node;

void create_node(int);
void display_list();

int main()
{
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        create_node(data);
    }

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
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}