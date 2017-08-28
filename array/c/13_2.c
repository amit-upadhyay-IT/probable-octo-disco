// assuming that elements in the array are positive
#include<stdio.h>
#include<stdlib.h>

void printSubArray(int *arr, int firstIndex, int secondIndex)
{
    int i;
    for (i = firstIndex; i <= secondIndex; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void getSubArray(int *arr, int n, int x)
{
    int i, j, sum = 0;
    i = 0, j = 0;// i and j are leftpointer and rightpointer respectively.
    int flag = 0;
    while (i < n && j < n)
    {
        sum = arr[i] + arr[j];
        if (sum == x)
        {
            printSubArray(arr, i, j);
            flag = 1;
            break;
        }
        if (sum < x)
            j++;// incrementing rightpointer because we need to add few more elements in the set
        else
            i++;
    }
    if (!flag)
        printf("no sub array with sum %d\n", x);
}

int main()
{
    int n, i, *arr, x;
    scanf("%d", &n);
    arr = malloc(sizeof(int) * n);

    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    scanf("%d", &x);

    getSubArray(arr, n, x);
    return 0;
}
