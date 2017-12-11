#include<stdio.h>

int check(int num)
{
    int i;
    int pos = num;
    for (i = 2; i < num; ++i) // in worst case, I am letting it go upto n
    {
        if (pos < i)
            return 1;
        if (pos % i == 0)
            return 0;
        pos = pos - (pos/i);
    }
    return 1; // just for sample, in case the number passes every possibility so it would definitely be.
}

int main()
{
    int n;
    scanf("%d", &n);
    if (check(n) == 0)
        printf("NO");
    else
        printf("YES");
}
