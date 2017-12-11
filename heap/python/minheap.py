class MinHeap:

    heapSize = 0
    heapList = list()

    def __init__(self, heapSize=None, heapList=None):
        self.heapSize = heapSize
        self.heapList = heapList

    def min_heapify(self, index):
        left = index*2
        right = index*2 + 1

        smallest = -1

        if left <= self.heapSize and self.heapList[left] < self.heapList[index]:
            smallest = left
        else:
            smallest = index

        if right <= self.heapSize and self.heapList[right] < self.heapList[smallest]:
            smallest = right

        if smallest != index:
            self.heapList[smallest], self.heapList[index] = self.heapList[index], self.heapList[smallest]
            self.min_heapify(smallest)

    def build_minheap(self):
        for i in range(self.heapSize/2, 0, -1):
            self.min_heapify(i)

    def print_heap(self):
        for i in range(1, self.heapSize+1, 1):
            print self.heapList[i],
