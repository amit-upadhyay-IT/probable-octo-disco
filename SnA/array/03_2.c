#include<stdio.h>
#include<stdlib.h>

int* get_diff_arr(int *arr, int n)
{
    int i;
    int *diff;
    diff = (int*)malloc((n-1)*sizeof(int));
    for (i = 0; i < n-1; ++i)
    {
        diff[i] = arr[i+1] - arr[i];
    }
    return diff;
}

int get_max_sum_subarray(int *arr, int n)
{
    int max_so_far = 0, max_ending_here = 0, i;
    for (i = 0; i < n; ++i)
    {
        max_ending_here += arr[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_ending_here > max_so_far)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}

int main()
{
    int n, i, *arr;
    scanf("%d", &n);
    arr = (int*)malloc(n*sizeof(int));
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    int *diff_arr = get_diff_arr(arr, n);// this will have length as one less than the original array.
    int res = get_max_sum_subarray(diff_arr, n-1);
    printf("\n result is %d \n", res);
    return 0;
}
