// alternating split of ll in a way that nodes address shouldn't change.
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert_at_end(struct node* head, int data)
{
    if (!head)
    {
        // the first node
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->next = NULL;
        return new_node;// this will be head
    }
    struct node* temp = head;
    while (temp->next)
        temp = temp->next;
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    temp->next = new_node;
    return head;
}

void print_ll(struct node* head)
{
    printf("\n");
    struct node* temp = head;
    while (temp)
    {
         printf("%d ", temp->data);
         temp = temp->next;
    }
    printf("\n");
}

void split_ll(struct node* first_head, struct node* second_head)
{
    struct node* first = first_head;
    struct node* second = second_head;
    while (second->next)
    {
        second = first->next;
        first->next = first->next->next;
        first = second;
    }
}

int main()
{
    struct node* head;
    head = insert_at_end(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 30);
    head = insert_at_end(head, 40);
    head = insert_at_end(head, 50);
    head = insert_at_end(head, 60);
    head = insert_at_end(head, 70);
    head = insert_at_end(head, 80);
    head = insert_at_end(head, 90);

    print_ll (head);

    struct node* second_node = head->next;

    struct node* first_head = head, *second_head = head;

    split_ll(first_head, second_head);

    print_ll(head);
    print_ll(second_node);

    return 0;
}
