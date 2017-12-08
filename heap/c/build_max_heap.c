#include<stdio.h>
#include<stdlib.h>

struct Heap
{
    int heapSize;
    int *arr;
};

void max_heapify(struct Heap *h, int i)
{
    int l = 2*i;
    int r = 2*i + 1;
    int largest = -1;

    if (l <= h->heapSize && h->arr[l] > h->arr[i])
        largest = l;
    else
        largest = i;

    if (r <= h->heapSize && h->arr[r] > h->arr[largest])
        largest = r;

    if (largest != i) // need for heapify
    {
        int t = h->arr[i];
        h->arr[i] = h->arr[largest];
        h->arr[largest] = t;

        max_heapify(h, largest);
    }
}

void buildMaxHeap(struct Heap *h)
{
    int i;
    for (i = h->heapSize/2; i >= 1; --i)
        max_heapify(h, i);
}

void printHeap(struct Heap *h)
{
    int i;
    printf("\n");
    for (i = 1; i <= h->heapSize; ++i)
        printf("%d ", h->arr[i]);
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    struct Heap *h;
    h->arr = malloc(sizeof(int)*(n+1));
    h->heapSize = n;

    int i;
    for (i = 1; i < n+1; ++i)
        scanf("%d", &h->arr[i]);

    buildMaxHeap(h);

    printf("The max heap is ");
    printHeap(h);

    return 0;
}
