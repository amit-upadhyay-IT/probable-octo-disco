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
    for (i = 0; i < n; ++i)
    {
        sum = arr[i];
        for (j = i+1; j < n; ++j)
        {
            sum = sum + arr[j];

            if (sum == x)
            {
                printSubArray(arr, i, j);
                break;
            }
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
