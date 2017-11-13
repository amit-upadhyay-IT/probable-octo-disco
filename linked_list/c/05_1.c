/*
 * to find the node where loop is being formed
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

struct node* has_loops(struct node* head)
{
    int loop_found = 0;
    struct node* fast = head, *slow = head;
    while (fast)
    {
         slow = slow->next;
         fast = fast->next->next;
         if (slow == fast)
         {
             loop_found = 1;
             break;
         }
    }
    if (loop_found)
    {
        for (slow = head; slow != fast; fast = fast->next, slow = slow->next);
        return slow;
    }
    return NULL;
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
    struct node* ret_val = has_loops(head);
    if (ret_val)
        printf("\nLL has loop at %d \n", ret_val->data);
    else
        printf("\nLL has no loops\n");
    return 0;
}
