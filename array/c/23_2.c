/*
 * change a[i] to a[a[i]]
 * approach 2: encrypting other element into one and later getting them by applying some operators
 * */
#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void changeArray(int *arr, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        arr[i] = arr[i] + (arr[arr[i]]%n)*n;// encrypting: a <- a + b*n.... later we can get as a <- a%n and b as b <- a/n

    for (i = 0; i < n; ++i)
        arr[i] = arr[i]/n;
}

int main()
{
    int arr[] = {3, 1, 0, 2, 4};
    int size = sizeof(arr)/sizeof(arr[0]);

    changeArray(arr, size);
    printArray(arr, size);

    printf("\n");
    return 0;
}

// Time is O(n)
// space is constant
