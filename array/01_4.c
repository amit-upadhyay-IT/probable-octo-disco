#include<stdio.h>

void show_pairs(int *arr, int n, int x)
{
    int i, temp;
    // create a hashtable and store the number as the indices of table.
    int hash_tab[50] = {0};// inserted 0 into all
    for (i = 0; i < n; ++i)
    {
        temp = x - arr[i];// will see what is the required element to add up the sum
        if (temp >= 0 && hash_tab[temp] == 1)
            printf("(%d, %d)\n", arr[i], x-arr[i]);
        hash_tab[arr[i]] = 1;
    }
}

int main()
{
    int n, arr[50], x, i;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    printf("\n Enter required sum : \n");
    scanf("%d", &x);
    show_pairs(arr, n, x);
    return 0;
}

// T.C = O(n) -> works for unsorted array too.
// S.C = O(n) -> for hashtable
