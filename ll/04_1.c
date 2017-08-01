#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert_at_beginning(struct node* head, int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
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
    int nodes_cnt = 10;// contains the number of nodes in ll
    int iteration_cnt = 0;
    struct node* temp;
    for (temp = head; temp->next; temp = temp->next)
    {
        struct node* t2 = temp->next;
        while (t2->next)
        {
            if (temp == t2)
            {
                 return 1;
            }
            if (iteration_cnt > nodes_cnt*nodes_cnt)
                return 1;
            iteration_cnt++;
            t2 = t2->next;
        }
    }
    return 0;
}

int main()
{
    struct node* head;
    int ch;
    /*
    scanf("%d", &ch);
    do
    {
        head = insert_at_beginning(head, ch);
        scanf("%d", &ch);
    } while (ch != -1);

    */
    head = insert_at_beginning(head, 5);
    head = insert_at_beginning(head, 10);
    head = insert_at_beginning(head, 15);
    head = insert_at_beginning(head, 20);
    head = insert_at_beginning(head, 25);
    head = insert_at_beginning(head, 30);
    head = insert_at_beginning(head, 35);
    print_ll(head);

    head->next->next->next->next = head->next;
    printf("\n");
    int val = has_loops(head);
    printf("%d\n", val);
    return 0;
}
