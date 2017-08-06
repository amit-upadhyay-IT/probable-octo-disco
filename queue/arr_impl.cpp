#include<iostream>

#define N 10

class Queue
{
    private:
        int queue[N];
        int front, rear;
    public:
        Queue()
        {
            front = rear = 0;
        }
        void enqueue(int item)
        {
            rear = (rear + 1) % N;
            // check for overflow condition
            if (front == rear)
            {
                std::cout<<"Queue is full\n";
                if (rear == 0)
                    rear = N - 1;
                else
                    rear = rear - 1;
            }
            else
            {
                queue[rear] = item;
            }
        }

        int dequeue()
        {
            // check for underflow
            if (front == rear)// in this kind of implementation this is the only condition for underflow, because I am not letting rear become equal to front anytime (this is how enqueue() function is written)
            {
                std::cout<<"Queue is empty\n";
                return -1;
            }
            else
            {
                front = (front + 1) % N;
                return queue[front];// it may seem to be different, but its because the queue in this implementation is starting from (front+1)th element
            }
        }

        void print_queue()
        {
            /*
            int k = (front+1) % N;
            while (k <= rear)
            {
                std::cout<<queue[k]<<" ";
                k = (k+1) % N;
            }
            */

            int count = (rear+N-front)%N;
            std::cout<<"Queue       : ";
            for(int i = 1; i <=count; i++)
            {
                int index = (front+i) % N; // Index of element while travesing circularly from front+1
                std::cout<<queue[index]<<" ";
            }
            std::cout<<"\n\n";
        }
};

int main()
{
    Queue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.enqueue(60);
    q1.enqueue(70);

    q1.print_queue();

    std::cout<<q1.dequeue()<<" ";
    std::cout<<q1.dequeue()<<" ";
    std::cout<<q1.dequeue()<<" ";

    std::cout<<std::endl;
    return 0;
}
