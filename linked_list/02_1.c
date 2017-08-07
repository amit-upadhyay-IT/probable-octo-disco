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

int nodes_in_ll(struct node* head)
{
    int cnt = 0;
    struct node* temp = head;
    if (!head)
        return 0;
    else if (!head->next)
        return 1;
    while (temp->next)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

void print_ll(struct node* head)
{
    if (head)
    {
        printf("%d ", head->data);
        print_ll(head->next);
    }
}

struct node* get_mid_node(struct node* head, int mid)
{
    if (head == NULL)
        return NULL;
    struct node* temp = head;

    while (mid > 0)
    {
         mid--;
         temp = temp->next;
    }
    return temp;
}


int main()
{
    int ch;
    struct node* head;
    scanf("%d", &ch);
    do
    {
         head = insert_end(head, ch);
         scanf("%d", &ch);
    } while (ch != -1);
    printf("\n");
    print_ll(head);
    printf("\n");

    int cnt = nodes_in_ll(head);
    printf("\n Number of  nodes : %d \n", cnt+1);

    struct node* mid_node = get_mid_node(head, cnt/2);
    printf("\n The moid node is %d \n", mid_node->data);
    return 0;
}
