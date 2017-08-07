// find kth node from end
/*
 * use hash table and store addresses of node there, access (cnt-k)th element in hashtable to get addresses
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

int print_ll(struct node* head)
{
    struct node* temp = head;
    int k = 0;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        k++;
    }
    return k;
}

void make_hash_table(struct node* head, struct node* addresses[])
{
    struct node* temp = head;
    int k = 0;
    while (temp->next)
    {
        addresses[k++] = temp;
        temp = temp->next;
    }
}

struct node* get_kth_node_from_end(struct node* head, int k, struct node* addresses[], int cnt)
{
    return addresses[cnt-k];
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
    int cnt = print_ll(head);
    printf("\nCnt of nodes = %d \n", cnt);
    printf("\nEnter k\n");
    scanf("%d", &k);
    make_hash_table(head, addresses);
    struct node* mid_node = get_kth_node_from_end(head, k, addresses, cnt);
    printf("\nThe middle node element is %d \n", mid_node->data);
    return 0;
}
// T.C = O(n)
// S.C = O(n)
