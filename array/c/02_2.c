#include<stdio.h>
#include<math.h>

int find_occurrance(int *arr, int n, int x, int first_search)
{
    int first = 0, last = n-1, mid, result = -1;
    while (first <= last)
    {
        mid = (first+last)/2;
        if (arr[mid] == x)
        {
            if (first_search)
                last = mid-1;
            else
                first = mid+1;
            result = mid;
        }
        else if (x < arr[mid])
            last = mid-1;
        else
            first = mid+1;
    }
    return result;
}

int main()
{
    int arr[50], n, i, x;

    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    x = arr[(n-1)/2];
    int first_ret_val, last_ret_val;
    first_ret_val = find_occurrance(arr, n, x, 1);
    if (first_ret_val != -1)
    {
        last_ret_val = find_occurrance(arr, n, x, 0);

        if (last_ret_val - first_ret_val + 1 >= n/2)
            printf("\n %d occurred more than %d times ", x, n/2);
        else
            printf("\n No element occurred more than %d times ", n/2);
    }
    printf("\n");
    return 0;
}

// T.C = O(log n)
// S.C = O(1)
