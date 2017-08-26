/*
 *for each element in the array we will iterate through the array
 and check the count of arr[i] and if comes out to be odd then we return
 true from the function.
 */

#include<stdio.h>
#include<stdlib.h>

int get_odd_occurred_ele(int *arr, int n)
{
    int i, j;
    int count = 0;
    for (i = 0; i < n; ++i)
    {
        int index = i;
        for (j = 0; j < n; ++j)
        {
            if (arr[index] == arr[j])
                count++;
        }
        if (count % 2 != 0)
            return arr[index];
        count = 0;// after each complete iteration we need to start count with 0
    }
    return 0;
}

int main()
{
    int *arr, n, i;
    scanf("%d", &n);
    arr = (int *)malloc(n*sizeof(int));
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    int ret_val = get_odd_occurred_ele(arr, n);
    if (ret_val)
        printf("\n %d occurred odd number of times ", ret_val);
    else
        printf("\n No number occurred odd number of times\n");
    return 0;

}

// T.C = O(n^2)
// S.C = O(1)
