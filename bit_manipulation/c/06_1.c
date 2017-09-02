/*
 * check whether a given number of power of 2.
 * in every number which is power of 2, the set bits count is always 1.
 * so we can count the set bits in number
 * */
#include<stdio.h>
#include<stdlib.h>

int countSetBits(int n)
{
    int count = 0;
    while (n != 0)
    {
        int rem = n & 1;// check the lsb
        if (rem == 1)
            count++;
        n = n>>1;
    }
    return count;
}

int main()
{
    int n, k;
    printf("\nEnter n\n");
    scanf("%d", &n);

    int count = countSetBits(n);
    if (count == 1)
        printf("\nThe number %d is power of 2\n", n);
    else
        printf("\nThe number %d is not power of 2\n", n);
    printf("\n");
    return 0;
}

// T.C = O(log n)
// space is constant
