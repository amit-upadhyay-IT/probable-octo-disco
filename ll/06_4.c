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

int get_length(struct node* head)
{
    int l = 0;
    struct node* temp = head;
    while (temp)
    { l++; temp = temp->next; }
    return l;
}

int get_mod(int num)
{
    if (num < 0)
        return num*-1;
    return num;
}

struct node* get_intersect_point(struct node* head1, struct node* head2)
{
    int flag = 0;
    struct node* temp1 = head1, *temp2 = head2;
    struct node* temp;
    int len1 = get_length(head1);
    int len2 = get_length(head2);
    int diff = get_mod(len1-len2);
    int max = len1>len2?len1:len2;
    while (diff)
    {
        if (max == len1)
        {
            flag = 1;
            temp = head1;
        }
        else
        {
            flag = 2;
            temp = head2;
        }
        temp = temp->next;
        diff--;
    }

    if (flag ==1 )
        temp1 = temp;
    else if (flag == 2)
        temp2 = temp;

    while (temp1->next && temp2->next)
    {
         if (temp1 == temp2)
             return temp1;
         temp1 = temp1->next;
         temp2 = temp2->next;
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

    printf("\nBefore linkage\n");

    print_ll(head1);
    print_ll(head2);

    make_linkage(head1, head2);

    printf("\nAfter linkage\n");

    print_ll(head1);
    print_ll(head2);

    struct node* ret_val = get_intersect_point(head1, head2);
    if (ret_val)
        printf ("\nMeeting at %d \n", ret_val->data);
    else
        printf("\nNo intersection\n");
    return 0;
}

// T.C = O(m*n)
// S.C = O(1)
