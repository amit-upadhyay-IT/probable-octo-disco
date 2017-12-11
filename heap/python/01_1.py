import maxheap

if __name__ == '__main__':
    sampleList = ['empty', 1, 5, 6, 8, 12, 14, 16]
    maxHeap = maxheap.MaxHeap(len(sampleList)-1, sampleList)
    maxHeap.build_maxheap()
    maxHeap.print_heap()
