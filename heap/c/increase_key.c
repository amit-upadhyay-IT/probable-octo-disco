/*
 * increase the key in heap
 * */

#include<stdio.h>
#include<stdlib.h>

struct Heap
{
    int heapSize;
    int *arr;
};

int main()
{
    int i;
    struct Heap *h;
    printf("\nEnter heap size\n");
    scanf("%d", &h->heapSize);

    printf("\nEnter heap elements \n");
    for (i = 1; i <= h->heapSize; ++i)
        scanf("%d", &h->arr[i]);
}
