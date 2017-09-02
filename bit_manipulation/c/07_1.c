/*
 * find the next highest number of a given number which is power of 2
 * 2^(floor(log2(n)+1))
 * */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n, k;
    printf("\nEnter n\n");
    scanf("%d", &n);

    int ans = pow(2, floor(log2(n)+1));
    printf("\nThe next higher number of %d which is power of two is %d\n", n, ans);
    printf("\n");
    return 0;
}

// time should be the time used in evaluation of log2
