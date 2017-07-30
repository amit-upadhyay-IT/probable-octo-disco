// iterative approach to reverse ll
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

struct node* reverse_ll(struct node* head)
{
    struct node* prev = NULL, *next_node = NULL;
    while (head)
    {
        next_node = head->link;
        head->link = prev;
        prev = head;
        head = next_node;
    }
    return prev;
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
    head = reverse_ll(head);
    printf("\n");
    traverse_ll(head);
    printf("\n");
    return 0;
}
