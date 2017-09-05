/*
 * find two repeating elements in a given array
 * approach 1
 * */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void printRepeating(int *arr, int size)
{
    // for every element check the other element and print of they are matching
    int i, j;
    for(i = 0; i < size; ++i)
    {
        for (j = i+1; j < size; ++j)
        {
            if (arr[i] == arr[j])
                printf("%d ", arr[i]);
        }
    }
}

int main()
{
    int arr[] = {0, 3, 4, 2, 2, 4, 1};
    int n = sizeof(arr)/sizeof(arr[0]) - 2;// because we have n+2 elements in array
    printRepeating(arr, n+2);

    printf("\n");
    return 0;
}
