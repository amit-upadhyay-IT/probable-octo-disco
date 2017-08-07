/*
 * for each char, if 'c' is operand then print it
 *                else if 'c' is ')' then pop and print elements of stack until '(' is encountered
 *                else, pop and print elements until you get some one with lower precedence or '(' is encountered or stack is empty
 *                      push 'c'
 * */
#include<iostream>
#include<stdlib.h>
#include<cstring>

struct node{
    char data;
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

        void push(char data)
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

        char Top()
        {
            if (!top)
                return 0;
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

int get_precedence(char op)
{
    switch(op)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
        case ')':
            return 3;
    }
}

int main()
{
    Stack s1;
    char arr[100] = "a+b*c";

    for (int i = 0; i < strlen(arr); ++i)
    {
        if (isalpha(arr[i]))
            std::cout<<arr[i];
        else if (arr[i] == ')')
        {
            while (s1.Top() != '(')
            {
                std::cout<<s1.Top();
                s1.pop();
            }
            s1.pop(); // for removing '('
        }
        else // the char is operator
        {
            if (s1.is_empty()==0)
                while (get_precedence(s1.Top()) > get_precedence(arr[i]) && s1.Top() != '(')
                {
                    std::cout<<s1.Top(); s1.pop();
                }
            s1.push(arr[i]);
        }
    }
    while (!s1.is_empty())
    {
        std::cout<<s1.Top();
        s1.pop();
    }
    std::cout<<std::endl;
    return 0;
}
