/*
 * using bitwise xor to get oddly occurred element
 */

#include<stdio.h>

int get_odd_occurred_ele(int *arr, int n)
{
    int i;
    int ret_val = arr[0];
    for (i = 1; i < n; ++i)
        ret_val = arr[i]^ret_val;
    return ret_val;
}

int main()
{
    int i, n, arr[100];
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    int ret_val = get_odd_occurred_ele(arr, n);
    if (ret_val)
        printf("\n %d element occurred odd times\n", ret_val);
    else
        printf("\n No elements occurred odd times\n");
    return 0;
}
