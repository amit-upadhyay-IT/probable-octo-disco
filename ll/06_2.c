/*
 *find intersect point of two LL
 * using brute force approach
 * INCOMPLETE
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 1000000

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

int hash_function(int val)
{
    return val%SIZE;
}

struct chaining_node
{
    struct chaining_node* details;
    struct chaining_node* next;
};

int str_to_int(char * add)
{
    int len = strlen(add), i, val = 0;
    for (i = 0; i < len-1; ++i)
        val = val*10 +(add[i] - '0');
    return val;
}

int search_in_chained_hash(struct node* addresses[], int hash_index, struct node* actual_address)
{
    struct node* tt = addresses[hash_index];
    if (tt->data == actual_address)
        return 1;
    else
    {
        char ch_add[20];
        struct node* temp = addresses[hash_index];
        while (temp)
        {
            snprintf(ch_add, 20, "%d", temp);
            int int_add = str_to_int(ch_add);
            if (int_add == hash_index)
                return 1;
            temp = temp->next;
        }
    }
    return 0;
}

void _store_address(struct node* head, struct node* addresses[])
{
    char ch_add[20];
    struct node* temp = head;
    while (temp)
    {
        snprintf(ch_add, 20, "%d", temp);
        int int_add = str_to_int(ch_add);
        int hash_index = hash_function(int_add);
        if (search_in_chained_hash(addresses, hash_index, temp))

        temp = temp->next;
    }

}

struct node* get_intersect_point(struct node* head1, struct node* head2)
{
}

void make_linkage(struct node* head1, struct node* head2)
{
    head1->next = head2->next->next;
}

int main()
{
    struct node* addresses[SIZE] = {'\0'};

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

    _store_address(head1, addresses);

    printf("\n");

    return 0;
}
