// check if kth bit is set or unset
#include<stdio.h>
#include<stdlib.h>

int checkKthBit(int n, int k)
{
    int otherNum = 1<<k;
    return n & otherNum;
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
        printf("\n%d bit is unset", k);
    printf("\n");
    return 0;
}
