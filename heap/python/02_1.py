import minheap


def deleteTheElement(minHeap, key):
    # searching the index
    ind = -1
    for i in range(1, minHeap.heapSize+1, 1):
        if key == minHeap.heapList[i]:
            ind = i

    # now I want to replace the last element with index
    # then reduce the heapsize and again heapify
    minHeap.heapList[ind] = minHeap.heapList[minHeap.heapSize]
    minHeap.heapSize -= 1
    minHeap.min_heapify(ind)


if __name__ == '__main__':
    sampleList = list()
    inp = 'empty'
    while (inp != -1):
        sampleList.append(inp)
        inp = input('enter elements in heap, enter -1 to stop entering\n')

    dele = input('enter element value to be deleted\n')
    minHeap = minheap.MinHeap(len(sampleList)-1, sampleList)
    minHeap.build_minheap()
    deleteTheElement(minHeap, dele)
    minHeap.print_heap()

# time complexity = O(n) + O(nlogn)
