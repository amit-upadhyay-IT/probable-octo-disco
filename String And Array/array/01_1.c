
#include<stdio.h>
#include<math.h>

// to get pairs in array whose sum is x
void get_pairs(int arr[], int x, int n)
{
    int i, j;
    // use brute force
    for (i = 0; i < n; ++i)
    {
        for (j = i; j < n; ++j)
            if (arr[i]+arr[j] == x)
            {
                printf("(%d , %d)\n", arr[i], arr[j]);
            }
    }
}

int main()
{
    int arr[20], n, i, x;

    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    printf("\n");

    printf("\n Enter element x : \n");
    scanf("%d", &x);

    get_pairs(arr, x, n);

    return 0;
}
