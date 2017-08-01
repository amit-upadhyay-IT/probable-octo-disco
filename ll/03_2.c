// find kth node from end
/*
 make two ptrs, fast ptr and slow ptr
 place fast pointer k nodes ahead of slow ptr
 keep slow ptr pointing to head
 increment both pointer one by one
 once fast pointer reaches last node then slow ptr would be pointing to required node
 */
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert_end(struct node* head, int data)
{
    if (head == NULL)// inserting node when there is no node before
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

struct node* get_kth_node_from_end(struct node* head, int k)
{
    struct node* slow_ptr = head, *fast_ptr = head;
    struct node* temp = head;
    while (k > 0)
    {
        temp = temp->next;
        k--;
    }
    fast_ptr = temp;
    while (fast_ptr)
    {
         slow_ptr = slow_ptr->next;
         fast_ptr = fast_ptr->next;
    }
    return slow_ptr;
}

int main()
{
    int ch, k;
    struct node* head;
    scanf("%d", &ch);
    do
    {
         head = insert_end(head, ch);
         scanf("%d", &ch);
    } while (ch != -1);
    printf("\n");
    print_ll(head);
    printf("\nEnter k\n");
    scanf("%d", &k);
    struct node* mid_node = get_kth_node_from_end(head, k);
    printf("\nThe middle node element is %d \n", mid_node->data);
    return 0;
}
// T.C = O(n)
// S.C = O(1)
