#include<stdio.h>
#include<stdlib.h>

int getMaxInLeft(int *arr, int index)
{
    int max = arr[index];
    int i;
    for (i = index-1; i >=0; --i)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int getMaxInRight(int *arr, int index, int n)
{
    int i, max = arr[index];
    for (i = index+1; i < n; ++i)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int getTrappedAmt(int *arr, int n)
{
    int i, sum = 0;
    for (i = 0; i < n; ++i)
    {
        sum = sum + min(getMaxInLeft(arr, i), getMaxInRight(arr, i, n)) - arr[i];
    }
    return sum;
}

int main()
{
    int arr[] = {1, 0, 2, 0, 1, 0, 3, 1, 0, 2};
    int size = sizeof(arr)/sizeof(arr[0]);

    int trappedWater = getTrappedAmt(arr, size);

    printf("The water trapped is %d", trappedWater);

    printf("\n");
    return 0;
}
