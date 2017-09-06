/*
 * trapping water problem
 * approach 2
 * */
#include<stdio.h>
#include<stdlib.h>

int* constructLeftArray(int *arr, int n)
{
    int *left = malloc(sizeof(int)*n);// allocating from heap because I need to return it, so the memory elements would not get erased
    int max = arr[0];
    left[0] = arr[0];// copying the first element because that would be the max as it doesn't have any elements in left
    int i;
    for (i = 1; i < n; ++i)
    {
        if (arr[i] > max)
            max = arr[i];
        left[i] = max;
    }
    return left;
}

int *constructRightArray(int *arr, int n)
{
    int *right = malloc(sizeof(int)*n);
    int max = arr[n-1];// declaring n-1 the element at max from right as it doesn't have any element in the right
    right[n-1] = arr[n-1];
    int i;
    for (i = n-2; i >= 0; --i)
    {
        if (max < arr[i])
            max = arr[i];
        right[i] = max;
    }
    return right;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int getTrappedAmt(int *arr, int *left, int *right, int n)
{
    int i, sum = 0;
    for (i = 0; i < n; ++i)
    {
        sum = sum + min(left[i], right[i]) - arr[i];
    }
    return sum;
}

int main()
{
    int arr[] = {1, 0, 2, 0, 1, 0, 3, 1, 0, 2};
    int size = sizeof(arr)/sizeof(arr[0]);

    int *left = constructLeftArray(arr, size);
    int *right = constructRightArray(arr, size);

    int trappedWater = getTrappedAmt(arr, left, right, size);

    printf("The water trapped is %d", trappedWater);

    printf("\n");
    return 0;
}

// Time is O(n)
// space is O(n)
