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
    int n;
    int arr[] = {1, 4, 5, 1, 2, 5, 3};
    n = sizeof(arr)/sizeof(arr[0]) - 2;
    printDuplicates(arr, n+2);

    printf("\n");
    return 0;
}
