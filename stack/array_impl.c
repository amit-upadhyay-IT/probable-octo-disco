#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

void push(int data)
{
    top == (MAX_SIZE-1)? printf("\nOverflow"):(A[++top] = data);
}

void pop()
{
    top == -1?printf("\nUnderflow"):top--;
}

int Top()
{
    return top == -1?0:A[top];
}

int is_empty()
{
    return top == -1?1:0;
}

void print()
{
    int i;
    for (i = 0; i <= top; ++i)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    push(10); print();
    push(20); print();
    push(30); print();
    pop();    print();
    push(40); print();
    push(50); print();
    return 0;
}
