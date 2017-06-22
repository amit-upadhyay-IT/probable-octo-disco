#include<stdio.h>
// NOTE: array input has to be sorted for correct output.
void check_pair(int *, int, int);

int main()
{
    int arr[50], i, n;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    int x;
    scanf("%d", &x);
    check_pair(arr, n, x);
    return 0;
}

int binary_search(int *arr, int key, int first, int last)
{
    int mid;
    while (first <= last)
    {
        mid = (first+last)/2;
        if (arr[mid] == key)
            return 1;
        else if (arr[mid] < key)
            first = mid+1;
        else
            last = mid-1;
    }
    return 0;
}

void check_pair(int *arr, int n, int x)
{
    int i;
    for (i = 0; i < n; ++i)
         if (binary_search(arr, x-arr[i], 0, n-1))
            printf("(%d , %d)", arr[i], x-arr[i]);
}
