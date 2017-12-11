import minheap

if __name__ == '__main__':
    samplelist = ['empty', 65, 13, 17, 18, 48, 79, 68]
    minHeap = minheap.MinHeap(len(samplelist)-1, samplelist)
    minHeap.build_minheap()
    minHeap.print_heap()
