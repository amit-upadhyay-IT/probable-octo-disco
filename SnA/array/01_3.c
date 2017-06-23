#include<stdio.h>
// NOTE: array input has to be sorted for correct output.
void check_pair(int *, int, int);

int main()
{
    int arr[50], i, n;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    int x;
    scanf("%d", &x);
    check_pair(arr, n, x);
    return 0;
}

void check_pair(int *arr, int n, int x)
{
    // take firstpos and lastpos and store element value there.
    int first_pos = 0;
    int last_pos = n-1;
    while (first_pos <= last_pos)
    {
        if (arr[first_pos]+arr[last_pos] < x)
            first_pos = first_pos+1;
        else if (arr[first_pos] + arr[last_pos] > x)
            last_pos = last_pos - 1;
        else
        {
            printf("(%d , %d)\n", arr[first_pos], arr[last_pos]);
            first_pos += 1;
            last_pos -= 1;
        }
    }
}

// T.C = O(n)
// S.C = O(1)
