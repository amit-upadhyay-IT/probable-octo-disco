#include<stdio.h>
#include<stdlib.h>

int* get_span_array(int *arr, int len)
{
    int* span_arr = malloc(sizeof(int)*len);
    span_arr[0] = 0;
    // iterate over arr
    for (int i = 1; i < len; ++i)
    {
        int cnt = 0;
        int j = i - 1;
        while (j >= 0 && arr[j] < arr[i])
        {
            cnt++;
            j--;
        }
        span_arr[i] = cnt;
    }
    return span_arr;
}

int main()
{
    int price[] = {10, 4, 5, 90, 120, 80};
    int len = sizeof(price)/sizeof(price[0]);
    int *res = get_span_array(price, len);
    int i;
    for (i = 0; i < len; ++i)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}

// time complexity = O(n^2)
// space complexity = O(1), because we require to output the result array
// so that isn't extra space used
