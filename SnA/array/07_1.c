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
}

void swap(int *arr, int a, int b)
{
     int t = arr[a];
     arr[a] = arr[b];
     arr[b] = t;
}

int partition(int *arr, int start, int end)
{
    int pivot = arr[end];
    int partitionIndex = start;
    int i;
    for (i = start; i < end; ++i)
    {
         if (arr[i] <  pivot)
         {
            swap(arr, i, partitionIndex);
            partitionIndex++;
         }
    }
    swap(arr, partitionIndex, end);
    return partitionIndex;
}

void quick_sort(int *arr, int start, int end)
{
    if (start < end)
    {
         int pIndex = partition(arr, start, end);// for partition index
         quick_sort(arr, start, pIndex-1);
         quick_sort(arr, pIndex+1, end);
    }
}

int get_mod(int num)
{
    if (num < 0)
        num = -1*num;
    return num;
}

struct PairInfo
{
    int f_pos, l_pos;
};

struct PairInfo get_pair_info(int *arr, int n, struct PairInfo pair_info)
{
    int i, sum_so_far = 100000;// some maximum value of int
    int first_pos = 0, last_pos = n-1;
    while (first_pos < last_pos)
    {
         int sum = arr[first_pos] + arr[last_pos];
         if (sum < 0)
         {
             if (get_mod(sum) < sum_so_far)
             {
                 sum_so_far = get_mod(sum);
                 pair_info.f_pos = first_pos;
                 pair_info.l_pos = last_pos;
             }
             first_pos++;
         }
         else if(sum > 0)
         {
             if (get_mod(sum) < sum_so_far)
             {
                 sum_so_far = get_mod(sum);
                 pair_info.f_pos = first_pos;
                 pair_info.l_pos = last_pos;
             }
             last_pos--;
         }
         else
         {
             pair_info.f_pos = first_pos;
             pair_info.l_pos = last_pos;
             return pair_info;
         }
    }
    return pair_info;
}

int main()
{
    int n, i, *arr;
    scanf("%d", &n);
    arr = (int*)malloc(n*sizeof(int));
    input_array(arr, n);
    quick_sort(arr, 0, n-1);
    print_array(arr, n);

    struct PairInfo pair_info;
    pair_info = get_pair_info(arr, n, pair_info);
    printf("\nThe elements are %d and %d\n", arr[pair_info.f_pos], arr[pair_info.l_pos]);
    return 0;
}
