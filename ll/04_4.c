/*
 * this approach uses two pointers fast and slow pointer, both starts with head and fast pointer moves two nodes ahead whereas the
 * the slow pointer moves only one step ahead, if at any point both of them matches then we say that there is loop.
 */
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* insert_at_end(struct node* head, int data)
{
    struct node* temp = head;
    if (!head)// head will be null first time, so insert here
    {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->next = NULL;
        head = new_node;
        return head;
    }

    while (temp->next)
        temp = temp->next;
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    temp->next = new_node;
    return head;
}

void print_ll(struct node* head)
{
    struct node* temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int has_loops(struct node* head)
{
    struct node* fast = head, *slow = head;
    while (fast)
    {
         slow = slow->next;
         fast = fast->next->next;
         if (slow == fast)
             return 1;
    }
    return 0;
}

void make_linkage(struct node* head)
{
    if (head->next->next->next->next)
        head->next->next->next->next = head->next;
}

int main()
{
    struct node* head;
    int ch;
    printf("\nEnter more than 5 nodes for proper execution of program\n");
    scanf("%d", &ch);
    do
    {
        head = insert_at_end(head, ch);
        scanf("%d", &ch);
    }while (ch != -1);

    printf("\n");
    print_ll(head);
    printf("\n");
    make_linkage(head);
    if (has_loops(head))
        printf("\nLL has loops\n");
    else
        printf("\nLL has no loops\n");
    return 0;
}
