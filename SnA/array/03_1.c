/*
 * moore voting algo
 * two steps: find major candidate, check if thats the majority or not
 * */
#include<stdio.h>
#include<stdlib.h>

int get_majority_candidate(int *arr, int n)
{
    int i;
    int current_element = arr[0], element_vote = 1;

    for (i = 1; i < n; ++i)
    {
        if (arr[i] == current_element)
            element_vote++;
        else
        {
            // now two cases may aries, element_vote can be greater than 0 or can be 0; if it is 0
            // then change the current_element to arr[i];
            if (element_vote == 0)
            {
                 current_element = arr[i];
                 element_vote++;
            }
            else
                element_vote--;
        }
    }
    return current_element;
}

int check_if_major(int *arr, int n, int candidate)
{
    int i, count = 0;
    for (i = 0; i < n; ++i)
        if (arr[i] == candidate)
            count++;
    return (count > n/2)?1:0;
}

int main()
{
    int *arr, n, i;
    scanf("%d", &n);
    arr = (int*) malloc(n*sizeof(int));
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    int majority_candidate = get_majority_candidate(arr, n);
    int val = check_if_major(arr, n, majority_candidate);
    if (val)
        printf("\n%d is the majority candidate \n", majority_candidate);
    else
        printf("\nThere are no majority element in the array \n");
    return 0;
}
