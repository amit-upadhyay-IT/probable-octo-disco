/*
 * find two repeating elements in a given array
 * approach 2: using hash array *
 * */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void doHashing(int *arr, int *hash, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        hash[arr[i]]++;
}

void getRepElements(int *hash, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        if (hash[i] >= 2)
            printf("%d ", i);
}

int main()
{
    int arr[] = {0, 3, 4, 2, 2, 4, 1};
    int n = sizeof(arr)/sizeof(arr[0]) - 2;// because we have n+2 elements in array
    int hash[100] = {0};
    doHashing(arr, hash, n+2);
    getRepElements(hash, n);

    printf("\n");
    return 0;
}

