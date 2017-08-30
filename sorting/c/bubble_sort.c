#include<stdio.h>
#include<stdlib.h>

void swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void bubbleSort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n; ++i)// used for doing multiple scans
        for (j = 0; j < n-i-1; ++j)// used for bubbling up the maximum element in the end
            if (arr[j] > arr[j+1])
                swap(arr, j, j+1);
}

void optimalBubbleSort(int *arr, int n)
{
    int i, j, swapped;
    for (i = 0; i < n; ++i)// used for doing multiple scans
    {
        swapped = 0;
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr, j, j+1);
                swapped = 1;
            }
        }
        if (!swapped)// now the array is sorted so there is no need to do more iterations
            break;
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
    bubbleSort(arr, n);
    printArray(arr, n);
    optimalBubbleSort(arr, n);
    printArray(arr, n);

    return 0;
}

// time order is n^2 and it's inplace
