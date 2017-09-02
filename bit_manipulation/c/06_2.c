/*
 * check whether a given number of power of 2.
 * we can do and of n and n-1
 * */
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, k;
    printf("\nEnter n\n");
    scanf("%d", &n);

    if (n == 0)
        printf("\n The number is not power of 2");
    int res = n & (n-1);
    if (res == 0)
        printf("\nThe number %d is power of 2\n", n);
    else
        printf("\nThe number %d is not power of 2\n", n);
    printf("\n");
    return 0;
}

// what is the time complexity?
