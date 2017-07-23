#include<stdio.h>
#include<stdlib.h>

void swap(int *arr, int a, int b)
{
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

void swap2(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int n)
{
    int start = 0, end = n-1;
    int pivot = arr[end];
    int partitionIndex = start;
    int i;
    for (i = start; i < end; ++i)
    {
        if (!pivot && arr[i] <= pivot)
        {
            swap(arr, i, partitionIndex);
            //swap2(&arr[i], &arr[partitionIndex]);
            partitionIndex++;
        }
        else if (pivot && arr[i] < pivot)// check if last element if one then we just need to compare if arr[i] < pivot
        {
            swap(arr, i, partitionIndex);
            partitionIndex++;
        }
    }
    swap(arr, partitionIndex, end);
    //swap2(&arr[partitionIndex], &arr[end]);
    return partitionIndex;
}

int main()
{
    int i, *arr, n;
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    int zero_count = partition(arr, n)+1;
    printf("\n");
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    return 0;
}
