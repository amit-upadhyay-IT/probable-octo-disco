// toggle kth bit of a number
#include<stdio.h>
#include<stdlib.h>

int toggleKthBit(int n, int k)
{
    int otherNum = 1 << k;
    int newNum = n ^ otherNum;
    return newNum;
}

int main()
{
    int n, k;
    printf("\nEnter n\n");
    scanf("%d", &n);
    printf("Enter k\n");
    scanf("%d", &k);
    int ans = toggleKthBit(n, k);
    printf("\nAfter the toggle we get %d\n", ans);
    printf("\n");
    return 0;
}

// T.C = O(n) where n is the number values not the number of bits
// S.C = constant
