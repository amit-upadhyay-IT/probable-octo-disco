import heap
import sys

#  iterating from the beginning of leaf to end of leaf


def getMax(minHeap):
    large = -sys.maxint-1
    for i in range(minHeap.heap_size/2+1, minHeap.heap_size+1, 1):
        if minHeap.heap_list[i] > large:
            large = minHeap.heap_list[i]

    return large


if __name__ == '__main__':
    samplelist = ['empty', 65, 13, 17, 18, 48, 79, 68]
    minHeap = heap.MinHeap(len(samplelist)-1, samplelist)
    minHeap.build_minheap()
    print 'max is', getMax(minHeap)

# time complexity = O(n)
# space complexity = O(1)
