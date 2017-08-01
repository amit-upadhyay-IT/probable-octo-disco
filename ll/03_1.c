// find kth node from end
/*
 *get count of nodes,
 find required node (count-k)
 go to required node and return address
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
    struct node* temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++; temp = temp->next;
    }
    temp = head;
    int req = cnt-k;
    while (req > 0)
    {
         temp = temp->next;
         req--;
    }
    return temp;
}

int main()
{
    int ch, k;
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
    printf("\nEnter k\n");
    scanf("%d", &k);
    struct node* mid_node = get_kth_node_from_end(head, k);
    printf("\nThe middle node element is %d \n", mid_node->data);
    return 0;
}
// T.C = O(n)
// S.C = O(1)
