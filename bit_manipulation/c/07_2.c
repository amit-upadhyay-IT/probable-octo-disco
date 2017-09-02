/*
 * find the next highest number of a given number which is power of 2
 * get the bit position of msb which is 1
 * form a number and set (POS+1)th bit as 1 and rest as 0
 * */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int getMSBcnt(int n)
{
    int cnt = 0;
    while (n)
    {
        n = n >> 1;
        cnt++;
    }
    return cnt;
}

int getNextHigher(int pos)
{
    int num = 1 << pos;
    return num;
}

int main()
{
    int n, k;
    printf("\nEnter n\n");
    scanf("%d", &n);

    int cnt = getMSBcnt(n);
    int ans = getNextHigher(cnt);
    printf("\nThe next higher number of %d which is power of two is %d\n", n, ans);
    printf("\n");
    return 0;
}

// time complexity = O(log n)
