#include<stdio.h>

int check_for_more(int *arr, int n)
{
    int i;
    int flag = 0;
    int half = n/2;
    for (i = 0; i < n/2+1; ++i)
    {
        if (arr[i] == arr[i+half])
        {
            flag = 1;
            break;
        }
    }
    if (flag)
        return arr[i];
    else
        return -1;
}

int main()
{
    int arr[50], n, i;

    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    printf("\n");
    int val = check_for_more(arr, n);
    if (val != -1)
        printf("\n %d occurred more than n/2\n", val);
    else
        printf("\n No number occurred more than n/2\n");

    return 0;
}
