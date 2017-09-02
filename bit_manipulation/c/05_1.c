/* count the number of set bits in a number
 * we can do modlo 2 and get the lsb if its one the we increase the count
 * we do above process until n becomes 0
 * */
#include<stdio.h>
#include<stdlib.h>

int countSetBits(int n)
{
    int count = 0;
    while (n != 0)
    {
        int rem = n % 2;
        if (rem == 1)
            count++;
        n = n/2;
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

