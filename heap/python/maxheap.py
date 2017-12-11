class MaxHeap:

    heapSize = 0
    heapList = list()

    def __init__(self, heapSize=None, heapList=None):
        self.heapSize = heapSize
        self.heapList = heapList

    def max_heapify(self, index):
        left = index*2
        right = index*2 + 1

        largest = -1

        if left <= self.heapSize and self.heapList[left] > self.heapList[index]:
            largest = left
        else:
            largest = index

        if right <= self.heapSize and self.heapList[right] > self.heapList[largest]:
            largest = right

        if largest != index:
            self.heapList[largest], self.heapList[index] = self.heapList[index], self.heapList[largest]
            self.max_heapify(largest)

    def build_maxheap(self):
        for i in range(self.heapSize/2, 0, -1):
            self.max_heapify(i)

    def print_heap(self):
        for i in range(1, self.heapSize+1, 1):
            print self.heapList[i],

