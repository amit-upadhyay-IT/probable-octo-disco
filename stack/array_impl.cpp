#include<stdio.h>
#include<iostream>
#include<stdlib.h>

#define MAX_SIZE 101

class Stack
{
    private:
        int arr[MAX_SIZE];
        int top;
    public:
        Stack()
        {
            top = -1;
        }
        void push(int data)
        {
            top == (MAX_SIZE-1) ? printf("\nOverflow"):(arr[++top] = data);
        }
        void pop()
        {
            top == -1?printf("\nUnderflow"):top--;
        }

        int Top()
        {
            return (top == -1)? 0:(arr[top]);

        }

        int is_empty()
        {
            return top == -1?1:0;
        }

        void print_stack()
        {
            for (int i = 0; i <= top; ++i)
                printf("%d ", arr[i]);
            printf("\n");
        }


};

int main()
{
     Stack s1, s2;
     s1.push(10);
     s1.push(11);
     s1.push(12);
     s1.push(13);
     s1.pop();

     s1.print_stack();

     s2.pop();
     s2.print_stack();
}
