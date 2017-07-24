#include<stdio.h>
#include<stdlib.h>

void input_array(int *arr, int n)
{
    int i;
    for (i = 0; i< n; ++i)
        scanf("%d", &arr[i]);
}

void print_array(int *arr, int n)
{
    int i;
    for (i = 0; i< n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int numcmp(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

void find_triplets(int *arr, int n, int x)
{
    int i;
}

int main()
{
    int i, n, *arr, x;
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    input_array(arr, n);
    scanf("%d", &x);
    qsort(arr, n, sizeof(int), numcmp);
}
