// reverse ll
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

struct node* recursive_reverse(struct node* first)
{
    if (first == NULL)// ll has no nodes
        return first;
    if (first->link == NULL)// ll has only one node
        return first;
    struct node* rest = recursive_reverse(first->link);
    first->link->link = first;
    first->link = NULL;
    return rest;
}

struct node* rec_reverse(struct node* head, struct node* prev, struct node* cur)
{
    if (cur)
    {
        rec_reverse(head, cur, cur->link);
        cur->link = prev;
    }
    else
        head = prev;
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
    printf("\nIterative Reverse\n");
    head = reverse_ll(head);
    traverse_ll(head);
    printf("\nRecursive reverse 1st approach\n");
    head = recursive_reverse(head);
    traverse_ll(head);
    printf("\nRecursive reverse 2nd approach\n");
    head = rec_reverse(head, NULL, head);
    traverse_ll(head);
    printf("\n");
    return 0;
}
