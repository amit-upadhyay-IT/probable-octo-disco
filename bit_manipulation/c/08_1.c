/*
 * check if the given number of power of 4.
 * see the position of the set bit and make count of set bit
 * */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int isPowerFour(int n)
{
    int cnt = 0, pos = 0;
    while (n)
    {
        pos++;
        n = n >> 1;
        if (n & 1)
            cnt++;
    }
    if (cnt != 1)
        return 0;
    if (pos % 2 != 0)// i.e. set bit is at position
        return 1;
    else
        return 0;
}

int main()
{
    int n, k;
    printf("\nEnter n\n");
    scanf("%d", &n);

    if (isPowerFour(n))
        printf("\n%d is power of 4");
    else
        printf("\n%d is not power of 4");

    printf("\n");
    return 0;
}

