/*
 *find intersect point of two LL
 * using brute force approach
 */
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void insert_at_end(struct node** head, int data)
{
    if (!*head)
    {
        // inserting at first position
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->next = NULL;
        *head = new_node;
    }
    else
    {
        struct node* temp = *head;
        while (temp->next)
            temp = temp->next;
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->next = NULL;
        temp->next = new_node;
    }
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

struct node* get_intersect_point(struct node* head1, struct node* head2)
{
    struct node* temp1 = head1, *temp2;
    while (temp1->next)
    {
        temp2 = head2;
        while (temp2->next)
        {
            if (temp1 == temp2)
                return temp1;
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return NULL;
}

void make_linkage(struct node* head1, struct node* head2)
{
    head1->next = head2->next->next;
}

int main()
{
    struct node* head1 = NULL, *head2 = NULL;
    insert_at_end(&head1, 50);
    insert_at_end(&head2, 25);
    insert_at_end(&head1, 40);
    insert_at_end(&head2, 20);
    insert_at_end(&head1, 30);
    insert_at_end(&head2, 15);
    insert_at_end(&head1, 20);
    insert_at_end(&head2, 10);
    insert_at_end(&head1, 10);
    insert_at_end(&head2, 5);
    insert_at_end(&head1, 1);
    insert_at_end(&head2, 2);

    print_ll(head1);
    print_ll(head2);

    make_linkage(head1, head2);

    struct node* ret_val = get_intersect_point(head1, head2);
    if (ret_val)
        printf("\nThe two linked list intersect at %d node\n", ret_val->data);
    else
        printf("\nThere is no intersection between two linked list\n");

    return 0;
}
