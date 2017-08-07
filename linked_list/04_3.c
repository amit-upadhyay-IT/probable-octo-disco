/*
 * in this approach i will change the structure of the node, I will add one more property to the structure
 * that is is_visited, as soon as the nodes are being visited I will update the is_visited property
 */
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
    int data;
    int is_visited;
    struct node* next;
};

struct node* insert_at_beginning(struct node* head, int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return head;
}

void print_ll(struct node* head)
{
    struct node* temp = head;
    while (temp)
    {
         printf("%d ", temp->data);
         temp = temp->next;
    }
}

int has_loop(struct node* head)
{
    struct node* temp = head;
    while (temp)
    {
        if (temp->is_visited == 1)
            return 1;
        temp->is_visited = 1;
        temp = temp->next;
    }
    return 0;
}

int main()
{
    struct node* head;
    int ch;
    /*
    scanf("%d", &ch);
    do
    {
        head = insert_at_beginning(head, ch);
        scanf("%d", &ch);
    } while (ch != -1);

    */
    head = insert_at_beginning(head, 5);
    head = insert_at_beginning(head, 10);
    head = insert_at_beginning(head, 15);
    head = insert_at_beginning(head, 20);
    head = insert_at_beginning(head, 25);
    head = insert_at_beginning(head, 30);
    head = insert_at_beginning(head, 35);
    print_ll(head);

    head->next->next->next->next = head->next;
    printf("\n");
    if (has_loop(head))
        printf("\nThe ll has loops\n");
    else
        printf("\nThe ll has no loops\n");
    return 0;
}

