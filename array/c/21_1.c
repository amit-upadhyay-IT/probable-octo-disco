/*
 * possible number of triangles
 * get all the possible sub arrays of 3 elements and check the following condition:
 *      a + b < c
 *      b + c < a
 *      a + c < b
 * finding the possible subarrays with 3 elements will take nC3 time and checking for conditions would take constant time
 * so overall time would become O(n^3)
 * */
#include<stdio.h>

int checkCondition(int a, int b, int c)
{
    if (a+b > c)
        if (b+c > a)
            if (a+c > b)
                return 1;
    return 0;
}

int getCount(int *arr, int n)
{
    int i, j, k, cnt = 0;
    for (i = 0; i < n-2; ++i)
    {
        for (j = i+1; j < n-1; ++j)
        {
            for (k = j+1; k < n; ++k)
            {
                if (checkCondition(arr[i], arr[j], arr[k]))
                    cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    int arr[] = {12, 8, 14, 50, 7, 6, 10};
    int size = sizeof(arr)/ sizeof(arr[0]);

    int cnt = getCount(arr, size);
    printf("\nThe possible triangles are %d\n", cnt);
    return 0;
}
