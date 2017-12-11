/*
 * heap sort
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

void heapSort(struct Heap *h)
{
    buildMaxHeap(h);

    int i;
    for (i = h->heapSize; i >= 2; --i)
    {
        // swap the root with last
        int temp = h->arr[h->heapSize];
        h->arr[h->heapSize] = h->arr[1];
        h->arr[1] = temp;

        h->heapSize--;

        max_heapify(h, 1);
    }
}


int main()
{
    struct Heap *h;
    int i;
    printf("\nEnter array size\n");
    scanf("%d", &h->heapSize);

    int n = h->heapSize;

    h->arr = malloc(sizeof(int) *(h->heapSize));


    printf("\nEnter array elements \n");
    for (i = 1; i <= h->heapSize; ++i)
        scanf("%d", &h->arr[i]);

    heapSort(h);

    printf("\nThe array after sorting\n");
    for (i = 1; i <= n; ++i)
        printf("%d ", h->arr[i]);
    printf("\n");

    return 0;
}

/*
 * time complexity = O(n*log n)
 * space complexity = O(logn)
 * */
