#include<iostream>
#include<stdlib.h>

void printSubArray(int *arr, int left, int right)
{
    for (int i = left ;i <= right; ++i)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

void getSubArray(int *arr, int n, int x)
{
    int hash[1000] = {0};

    int sum = arr[0];
    // creating the hash
    for (int i = 1; i < n; ++i)
    {
        hash[sum] = i;
        sum = sum + arr[i];
    }
    int flag = 0;

    sum = 0;
    // again iterating over the array
    for (int i = 0; i < n; ++i)
    {
        sum = sum + arr[i];
        if ((sum - x) >= 0 &&hash[sum - x])
        {
            flag = 1;
            printSubArray(arr, hash[sum-x], i);
        }
        else
        {
        }
    }
    if (!flag)
    {
        std::cout<<"No such subarray\n";
    }

}

int main()
{
    int arr[] = {8, 5, -2, 3, 4, -5, 7};

    int n = 7;
    int x = 10;

    getSubArray(arr, n, x);
    return 0;
}
