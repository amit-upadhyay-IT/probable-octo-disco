'''
implementation of head as a abstract ds
'''


# parent class for MinHeap and MaxHeap, here the common utifity functions
# are implemented
class Heap(object):
    # property of heap: a) heap_size and b) heap_list
    def __init__(self, heap_size=None, heap_list=None):
        self.heap_size = heap_size
        self.heap_list = heap_list

    # print the heap indexed from 1 to n
    def print_heap(self):
        for i in xrange(1, self.heap_size + 1):
            print self.heap_list[i]


class MinHeap(Heap):
    # constuctor for MinHeap, it should call the parent constructor
    def __init__(self, heap_size=None, heap_list=None):
        Heap.__init__(self, heap_size, heap_list)

    # heapify the MinHeap on the index passed as the arg
    # the indexing here is starts from 1
    def min_heapify(self, i):
        # step1: get the smallest among the left child, right child and root
        # step2: if root is not the smallest among three then swap appropriately

        # get left index
        left = i * 2
        # get right index
        right = i * 2 + 1

        # init the smallest var
        smallest = -1

        # check if left is greater than root, also check the boundary of left
        if left <= self.heap_size and self.heap_list[left] < self.heap_list[i]:
            smallest = left
        else:
            smallest = i

        # check if right is smallerst or not, also check the boundary of right
        if right <= self.heap_size and self.heap_list[right] < \
                self.heap_list[smallest]:
            smallest = right

        # step 2: if smallest is not the one at root, then you need to swap
        if smallest != i:
            self.heap_list[smallest], self.heap_list[i] = \
                self.heap_list[i], self.heap_list[smallest]
            # after this swap there may be disordering somewhere in child
            # so again calling heapify over the smallest index
            self.min_heapify(smallest)

    # constructs the minheap
    def build_minheap(self):
        # start from the last non-leaf index and go upto 1 and heapify at
        # each step
        for i in xrange(self.heap_size/2, 0, -1):
            self.min_heapify(i)

    # returns the minimum element in the heap
    def get_min(self):
        return self.heap_list[1]


class MaxHeap(Heap):
    # constructor
    def __init__(self, heap_size=None, heap_list=None):
        Heap.__init__(self, heap_size, heap_list)

    # heapify the MaxHeap about the index passed as the argument
    def max_heapify(self, i):
        # step1: get the largest among left child, right child and root
        # step2: is largest is not the root, then swap and heapify for largest

        # get left index
        left = 2 * i
        # get right index
        right = 2 * i + 1

        # init the largest
        largest = -1

        # check the boundary for left also check if its greater or not
        if left <= self.heap_size and self.heap_list[left] > self.heap_list[i]:
            largest = left
        else:
            largest = i

        # check the boundary for right also see if its greater than prev largest
        if right <= self.heap_size and \
                self.heap_list[right] > self.heap_list[largest]:
            largest = right

        # step2: if root is not largest then you need to swap
        if largest != i:
            self.heap_li[largest], self.heap_li[i] = \
                self.heap_list[i], self.heap_list[largest]
            # there may be disordering in the child somewhere, so check them
            self.max_heapify(largest)

    # constructs the MaxHeap
    def build_maxheap(self):
        # start from the last non-leaf and go upto 1 and at each step
        # heapify
        for i in xrange(self.heap_size/2, 0, -1):
            self.max_heapify(i)

    # returns the max from MaxHeap
    def get_max(self):
        return self.heap_list[1]
