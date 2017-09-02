/*
 * check if the given number of power of 4.
 * use log4(n)
 * */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int isPowerFour(int n)
{
    while (n % 4 == 0)
        n = n >> 2;
    if (n == 1)
        return 1;
    else
        return 0;
}

int main()
{
    int n, k;
    printf("\nEnter n\n");
    scanf("%d", &n);

    if (isPowerFour(n))
        printf("\n%d is power of 4\n", n);
    else
        printf("\n%d is not power of 4\n", n);

    return 0;
}

