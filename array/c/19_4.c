/*
 * rotate elements of array by d
 * approach 1 : left rotate
 * */
#include<stdio.h>
#include<stdlib.h>

void swap(int *arr, int a, int b)
{
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

void reverseArray(int *arr, int firstPos, int lastPos)
{
    int i, j;
    for (i = firstPos, j = lastPos-1; i < (firstPos + lastPos)/2; ++i, --j)
    {
        swap(arr, i, j);
    }
}

void rotateLeft(int *arr, int n, int d)
{
    // first reverse 0 to d
    reverseArray(arr, 0, d);

    // reverse d to n
    reverseArray(arr, d, n);

    // reverse whole array
    reverseArray(arr, 0, n);
}

void printArray(int *arr, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    int d = 2;

    rotateLeft(arr, n, d);

    printArray(arr, n);
    return 0;
}

// time is O(n*d)
// space is O(1)
