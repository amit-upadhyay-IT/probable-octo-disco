#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int n)
{
    int i;
    for (i = 1; i <= n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}


int* countingSort(int *arr, int n, int range)
{
    int i;
    int *b = malloc(sizeof(int)*(n+1));// new sorted array
    int *c = malloc(sizeof(int)*(range+1));// count of occurrence of element of arr

    //initializing c with 0
    for (i = 1; i <= range; ++i)
        c[i] = 0;

    // put count of occurrences of elements of arr in c
    for (i = 0; i < n; ++i)
        c[arr[i]]++;

    for (i = 2; i <= range; ++i)
        c[i] = c[i-1]+c[i];

    for (i = n-1; i >= 0; --i)
    {
        b[c[arr[i]]] = arr[i];
        c[arr[i]]--;
    }

    return b;
}

int main()
{
    int arr[] = {2, 4, 3, 1, 1, 3, 5, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int range = 5;

    int *b = countingSort(arr, n, range);
    printArray(b, n);

    return 0;
}
