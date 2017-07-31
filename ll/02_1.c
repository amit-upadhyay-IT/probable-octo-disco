#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert_end(struct node* head, int data)
{
    if (head == NULL)
    {
        struct node* t = (struct node*)malloc(sizeof(struct node));
        t->data = data;
        t->next = NULL;
        head = t;
        return head;
    }
    struct node* temp;
    temp = head;
    while (temp->next)
         temp = temp->next;
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->next = NULL;
    new_node->data = data;
    temp->next = new_node;
    return head;
}

void print_ll(struct node* head)
{
    if (head)
    {
        printf("%d ", head->data);
        print_ll(head->next);
    }
}

int main()
{
    int ch;
    struct node* head;// = (struct node*)malloc(sizeof(struct node));
    do
    {
         scanf("%d", &ch);
         head = insert_end(head, ch);
    } while (ch != -1);
    printf("\n");
    print_ll(head);
    printf("\n");

    return 0;
}
