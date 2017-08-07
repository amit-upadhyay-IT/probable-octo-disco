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

// joining the end node of ll1 to the head of ll1;
void loop_ll_1(struct node* head)
{
    struct node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = head;
}

struct node* get_intersect_point(struct node* head1, struct node* head2)
{
    int flag = 0;
    struct node* slow = head2, *fast = head2;

    while (slow && fast)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        slow = head2;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
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

    loop_ll_1(head1);

    struct node* var = get_intersect_point(head1, head2);
    if (var)
        printf("\nThey intersect at %d\n", var->data);
    else
        printf("\nThey don't intersect at all\n");

    return 0;
}

// T.C = O(m*n)
// S.C = O(1)
