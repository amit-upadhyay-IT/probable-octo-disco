#include<stdio.h>

int get_max_diff(int *arr, int n)
{
    int i, j, max_diff = 0;

    for (i = n-1; i >= 0; --i)
    {
        for (j = i-1; j >= 0; --j)
        {
            if (arr[i] - arr[j] > max_diff)
                max_diff = arr[i] - arr[j];
        }
    }
    return max_diff;
}

int main()
{
    int i, arr[100], n;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    printf("\n%d is the maximum difference \n", get_max_diff(arr, n));
    return 0;
}
