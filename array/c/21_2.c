/*
 * number of possible triangles
 * approach 2
 * */
#include<stdio.h>
#include<stdlib.h>

void swap(int *arr, int a, int b)
{
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

int partition(int *arr, int first, int last)
{
    int pivot = arr[last];
    int pIndex = first;// partitioning index
    int i;
    for (i = first; i < last; ++i)
    {
        if (arr[i] < pivot)
        {
            swap(arr, i, pIndex);
            pIndex++;
        }
    }
    swap(arr, pIndex, last);
    return pIndex;
}

void quickSort(int *arr, int first, int last)
{
    if (first < last)
    {
        int pIndex = partition(arr, first, last);
        quickSort(arr, first, pIndex-1);
        quickSort(arr, pIndex+1, last);
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
    int arr[] = {6, 7, 8, 10, 12, 14, 50};
    int size = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, size-1);

    printArray(arr, size);

    printf("\n");
    return 0;
}
