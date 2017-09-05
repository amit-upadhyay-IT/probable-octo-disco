/*
 * rotate elements of array by d
 * approach 1 : left rotate
 * */
#include<stdio.h>
#include<stdlib.h>

void rotateRight(int *arr, int n, int d)
{
    // copy the last d elements from right to left
    int i, *temp = malloc(sizeof(int)*d);
    for (i = n-d; i < n; ++i)
        temp[i-(n-d)] = arr[i];

    // shifting the elements
    for (i = n-d-1; i >= 0; i--)
        arr[i+d] = arr[i];

    for (i = 0; i < d; ++i)
        arr[i] = temp[i];
}

void rotateLeft(int *arr, int n, int d)
{
    int *temp = malloc(sizeof(int) * d);
    int i;
    for (i = 0; i < d; ++i)
        temp[i] = arr[i];

    // shifting the elements
    for(i = d; i < n; ++i)
        arr[i-d] = arr[i];

    // copying the last d elements from temp
    for (i = 0; i < d; ++i)
        arr[n-d+i] = temp[i];
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
    //scanf("%d", &d);

    //rotateLeft(arr, n, d);
    rotateRight(arr, n, d);

    printArray(arr, n);
    return 0;
}

// Time is n^2
