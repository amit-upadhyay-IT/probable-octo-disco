#include<iostream>
#include<stdlib.h>

int getPrev(int n)
{
    int temp = n;
    int c0 = 0;
    int c1 = 0;
    while  (temp & 1 == 1)
    {
        c1++;
        temp >>= 1;
    }

    if (temp == 0)
        return -1;

    while ((temp & 1) == 0 && (temp != 0))
    {
        c0++;
        temp >>= 1;
    }

    int p = c0 + c1;
    n &= ((~0) << (p+1));

    int mask = (1 << (c1+1)) - 1;
    n |= mask << (c0 -1);

    return n;
}

int main()
{
    std::cout<<getPrev(13948)<<std::endl;

}
