#include<stdio.h>
#include<iostream>
#include<queue>

// takes O(n) time
void push(std::queue<int> &q1, std::queue<int> &q2, int item)
{
    // insert in any of the empty queue
    if (q1.empty())
    {
        q1.push(item);
        if (q2.empty())
        {
            // do nothing
        }
        else
        {
            // dequeue elements from q2 and enqueue them in q1
            while (!q2.empty())
            {
                int _val = q2.front();
                q2.pop();
                q1.push(_val);
            }
        }
    }
    else if (q2.empty())
    {
        // q1 is not empty and q2 is empty, so insert into q2
        q2.push(item);
        while (!q1.empty())
        {
            int _val = q1.front();
            q1.pop();
            q2.push(_val);
        }
    }
}

// takes O(1) time
int pop(std::queue<int> &q1, std::queue<int> &q2)
{
    if (!q1.empty())
    {
        int _val = q1.front();
        q1.pop();
        return _val;
    }
    else
    {
        // q2 is not empty
        int _val = q2.front();
        q2.pop();
        return _val;
    }
}

void print_queue(std::queue<int> q)
{
    // we need to print q
    while (!q.empty())
    {
        std::cout<<q.front()<<" ";
        q.pop();
    }
    printf("\n");
}

int main()
{
    std::queue<int> q1, q2;

    push(q1, q2, 5);
    push(q1, q2, 10);
    push(q1, q2, 15);
    push(q1, q2, 20);
    push(q1, q2, 25);

    print_queue(q1.empty()?q2:q1);

    std::cout<<std::endl<<pop(q1, q2)<<std::endl;

    return 0;
}
