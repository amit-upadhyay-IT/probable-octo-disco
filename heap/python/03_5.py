import minheap


def getKLargest(minHeap, sampleList, k):
    for i in range(k, len(sampleList), 1):
        if minHeap.heapList[1] < sampleList[i]:
            minHeap.heapList[1] = sampleList[i]
            minHeap.min_heapify(1)

    minHeap.print_heap()


if __name__ == '__main__':
    sampleList = [10, 20, 30, 50, 100, 15]
    k = input('enter the value of k\n')
    heapList = ['empty']
    for i in range(0, k, 1):
        heapList.append(sampleList[i])
    minHeap = minheap.MinHeap(len(heapList)-1, heapList)
    minHeap.build_minheap()
    getKLargest(minHeap, sampleList, k)

# time complexity = O(k)+O((n-k)*logk), or you can also say: O(k)+O(nlogk)
# sapce complexity = O(k), if we use the same array for building the heap,
# then the space complexity would become O(1), in my case I have made a
# new heap because I don't want to change my custom module of minheap
