// set the kth bit of a number
#include<stdio.h>
#include<stdlib.h>

int checkKthBit(int n, int k)
{
    int otherNum = 1<<k;
    return n & otherNum;
}

int setKthBit(int n, int k)
{
    int otherNum = 1 << k;
    int newNum = otherNum | n;
    return newNum;
}

int main()
{
    int n, k;
    printf("\nEnter n\n");
    scanf("%d", &n);
    printf("Enter k\n");
    scanf("%d", &k);
    if (checkKthBit(n, k))
        printf("\n%d bit is set", k);
    else
    {
        int ret = setKthBit(n, k);
        printf("\nThe new number formed after setting kth bit is %d \n", ret);
    }
    printf("\n");
    return 0;
}

// T.C = O(n) where n is the number values not the number of bits
// S.C = constant
