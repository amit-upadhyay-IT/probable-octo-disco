/*
 * find the smallest number that can't be formed with the sum of the number in given array
 * approach 1: NAIVE APPROACH, find the possible sums in 2^n time
 * */
#include<stdio.h>
#include<stdlib.h>

int minSum(int *arr, int n, int k)
{
    int i, j;
    int sum = 0;
    for (i = 0; i < (1<<n); ++i)
    {
        for (j = i; j < n; ++j)
        {
            if ((1 & (1 << j)) > 0)
                sum = sum + arr[j];
            if (sum == k)
                return 1;
        }
    }
    return 0;
}

int main()
{
    int arr[] = {4, 13, 2, 3, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    int i;
    for (i = 1; 1; ++i)
    {
        if (!minSum(arr, size, i))
        {
            printf("\n Min sum = %d", i);
            break;
        }
        if (i > 10000000)
        {
            printf("\nSeems too big");
            break;
        }
    }

    printf("\n");
    return 0;
}

