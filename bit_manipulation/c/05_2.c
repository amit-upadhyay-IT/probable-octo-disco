/* count the number of set bits in a number
 * instead of finding modulo 2 to check last bit, we can perform ANDing of number
 * with 1.
 * also instead of dividing the number by 2, we can perform right shift by 1.
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
    printf("\nThe number of set bits in %d is %d\n", n, count);
    printf("\n");
    return 0;
}

// T.C = O(log n)
// space is constant
