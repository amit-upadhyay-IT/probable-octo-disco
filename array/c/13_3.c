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
    int hash[10000] = {0};
    int sum = 0;
    int i;
    for (i = 0; i < n; ++i)
    {
        sum = sum + arr[i];
        hash[sum] = i+1;//adding 1 so that we can't have zero as value of any hash
        if (hash[sum - x])
        {
            int firstIndex = hash[sum-x];
            int secondIndex = i;
            printSubArray(arr, firstIndex, secondIndex);
            break;
        }
    }
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
