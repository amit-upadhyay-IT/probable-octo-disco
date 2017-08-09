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
   public:
        struct petrolPump *p;
        int front, rear;

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
                petrolPump pp; pp.petrol = -1; pp.distance = -1;
                return pp;
            }
            else
            {
                 front = front + 1;
                 return p[front];
            }
        }

        void print_queue()
        {
            int count = (rear+N-front) % N;
            std::cout<<std::endl<<count<<std::endl;
            std::cout<<"Queue   ";
            for (int i = 1; i <= count; ++i)
            {
                int index = (front+i) % N;
                std::cout<<p[index].distance<<" "<<p[index].petrol<<std::endl;
            }
            std::cout<<std::endl;
        }
};

int check_circular_tour(Queue *q, int cnt)
{
    return 0;
}

/*
 * INCOMPLETE
 * */
int main()
{
    Queue *q = new Queue();
    int t, i = 1, num;
    std::cin>>t;
    int petrol, distance;
    while (t--)
    {
        std::cin>>num;
        int n = num;
        printf("\nEnter petrol and distance\n");
        while (n--)
        {
            std::cin>>petrol>>distance;
            q->p[i].petrol = petrol; q->p[i].distance = distance;
            q->p[i].petrol = q->p[i].petrol - q->p[i].distance;
            q->enqueue(q->p[i]);
            i++;
        }

    }
    q->print_queue();
    return 0;
}
