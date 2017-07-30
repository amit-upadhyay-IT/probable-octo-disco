#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};

struct node* get_new_node()
{
    return (struct node*)malloc(sizeof(struct node));
}

struct node* insert_at_beginning(struct node* head, int data)
{
    struct node* new_node = get_new_node();
    new_node->data = data;
    new_node->link = head;
    head = new_node;
    //printf("\n%x\n", head);
    return head;
}

void insert_at_end(struct node* head, int data)
{
    struct node* temp;
    temp = head;
    while (temp->link)
        temp = temp->link;
    struct node* new_node = get_new_node();
    temp->link = new_node;
    new_node->data = data;
    new_node->link = NULL;
}

void traverse_ll(struct node* head)
{
    struct node* temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
}

int main()
{
    int i;
    struct node* head;
    int ch, data;
    do
    {
        printf("\nEnter your choice : \n1.Insert at beginning\n2.Insert at end\n3.Traverse\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the data\n");
                scanf("%d", &data);
                head = insert_at_beginning(head, data);
                break;
            case 2:
                printf("\nEnter the data\n");
                scanf("%d", &data);
                insert_at_end(head, data);
                break;
            case 3:
                traverse_ll(head);
                break;
        }
    }while (ch != 4);
}
