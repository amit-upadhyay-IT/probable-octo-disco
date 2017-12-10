/*
 * deleting the maximum element from max heap
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

    if (largest != i)
    {
        // swapping the element at largest index and root (i)
        int temp = h->arr[largest];
        h->arr[largest] = h->arr[i];
        h->arr[i] = temp;

        max_heapify(h, largest);
    }
}

int delMax(struct Heap *h)
{
    if (h->heapSize < 1)
    {
        printf("Heap underflow");
        return -1;
    }
    int max = h->arr[1];

    // swapping root node and last node
    h->arr[1] = h->arr[h->heapSize];

    h->heapSize -= 1;

    max_heapify(h, 1);

    return max;
}

void printHeap(struct Heap *h)
{
    int i;
    for (i = 1; i <= h->heapSize; ++i)
    {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct Heap *h;
    h->arr = malloc(7*sizeof(int));

    int array[] = {100, 50, 20, 1, 3, 10, 5};

    int i;
    for (i = 1; i <= 7; ++i)
    {
        h->arr[i] = array[i-1];
    }
    h->heapSize = sizeof(array)/sizeof(array[0]);

    int valRet = delMax(h);

    printf("%d  is value deleted\n", valRet);

    return 0;
}

/*
 * Time complexity = O(log n), logn time is for doing the heapify operation
 * Space complexity = O(log n), for recursion involved in heapify
 * */
