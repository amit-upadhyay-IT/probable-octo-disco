/*
 * using hashing to solve problem
 */
#include<stdio.h>
#include<stdlib.h>

int get_odd_occurred_element(int *arr, int n)
{
    int hash_set[1000] = {0}, i = 0;// no element can be greater then 1000
    for (i = 0; i < n; ++i)
    {
        hash_set[arr[i]]++;
    }
    // iterating over hash_set to see oddly occurred element
    for (i = 0; i < n; ++i)
        if (hash_set[arr[i]] & 1)
            return arr[i]; // return the element which occurred odd times
    return 0;

}

int main()
{
    int n, *arr, i;
    scanf("%d", &n);
    arr = (int *)malloc(n*sizeof(int));
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    int ret_val = get_odd_occurred_element(arr, n);
    if (ret_val)
        printf("\n%d element occurred odd times\n", ret_val);
    else
        printf("\n No element occurred odd times\n");
    return 0;
}

// T.C = O(n)
// S.C = O(n)
