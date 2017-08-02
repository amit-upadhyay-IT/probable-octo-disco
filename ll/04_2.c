/*
 * hash table approach, iterate over ll and add the address to hash table and then search of the address in hash table.
 * */
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define SIZE 1000000

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

int char_to_int(char *arr)
{
    int len = strlen(arr);
    int i, x = 0;
    for (i = 0; i < len-1; ++i)
    {
        x = x*10 + arr[i]-'0';
    }
    return x;
}

int hash_function(int num)
{
    return num%SIZE;
}

int has_loops(struct node* head, struct node* addresses[])
{
    char add_arr[15];// to store the address of node
    int k = 0;
    struct node* temp = head;
    while (temp)
    {
        snprintf(add_arr, 15, "%d", temp);
        int add_val = char_to_int(add_arr);// address value in integer
        int hash_index = hash_function(add_val); // integer address value is hashed

        if (addresses[hash_index])
            return 1;
        addresses[hash_index] = temp;
        printf ("%d ", hash_index);
        temp = temp->next;
    }
    return 0;
}

int main()
{
    struct node* head;
    int ch;
    struct node* addresses[SIZE] = {'\0'};
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
    int val = has_loops(head, addresses);
    if (val)
        printf("\nThe linked list has loops\n");
    else
        printf("\nNo Loops found in Linked List\n");
    return 0;
}

