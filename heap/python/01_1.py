import minheap
import sys

#  iterating from the beginning of leaf to end of leaf


def getMax(minHeap):
    large = -sys.maxint-1
    for i in range(minHeap.heapSize/2+1, minHeap.heapSize+1, 1):
        if minHeap.heapList[i] > large:
            large = minHeap.heapList[i]

    return large


if __name__ == '__main__':
    samplelist = ['empty', 65, 13, 17, 18, 48, 79, 68]
    minHeap = minheap.MinHeap(len(samplelist)-1, samplelist)
    minHeap.build_minheap()
    print 'max is', getMax(minHeap)

# time complexity = O(n)
# space complexity = O(1)
