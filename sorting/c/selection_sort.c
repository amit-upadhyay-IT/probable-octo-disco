#include<stdio.h>
#include<stdlib.h>

void swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void selectionSort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n-1; ++i)// doing multiple iterations to find the minimum each time and places it at beginning
    {
        int minIndex = i;
        for (j = i+1; j < n; ++j)// getting the minimum index
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr, i, minIndex);
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
    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}
// time is order n^2 and inplace algo
