/*
 * multiply the given number without using * operator
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

    n = (n << 3) - n;
    printf("\nMultiplication with 7 is %d\n", n);
    return 0;
}

