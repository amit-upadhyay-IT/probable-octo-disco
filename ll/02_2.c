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

int hash_table_approach(struct node* head, struct node* addresses[])
{
    struct node* temp = head;
    int k = 0;
    while (temp->next)
    {
         addresses[k++] = temp;
         temp = temp->next;
    }
    return k; // returning the count of node in linked list;
}

int main()
{
    int ch;
    struct node* head;
    struct node* addresses[100];
    scanf("%d", &ch);
    do
    {
         head = insert_end(head, ch);
         scanf("%d", &ch);
    } while (ch != -1);
    printf("\n");
    print_ll(head);
    int cnt = hash_table_approach(head, addresses);
    printf("\nCount of nodes is : %d \n", cnt);
    struct node* mid_ptr = addresses[cnt/2];
    printf("\nThe middle node is %d\n", mid_ptr->data);
    return 0;
}
// S.C = O(n)
// T.C = O(N)
