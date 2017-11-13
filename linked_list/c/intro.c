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

struct node* insert_at_end(struct node* head, int data)
{
    if (!head)// when no node are in ll
    {
         struct node* t = (struct node*)malloc(sizeof(struct node));
         t->data= data;
         t->link = NULL;
         head = t;
         return head;
    }
    struct node* temp;
    temp = head;
    while (temp->link)
        temp = temp->link;
    struct node* new_node = get_new_node();
    temp->link = new_node;
    new_node->data = data;
    new_node->link = NULL;
    return head;
}

struct node* insert_in_between(struct node* head, int data, int value)
{
    struct node* temp = head;
    while (temp->data != value)
        temp = temp->link;
    struct node* new_node = get_new_node();
    new_node->link = temp->link;
    temp->link = new_node;
    new_node->data = data;
    return head;
}

struct node* delete_from_beginning(struct node* head)
{
    if (head == NULL)// the linked list is empty and it has nothing to delete
        return head;
    /*
    else if (head ->link == NULL)// ll has one node which needs to be deleted
    {
        free(head);
        head = NULL;
        return head;
    }
    */
    else
    {
        struct node* temp = head;
        head = head->link;
        free(temp);
        return head;
    }
}

struct node* delete_from_end(struct node* head)
{
    if (head == NULL)
        return NULL;
    else if(head -> link == NULL)// there is only one element in ll
    {
        free(head);
        return NULL;
    }
    else
    {
        struct node* temp = head;
        while (temp->link->link != NULL)
            temp = temp->link;
        free(temp->link);
        temp->link = NULL;
        return head;
    }
}

struct node* delete_from_middle(struct node* head, int x)
{
    if (head == NULL)
        return NULL;
    else if (head->link == NULL && head->data != x)// checks if ll has only one element and that is not the element to be deleted
    {
        printf("\n There is no such node\n");
        return head;
    }
    else if (head->data == x)// to delete the first node of ll
    {
        struct node* temp = head;
        head = head->link;
        free(temp);
        return head;
    }
    else
    {
        int flag = 0;
        struct node* temp = head;
        while (temp->link->data != x)
        {
            if (temp->link->link == NULL)// traversing of ll is over and yet we didn't found x
            {
                flag = 1;
                break;
            }
            temp = temp->link;
        }
        if (flag)
        {
            printf("\n there is no such element \n");
            return head;
        }
        struct node* t1 = temp->link;
        temp->link = temp->link->link;
        free(t1);
        return head;
    }
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
    int i, value;
    struct node* head;
    int ch, data, x;
    do
    {
        printf("\nEnter your choice : \n1.Insert at beginning\n2.Insert at end\n3.Insert in between\n4.Traverse\n5.Delete from beginning\n6.Delete from end\n7.Delete from middle\n8.Exit\n");
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
                head = insert_at_end(head, data);
                break;
            case 3:
                printf("\nEnter the data\n");
                scanf("%d", &data);
                printf("\nEnter value after which you want to insert\n");
                scanf("%d", &value);
                head = insert_in_between(head, data, value);
                break;
            case 4:
                traverse_ll(head);
                break;
            case 5:
                head = delete_from_beginning(head);
                break;
            case 6:
                head = delete_from_end(head);
                break;
            case 7:
                printf("\nEnter value you want to delete\n");
                scanf("%d", &x);
                head = delete_from_middle(head, x);
                break;
        }
    }while (ch != 8);
}
