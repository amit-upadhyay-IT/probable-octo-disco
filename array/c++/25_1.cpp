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
