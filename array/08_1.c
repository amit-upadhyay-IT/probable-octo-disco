#include<stdio.h>
#include<stdlib.h>

void show_triplets(int *arr, int n, int x)
{
    int i, j, k;
    for (i = 0; i < n; ++i)
        for (j = i+1; j < n; ++j)
            for (k = j+1; k < n; ++k)
                if (arr[i] + arr[j] + arr[k] == x)
                    printf("(%d, %d, %d)", arr[i], arr[j], arr[k]);
}

int main()
{
    int n, *arr, i, x;
    scanf("%d", &n);
    arr = (int*)malloc(n*sizeof(int));
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    scanf("%d", &x);
    show_triplets(arr, n, x);
    return 0;
}

//T.C = O(n^3)
//S.C = O(1)
