// clear kth bit of a number
#include<stdio.h>
#include<stdlib.h>

int clearKthBit(int n, int k)
{
    int otherNum = 1 << k;
    otherNum = ~otherNum;
    int newNum = otherNum & n;
    return newNum;
}

int main()
{
    int n, k;
    printf("\nEnter n\n");
    scanf("%d", &n);
    printf("Enter k\n");
    scanf("%d", &k);
    int num = clearKthBit(n, k);
    if (num == k)
        printf("\nThe %d bit is already cleared\n", k);
    else
        printf("\nAfter clearing the %d bit we get the number as %d\n", k, num);
    printf("\n");
    return 0;
}

// T.C = O(n) where n is the number values not the number of bits
// S.C = constant
