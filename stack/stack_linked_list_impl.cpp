#include<iostream>
#include<stdlib.h>

struct node{
    int data;
    struct node*  next;
};

class Stack
{
    private:
        struct node* top;
    public:
        Stack()
        {
            top = NULL;
        }

        void push(int data)
        {
            //node* new_node = (node*)malloc(sizeof(node));
            node* new_node = new node;
            new_node->next = top;
            new_node->data = data;
            top = new_node;
        }

        void pop()
        {
            if (!top)
                return ;
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
            struct node* temp = top;
            while (temp)
            {
                std::cout<<temp->data<<" ";
                temp = temp->next;
            }
            std::cout<<std::endl;
        }
};

int main()
{
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);

    s1.print_stack();

    s1.pop();
    s1.print_stack();
    //s1.pop();
    //s1.print_stack();
}
