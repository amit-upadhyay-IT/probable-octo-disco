/*
 * check whether a given number of power of 2.
 * simple find log base 2 of that number, if result seems integral then its power of 2
 * */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n, k;
    printf("\nEnter n\n");
    scanf("%d", &n);

    float res = log2(n);
    if (res - (int)res == 0)
        printf("\nThe number %d is power of 2\n", n);
    else
        printf("\nThe number %d is not power of 2\n", n);
    printf("\n");
    return 0;
}

// time should be the time used in evaluation of log2
