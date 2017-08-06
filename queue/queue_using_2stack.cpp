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

class Queue
{
    public:
        void enqueue(Stack &s, int item)
        {
            s.push(item);
        }

        int dequeue(Stack s1, Stack s2)
        {
            int x = 0;
            if (s2.is_empty())
            {
                if (s1.is_empty())
                {
                    std::cout<<"Queue is empty (Underflow)\n";
                    return x;
                }
                else // s1 has some elements, so we need to pop up those and push to s2
                {
                    while (!s1.is_empty())
                    {
                        int x = s1.Top(); s1.pop();
                        s2.push(x);
                    }
                }
            }
            x = s2.Top();
            s2.pop();
            return x;
        }
};

int main()
{
    Queue q;
    Stack s1, s2;
    /*
    q.enqueue(s1, 10);
    q.enqueue(s1, 20);
    q.enqueue(s1, 30);
    q.enqueue(s1, 40);
    q.enqueue(s1, 50);

    s1.print_stack();

    std::cout<<q.dequeue(s1, s2)<<" ";

    */

    std::cout<<std::endl;
    return 0;
}
