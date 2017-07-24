#include<stdio.h>
#include<stdlib.h>

void input_array(int *arr, int n)
{
    int i;
    for (i = 0; i< n; ++i)
        scanf("%d", &arr[i]);
}

void print_array(int *arr, int n)
{
    int i;
    for (i = 0; i< n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int numcmp(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int check_for_pair(int *arr, int n, int start, int x)
{
    int first_pos = start;
    int last_pos = n-1;
    int i;
    while (first_pos < last_pos)
    {
        int sum = arr[first_pos] + arr[last_pos] + arr[start-1];
        if (sum < x)
            first_pos++;
        else if (sum > x)
            last_pos--;
        else
        {
            printf("(%d, %d, %d)\n", arr[start-1], arr[first_pos], arr[last_pos]);
            first_pos++; last_pos--;
        }
    }
}

void find_triplets(int *arr, int n, int x)
{
    int i;
    for (i = 1; i < n; ++i)
    {
        check_for_pair(arr, n, i, x);
    }
}

int main()
{
    int i, n, *arr, x;
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    input_array(arr, n);
    scanf("%d", &x);
    qsort(arr, n, sizeof(int), numcmp);
    find_triplets(arr, n, x);
    return 0;
}
// T.C = O(N^2)
// S.C = O(1)
