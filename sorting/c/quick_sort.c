#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void printArray(int *arr, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int getPartiotionIndex(int *arr, int firstIndex, int lastIndex)
{
    int i;
    int pivot = arr[lastIndex];// initializing the pivot element with end element in the array
    int partitionIndex = firstIndex;
    for (i = firstIndex; i < lastIndex; ++i)
    {
        if (arr[i] <= pivot)// if the element at beginning seems to be smaller than pivot then we swap elements at i and partitionIndex.
            //but why? because i is always ahead or equal to partitionIndex and we want no smaller elements than pivot should be after partitionIndex thus we swap these
        {
            swap(arr, i, partitionIndex);
            partitionIndex++;
        }
    }
    swap(arr, lastIndex, partitionIndex);// in the end we just put the pivot in its right position(which is partitionIndex).
    return partitionIndex;
}

int randomizedPartition(int *arr, int firstIndex, int lastIndex)
{
    srand(time(NULL));
    int pivotIndex = rand() % (lastIndex-firstIndex+1);
    swap(arr, pivotIndex, lastIndex);
    return getPartiotionIndex(arr, firstIndex, lastIndex);
}

void quickSort(int *arr, int firstIndex, int lastIndex)
{
    if (firstIndex < lastIndex)
    {
        int partitionIndex = getPartiotionIndex(arr, firstIndex, lastIndex);
        quickSort(arr, firstIndex, partitionIndex-1);
        quickSort(arr, partitionIndex+1, lastIndex);
    }
}

int main()
{
    int n, i, *arr;
    printf("Enter n\n");
    scanf("%d", &n);
    arr = malloc(sizeof(int) * n);
    printf("Enter elements\n");
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    quickSort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}
// T.C = O(n log n) not inplace
