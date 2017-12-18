class HeapNode:
    heapElement = -1
    heapRow = -1


class MinHeap:

    heapSize = 0
    heapList = list()  # it should be list of HeapNode

    def __init__(self, heapSize=None, heapList=None):
        self.heapSize = heapSize
        self.heapList = heapList

    def min_heapify(self, index):
        left = index*2
        right = index*2 + 1

        smallest = -1

        if left <= self.heapSize and self.heapList[left].heapElement < self.heapList[index].heapElement:
            smallest = left
        else:
            smallest = index

        if right <= self.heapSize and self.heapList[right].heapElement < self.heapList[smallest].heapElement:
            smallest = right

        if smallest != index:
            self.heapList[smallest], self.heapList[index] = self.heapList[index], self.heapList[smallest]
            self.min_heapify(smallest)

    def build_minheap(self):
        for i in range(self.heapSize/2, 0, -1):
            self.min_heapify(i)

    def print_heap(self):
        for i in range(1, self.heapSize+1, 1):
            print self.heapList[i].heapElement,

    def getMinElement(self):
        return self.heapList[1].heapElement


def constructHeap(mat, row, col):
    heapLi = ['empty']
    heapNode = HeapNode(0, 0)
    for i in range(row):
        heapNode.heapElement = mat[i][0]
        heapNode.heapRow = i
        heapLi.append(heapNode)
    minHeap = MinHeap(len(heapLi)-1, heapLi)
    return minHeap


# takes O(n/2)
def getMaximum(minHeap):
    import sys
    maxi = -sys.maxint-1
    for i in range(minHeap.heapSize/2+1, minHeap.heapSize+1):
        if minHeap.heapList[i].heapElement > maxi:
            maxi = minHeap.heapList[i].heapElement
    return maxi


def deleteMinAndGetRowNum(minHeap):
    mini = minHeap.heapList[1]
    minHeap.heapList[1] = minHeap.heapList[minHeap.heapSize]
    minHeap.heapSize -= 1
    minHeap.min_heapify(1)
    return mini


if __name__ == '__main__':
    row = input('enter number of lists')
    col = input('enter size of each list')

    mat = [[input('enter elements of list one by one:\n') for i in range(row)] for j in range(col)]
