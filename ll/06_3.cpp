/*
 *find intersect point of two LL
 */
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<iostream>

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

struct node* compare_stacks(std::stack<struct node*> s1, std::stack<struct node*> s2)
{
    int size1 = s1.size(), size2 = s2.size();
    while (size1 && size2)
    {
        if (s1.top() != s2.top())
        {
             return s1.top();
        }
        s1.pop(); s2.pop();
        size1--; size2--;
    }
    return 0;
}

void get_intersect_point(struct node* head1, struct node* head2)
{
    std::stack<struct node*> s1, s2;
    while (head1)
    {
        s1.push(head1);
        head1 = head1->next;
    }
    while (head2)
    {
         s2.push(head2);
         head2 = head2->next;
    }

    struct node* val = compare_stacks(s1, s2);
    if (val)
        printf("\nThey are meeting at %d\n", val->next->data);
    else
        printf("\nThe two linked list are not meeting\n");
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

    get_intersect_point(head1, head2);

    return 0;
}
