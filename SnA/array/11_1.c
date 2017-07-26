#include<stdio.h>
#include<stdlib.h>

void input_array(int *arr, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

void get_max_subarrays(int *arr, int n, int k)
{
    int i, j;
    for (i = 0; i <= n-k; ++i)
    {
        int max = arr[i];
        for (j = 1; j < k; ++j)
        {
            if (arr[i+j] > max)
                max = arr[i+j];
        }
        printf("%d ",max);
    }
}

int main()
{
    int n, *arr, k;
    scanf("%d", &n);
    arr = (int*)malloc(n*sizeof(int));
    input_array(arr, n);
    scanf("%d", &k);
    get_max_subarrays(arr, n, k);
    return 0;
}

// T.C = O(n*k)
// S.C = O(1)
