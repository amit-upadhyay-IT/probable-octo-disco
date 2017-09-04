/*
 * sort a nearly sorted array
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

void sortIt(int *arr, int n)
{
    int i;
    for (i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j > 0 && key < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int i, *arr, n;
    printf("\nEnter n\n");
    scanf("%d", &n);
    arr = malloc(sizeof(int)*n);
    printf("\nEnter elements\n");
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    sortIt(arr, n);
    printArray(arr, n);

    return 0;
}
