class HeapNode:
    heapElement = -1
    heapRow = -1
    heapCol = -1

    def __init__(self, heapElement, heapRow, heapCol):
        self.heapElement = heapElement
        self.heapRow = heapRow
        self.heapCol = heapCol


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
        heapNode = HeapNode(mat[i][0], i, 0)
        heapLi.append(heapNode)
    minHeap = MinHeap(len(heapLi)-1, heapLi)
    return minHeap


def insertIntoHeap(minHeap, element, row, col):
    minHeap.heapSize = minHeap.heapSize + 1
    minHeap.heapList[minHeap.heapSize] = HeapNode(element, row, col)
    ind = minHeap.heapSize
    while (minHeap.heapList[ind].heapElement < minHeap.heapList[ind/2].heapElement):
        minHeap.heapList[ind], minHeap.heapList[ind/2] = minHeap.heapList[ind/2], minHeap.heapList[ind]
        ind /= 2


# takes O(n/2)
def getMaximum(minHeap):
    import sys
    maxi = -sys.maxint-1
    for i in range(minHeap.heapSize/2+1, minHeap.heapSize+1):
        if minHeap.heapList[i].heapElement > maxi:
            maxi = minHeap.heapList[i].heapElement
    return maxi


def deleteMinAndGetRowNum(minHeap):
    miniElementRow = minHeap.heapList[1].heapRow
    minHeap.heapList[1] = minHeap.heapList[minHeap.heapSize]
    minHeap.heapSize -= 1
    minHeap.min_heapify(1)
    return miniElementRow


if __name__ == '__main__':
    row = input('enter number of lists')
    col = input('enter size of each list')

    mat = [[input('enter elements of list one by one:\n') for i in range(row)] for j in range(col)]

    miniHeap = constructHeap(mat, row, col)

    res_range = 100000
    while (True):
        minimumEle = miniHeap.getMinElement()
        maximumEle = getMaximum(miniHeap)
        curr_range = maximumEle - minimumEle
        if curr_range < res_range:
            res_range = curr_range

        ind = deleteMinAndGetRowNum(miniHeap)









