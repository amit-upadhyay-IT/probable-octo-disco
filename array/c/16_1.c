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

int main()
{
    int i, *arr, n;
    printf("\nEnter n\n");
    scanf("%d", &n);
    arr = malloc(sizeof(int)*n);
    printf("\nEnter elements\n");
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    return 0;
}
