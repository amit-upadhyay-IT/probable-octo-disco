#include<stdio.h>
#include<stdlib.h>

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

void mergeArrays(int *arr, int *leftArray, int *rightArray, int nL, int nR)
{
    int i, j, k;
    i = j = k = 0;// i <- arr, j <- leftArray and k <- rightArray
    while (j < nL && k < nR)
    {
        if (leftArray[j] < rightArray[k])
        {
            arr[i] = leftArray[j];
            j++;
        }
        else
        {
            arr[i] = rightArray[k];
            k++;
        }
        i++;
    }
    while (j < nL)
    {
        arr[i] = leftArray[j];
        j++; i++;
    }
    while (k < nR)
    {
        arr[i] = rightArray[k];
        i++; k++;
    }
}

void mergeSort(int *arr, int n)
{
    if (n < 2)// base condition when array has less than 2 elements
        return;
    else
    {
        // we need to partition array into leftArray and rightArray
        int i;
        int mid = n/2;
        int *leftArray = malloc(sizeof(int)*mid);
        int *rightArray = malloc(sizeof(int)*(n-mid));

        // initializing elements
        for (i = 0; i < mid; ++i)
            leftArray[i] = arr[i];
        for (i = mid; i < n; ++i)
            rightArray[i-mid] = arr[i];

        mergeSort(leftArray, mid);
        mergeSort(rightArray, n-mid);
        mergeArrays(arr, leftArray, rightArray, mid, n-mid);
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
    mergeSort(arr, n);
    printArray(arr, n);
    return 0;
}
// T.C = O(n log n) not inplace
