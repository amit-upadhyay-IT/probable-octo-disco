/*
 * change a[i] to a[a[i]]
 * approach 1: using extra space
 * */
#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void changeArray(int *arr, int n)
{
    int i;
    int *temp = malloc(sizeof(int)*n);

    for (i = 0; i < n; ++i)
    {
        temp[i] = arr[arr[i]];
    }

    // copying elements of temp in original array
    for (i = 0; i < n; ++i)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    int arr[] = {3, 1, 0, 2, 4};
    int size = sizeof(arr)/sizeof(arr[0]);

    changeArray(arr, size);
    printArray(arr, size);

    printf("\n");
    return 0;
}

// Time is O(n)
// space is O(n)
