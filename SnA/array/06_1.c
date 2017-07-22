#include<stdio.h>
#include<stdlib.h>

int zero_cnt(int *arr, int n)
{
    int i, cnt = 0;
    for (i = 0; i < n; ++i)
        if (arr[i] == 0)
            cnt++;
    return cnt;
}

void set_array_element(int *arr, int n, int z_cnt)
{
    int i;
    for (i = 0; i < z_cnt; ++i)
         arr[i] = 0;
    for (i = z_cnt; i < n; ++i)
        arr[i] = 1;
}

void print_array(int *arr, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}

int main()
{
    int i, n, *arr;
    scanf("%d", &n);
    arr = (int*) malloc(n*sizeof(int));
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    int z_cnt = zero_cnt(arr, n);
    set_array_element(arr, n, z_cnt);
    print_array(arr, n);
    return 0;
}
