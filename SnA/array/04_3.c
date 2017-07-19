#include<stdio.h>

int get_max_diff(int *arr, int n)
{
    int i, min_so_far, max_diff_so_far = 0;
    min_so_far = arr[0];
    for (i = 1; i < n; ++i)
    {
        if (arr[i] < min_so_far)
            min_so_far = arr[i];
        if (arr[i] - min_so_far > max_diff_so_far)
            max_diff_so_far = arr[i] - min_so_far;
    }
    return max_diff_so_far;
}

int main()
{
    int i, n, *arr;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    int max_diff = get_max_diff(arr, n);
    printf("\nThe maximum difference b/w two elements in array such that larger\
number appears after the smaller is %d\n", max_diff);
    return 0;
}
