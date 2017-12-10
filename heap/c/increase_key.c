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

void increase_key(struct Heap* h, int index, int key)
{
    if (key <= h->arr[index])
    {
        printf("\nError\n");
        return;
    }

    h->arr[index] = key;

    // as we have increased the value of node, so property of max heap will still be maintained, so just see if parent node has been disturbed or not

    while (index > 1 && h->arr[index/2] < h->arr[index])
    {
        // swap parent and child
        int temp = h->arr[index];
        h->arr[index] = h->arr[index/2];
        h->arr[index/2] = temp;

        index /= 2;
    }
}

void printHeap(struct Heap *h)
{
    int i;
    printf("\n");
    for (i = 1; i <= h->heapSize; ++i)
    {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}


int main()
{
    int i;
    struct Heap *h;
    printf("\nEnter heap size\n");
    scanf("%d", &h->heapSize);

    printf("\nEnter heap elements \n");
    for (i = 1; i <= h->heapSize; ++i)
        scanf("%d", &h->arr[i]);

    buildMaxHeap(h);

    int ind, val;
    printf("\nEnter the index and the value with which you wanna replace the key\n");
    scanf("%d%d", &ind,&val);

    printf("\nThe heap before increasing the key\n");
    printHeap(h);

    increase_key(h, ind, val);
    printf("\nThe heap after increasing the key\n");
    printHeap(h);
}
