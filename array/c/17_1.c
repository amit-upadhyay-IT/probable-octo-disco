/*
 * find the duplicates in O(n) and O(1) space, given 0<=arr[i]<=n-1
 * */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void printDuplicates(int *arr, int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        // check sign of arr[arr[i]]
        if (arr[abs(arr[i])] >= 0)// positive
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
            printf("%d ", abs(arr[i]));// repeated
    }
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int *arr = malloc(sizeof(int)*n);
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    printDuplicates(arr, n);

    return 0;
}
