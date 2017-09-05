/*
 * find two repeating elements in a given array
 * approach 4 : using xor
 * */
#include<stdio.h>
#include<stdlib.h>

void printRepElements(int *arr, int size)
{
    int n = size - 2, i, x = 0, y = 0;
    int xorRes = arr[0];

    for (i = 1; i < size; ++i)
        xorRes = xorRes ^ arr[i];
    for (i = 1; i <= n; ++i)
        xorRes = xorRes ^ i;
    // xorRes is now equal to x ^ y, so our task is now to find out x and y
    int setBit = xorRes & ~(xorRes-1);

    for (i = 0; i < size; ++i)
    {
        if (arr[i] & setBit)
            x = x ^ arr[i];
        else
            y = y ^ arr[i];
    }
    // now we even need to xor with natural numbers
    for (i = 1; i <= n; ++i)
    {
        if (i & setBit)
            x = x ^ i;
        else
            y ^= i;
    }

    printf("\nFirst number = %d\nSecond Number = %d", x, y);
}

int main()
{
    int i;
    int arr[] = {1, 4, 5, 1, 2, 5, 3};
    int n = sizeof(arr)/sizeof(arr[0]) - 2;// because we have n+2 elements in array

    printRepElements(arr, n+2);

    printf("\n");
    return 0;
}
