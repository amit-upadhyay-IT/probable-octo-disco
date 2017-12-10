/*
 * insert key in heap
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

void insertIntoHeap(struct Heap* h, int key)
{
    /*
     increasing the heapsize and then inserting the element there
    */

    h->heapSize += 1;

    h->arr[h->heapSize] = key;

    int index = h->heapSize;

    while (index > 1 && h->arr[index/2] < h->arr[index])
    {
        // swapping the parent and child
        int temp = h->arr[index];
        h->arr[index] = h->arr[index/2];
        h->arr[index/2] = temp;

        index /= 2;
    }
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

    printf("\nThe heap is \n");
    printHeap(h);

    int key;
    printf("\nEnter the element you want to insert into heap\n");
    scanf("%d", &key);

    insertIntoHeap(h, key);

    printf("\nHeap after inserting element\n");
    printHeap(h);

    return 0;
}

/*
 * FOR THE INSERTION ONLY:
 * time complexity = O(log n)
 * space complexity = O(1), no recursion is involved in insertion so no count for stack size
 * */
