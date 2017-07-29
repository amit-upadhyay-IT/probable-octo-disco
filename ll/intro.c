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

void insert_at_beginning(struct node* head, int data)
{
    struct node* new_node = get_new_node();
    new_node->data = data;
    new_node->link = head;
    head = new_node;
    printf("\n%x\n", head);
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
    head = (struct node*)malloc(sizeof(struct node));
    head ->data = 4;
    do
    {
        printf("\nEnter your choice : \n1.Insert at beginning\n2.Traverse\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the data\n");
                scanf("%d", &data);
                insert_at_beginning(head, data);
                break;
            case 2:
                traverse_ll(head);
                break;
        }
    }while (ch != 4);
}
