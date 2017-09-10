#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<stack>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        std::cout<<arr[i]<<" ";
    std::cout<<std::endl;
}

int * constructArray(std::stack<int> s0, std::stack<int> s1, std::stack<int> s2, int n)
{
    int *newArr = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; ++i)
    {
        while (!s0.empty())
        {
            newArr[i] = s0.top();
            s0.pop();
        }
        while (!s1.empty())
        {
            newArr[i] = s1.top();
            s1.pop();
        }
        while (!s2.empty())
        {
            newArr[i] = s2.top();
            s2.pop();
        }
    }
}

int * removeRequiredElement(int *arr, int n, std::stack<int> s0, std::stack<int> s1, std::stack<int> s2)
{
    int size = n;
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum = sum + arr[i];

    if (sum % 3 == 0)
        return arr;

    else if (sum % 3 == 1)
    {
        if (!s1.empty())
        {
            s1.pop();
            size--;
        }
        else if (!s2.empty())
        {
            // we need to pop two elements whose rem is 2
            s2.pop();
            size--;
            if (!s2.empty())
            {
                s2.pop();
                size--;
            }
            else
                return NULL;
        }
        else
            return NULL;
    }
    else // rem is 2
    {
        if (!s2.empty())
        {
            s2.pop();
            size--;
        }
        else if (!s1.empty())
        {
            // pop two elements whose rem is 1
            s1.pop();
            size--;
            if (!s1.empty())
            {
                s1.pop();
                size--;
            }
            else
                return NULL;
        }
        else
            return NULL;
    }
    return constructArray(s0, s1, s2, size);
}

int * getLargestMultiple(int *arr, int n)
{
    // sorting the array in descending order
    std::sort(arr, arr+n, std::greater<int>());
    std::stack<int> s0, s1, s2;

    // pushing the elements in respective stacks
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] % 3 == 0)
            s0.push(arr[i]);
        else if (arr[i] % 3 == 1)
            s1.push(arr[i]);
        else
            s2.push(arr[i]);
    }


    return NULL;
}

int main()
{
    int n;
    int arr[] = {4, 1, 7, 3, 8, 8, 3, 3};
    n = sizeof(arr)/sizeof(arr[0]);
    getLargestMultiple(arr, n);
    return 0;
}
