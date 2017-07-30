//move last node to first
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};

struct node* get_new_node()
{
    return (struct node*)malloc(sizeof(struct node));
}

struct node* insert_at_beginning(struct node* head, int data)
{
    struct node* new_node = get_new_node();
    new_node->data = data;
    new_node->link = head;
    head = new_node;
    //printf("\n%x\n", head);
    return head;
}


void traverse_ll(struct node* head)
{
    struct node* temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
}

void f (struct node* head)
{
    if (head)
    {
         printf("%d ", head->data);
         f(head->link);
    }
}

void g (struct node* head)
{
    if (head)
    {
        g(head->link);
        printf("%d ", head->data);
    }
}

int main()
{
    struct node* head;
    int data;
    printf("\nenter element\n");
    scanf("%d", &data);
    while (data != -1)
    {
        head = insert_at_beginning(head, data);
        scanf("%d", &data);
    }
    traverse_ll(head);
    printf("\n");
    f(head);
    printf("\n");
    g(head);
    printf("\n");
    return 0;
}
