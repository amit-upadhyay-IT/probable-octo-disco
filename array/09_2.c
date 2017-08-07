#include<stdio.h>
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

int get_equilibrium_index(int *arr, int n)
{
    int i, *left_arr, *right_arr;
    left_arr = (int*)malloc((n+1)*sizeof(int));
    right_arr = (int*)malloc((n+1)*sizeof(int));
    left_arr[0] = arr[0];
    right_arr[0] = arr[n-1];
    // filling left_arr with sum of elements from left
    for (i = 1; i < n; ++i)
        left_arr[i] = left_arr[i-1] + arr[i];
    // filling right_arr with sum of elements from right
    for (i = 1; i < n; ++i)
        right_arr[i] = right_arr[i-1] + arr[n-i-1];
    // now iterating over left_arr and right_arr and checking if somewhere the elements matches
    for (i = 0; i < n; ++i)
        if (left_arr[i] == right_arr[i+1])
            return i;
    //print_array(left_arr, n);
    //print_array(right_arr, n);
    return -1;
}

int main()
{
    int n, *arr;
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    input_array(arr, n);
    int ret_val = get_equilibrium_index(arr, n);
    if (ret_val != -1)
        printf ("\n%d is the equilibrium index\n", ret_val);
    else
        printf("\nThere is no equilibrium index\n");
    return 0;
}
