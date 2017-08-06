#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* top;

void push(int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = top;
    top = new_node;
}

void pop()
{
    struct node* temp = top;
    top = top->next;
    free(temp);
}

int is_empty()
{
    return top == NULL;
}

int Top()
{
    return top->data;
}

void print_stack()
{
    if (!top)
        return;
    struct node* temp = top;
    while(top)
    {
        printf("%d ",top->data);
        top = top->next;
    }
}

int main()
{
    top = NULL;
    push(5);
    push(10);
    push(15);
    push(20);
    push(25);
    push(30);
    pop();

    print_stack();
    return 0;
}
