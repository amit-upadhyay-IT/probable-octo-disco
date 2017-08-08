#include<stdio.h>
#include<stdlib.h>
#include<iostream>

#define N 100

struct petrolPump
{
    int petrol;
    int distance;
};

class Queue
{
    private:
        struct petrolPump *p;
        int front, rear;

    public:
        Queue()
        {
            front = rear = 0;
            p = (struct petrolPump*)malloc(100 * sizeof(struct petrolPump));
        }

        void enqueue(struct petrolPump item)
        {
            // check for overflow
            rear = (rear + 1) % N;
            if (front == rear)
            {
                std::cout<<"Queue is full\n";
                if (front = 0)// rear == 0
                    rear = N - 1;
                else
                    rear = rear - 1;
            }
            else
                p[rear] = item;
        }

        struct petrolPump dequeue()
        {
            // check for underflow
            if (front == rear)
            {
                std::cout<<"\n Queue is empty\n";
                return NULL;
            }
            else
            {
                 front = front + 1;
                 return p[front];
            }
        }
};
