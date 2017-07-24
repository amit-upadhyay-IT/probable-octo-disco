#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

void input_array(int *arr, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

void print_array(int *arr, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int cmpnum(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int binary_search(int *arr, int n, int x)// I am searching from beginning index so thing will result in printing of same pair with different order
{
    int i, mid, first, last;
    first = 0, last = n-1;
    while (first <  last)
    {
         mid = (first + last)/2;
         if (arr[mid] == x)
             return arr[mid];
         else if (arr[mid] > x)
             last = mid-1;
         else
             first = mid+1;
    }
    return INT_MIN;
}

void find_triplets(int *arr, int n, int x)
{
    int i, j;
    for (i = 0; i< n; ++i)
        for (j = i+1; j < n; ++j)
        {
            int req = x - (arr[i] + arr[j]);
            int val = binary_search(arr, n, req);
            if (val != INT_MIN)
                printf("(%d, %d, %d)", arr[i], arr[j], val);
        }
}

int main()
{
    int *arr, n, i, x;
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    input_array(arr, n);
    scanf("%d", &x);
    qsort(arr, n, sizeof(int), cmpnum);
    find_triplets(arr, n, x);
    printf("\n");
    return 0;
}

// T.C = (n^2 log n)
// S.C = O(1)
