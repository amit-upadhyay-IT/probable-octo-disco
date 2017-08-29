/*
 * replacing all 0's with -1 and then changing the statement to:
 *      find maximum length subarray whose sum is X (here X will be 0)
 * using hash approach to solve problem in O(n), however binary search
 * can also be used to solve problem in O(n log n)
 * since we are using hash table without chaining thus, chances are there
 * that this program may not work for all test cases.
 * However corresponding java program would definitely work.
 *
 * one proper test case :
 * n = 12
 * arr: [1 1 1 0 1 0 0 0 1 1 1 0]
 * */
#include<stdio.h>
#include<stdlib.h>

void printSubArray(int *arr, int firstIndex, int lastIndex)
{
    int i;
    for (i = firstIndex; i <= lastIndex; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void replaceNegOnes(int *arr, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        if (arr[i] == -1)
            arr[i] = 0;
}

void getMaxSubArray(int *arr, int n)
{
    int i, hash[100] = {[0 ... 99] = -10}; // initializing all elements with -10 because we will store the indices of sum_so_far obtained.
    int sum = 0;
    int lower_bound = 0, upper_bound = 0, size = 0;
    for (i = 0; i < n; ++i)
    {
        sum = sum + arr[i];
        // check if hash contains
        if (hash[sum] != -10)// sum is present in hash
        {
            int current_size = i - hash[sum];
            if (size < current_size)
            {
                size = current_size;
                lower_bound = hash[sum];
                upper_bound = i;
            }
        }
        else// sum is not present in hash, so insert it
        {
            hash[sum] = i; //initializing with the index
        }
    }
    replaceNegOnes(arr, n);
    printSubArray(arr, lower_bound+1, upper_bound);
}

// takes O(n)
void replaceZeros(int *arr, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        if (arr[i] == 0)
            arr[i] = -1;
}

int main()
{
    int i, *arr, n;
    printf("\nEnter n\n");
    scanf("%d", &n);
    arr = malloc(sizeof(int)*n);
    printf("\nEnter elements\n");
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    replaceZeros(arr, n);
    getMaxSubArray(arr, n);
    return 0;
}

// T.C = O(n) <- only in one iteration we are solving the problem
// S.C = O(n) in worst case we may need to make the hashmap size equal to n
