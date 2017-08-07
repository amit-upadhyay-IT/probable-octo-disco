#include<stdio.h>
#include<stdlib.h>

void input_array(int *arr, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

int get_equilibrium_index(int *arr, int n)
{
    int i, j;
    int left_sum = 0, right_sum = 0;
    for (i = 0; i < n; ++i)
    {
        left_sum += arr[i];
         for (j = i+1; j < n; ++j)
         {
             right_sum += arr[j];
         }
         if (left_sum == right_sum)
             return i;
         right_sum = 0;
    }
    return -1;
}

int main()
{
    int n, *arr;
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    input_array(arr, n);
    int ret = get_equilibrium_index(arr, n);
    if (ret != -1)
        printf("\n%d is the equilibrium index\n",ret);
    else
        printf("\nThere is no equilibrium index\n");
    return 0;
}
