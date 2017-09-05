/*
 * rotate elements of array by d
 * approach 1 : left rotate
 * */
#include<stdio.h>
#include<stdlib.h>

void rotateLeft(int *arr, int n, int d)
{
    int temp, i;
    while (d--)
    {
        temp = arr[0];
        for (i = 0; i < n-1; ++i)
        {
            arr[i] = arr[i+1];
        }
        arr[i] = temp;
    }
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

    rotateLeft(arr, n, d);

    printArray(arr, n);
    return 0;
}

// time is O(n)
// space is O(d)
