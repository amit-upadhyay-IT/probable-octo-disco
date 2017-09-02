/*
 * check if the given number of power of 4.
 * use log4(n)
 * */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n, k;
    printf("\nEnter n\n");
    scanf("%d", &n);

    int logVal = log10(n)/log10(4);// finding the log4
    if (pow(4, logVal) == n)
        printf("\n%d is power of 4\n", n);
    else
        printf("\n%d is not power of 4\n", n);

    return 0;
}

