#include<stdio.h>
#include<stdlib.h>

void swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void insertionSort(int *arr, int n)
{
    int i, j;
    for (i = 1; i < n; ++i)
    {
        int key = arr[i];
        j = i-1;// j is pointing to right most part of the sorted array, so that we can start comparing from there
        while (j >= 0 && key < arr[j])// check if current element pointed by i is smaller or not, if smaller then only we need to shift elements from sorted part of array
        {
            arr[j+1] = arr[j];// shifting elements
            j--;
        }
        arr[j+1] = key;// at the end which elements gets shifted then we need to place the element pointed by ith index at its appropriate position
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
    int n, i, *arr;
    printf("Enter n\n");
    scanf("%d", &n);
    arr = malloc(sizeof(int) * n);
    printf("Enter elements\n");
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}
