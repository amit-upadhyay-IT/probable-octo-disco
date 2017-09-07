/*
 * find the smallest number that can't be formed with the sum of the number in given array
 * approach 2: sorting approach
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

int getSmallestNum(int *arr, int n)
{
    int smallestNum = 1, i;
    for (i = 0; i < n; ++i)
    {
        if (arr[i] <= smallestNum)
        {
            smallestNum = smallestNum + arr[i];
        }
        else
            break;
    }
    return smallestNum;
}


int main()
{
    int arr[] = {4, 13, 2, 3, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, size-1);

    int smallestNum = getSmallestNum(arr, size);
    printf("\nThe smallest number which is not possible to be formed from the elements of array is %d\n", smallestNum);

    printf("\n");
    return 0;
}

