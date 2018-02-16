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
    # the indexing here is starts from 1, time complexity = O(log2(n))
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

    # constructs the minheap, time complexity = O(n)
    def build_minheap(self):
        # start from the last non-leaf index and go upto 1 and heapify at
        # each step
        for i in xrange(self.heap_size/2, 0, -1):
            self.min_heapify(i)

    # returns the minimum element in the heap, time complexity = O(1)
    def get_min(self):
        return self.heap_list[1]


class MaxHeap(Heap):
    # constructor
    def __init__(self, heap_size=None, heap_list=None):
        Heap.__init__(self, heap_size, heap_list)

    # heapify the MaxHeap about the index passed as the argument
    # time complexity = O(log2(n))
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

    # constructs the MaxHeap, time complexity = O(n)
    def build_maxheap(self):
        # start from the last non-leaf and go upto 1 and at each step
        # heapify
        for i in xrange(self.heap_size/2, 0, -1):
            self.max_heapify(i)

    # returns the max from MaxHeap
    def get_max(self):
        return self.heap_list[1]

    # remove the maximum from heap and returns it
    # don't forget to check the return type while using this api
    # time complexity = O(log2(n))
    def extract_max(self):
        # store root in a var, then replace root with some element in heap
        # and heapify
        # check if heap has appropriate elements
        if self.heap_size < 1:
            print 'Heap Underflow'
            return None
        # extract maximum
        max_element = self.heap_list[1]
        # replace the root with last element in the heap
        self.heap_list[1] = self.heap_list[self.heap_size]
        # now decrease the heap_size
        self.heap_size -= 1
        # now heapify about the root
        self.max_heapify(1)
        # return element
        return max_element

    # increase the key at index passed in arg, time complexity = O(log2(n))
    def increase_key(self, index, value):
        # check if the new value is greater then the previous key present in
        # heap or not
        if value <= self.heap_list[index]:
            print 'The new value is less than element at', index,\
                ' kindly enter a greater value\n'
            return None
        # set the value at index
        self.heap_list[index] = value
        # as we have increased the value at index, so property of MaxHeap will
        # still be maintained, but check if the parent node is still MaxHeap
        # as chances are there that the increased value might be greater than
        # the parent of the node at position 'index'
        while index > 1 and self.heap_list[index/2] < self.heap_list[index]:
            # swap parent and child
            self.heap_list[index], self.heap_list[index/2] = \
                self.heap_list[index/2], self.heap_list[index]
            # change the index to index/2
            index /= 2

    # decreases the value at position 'index'
    # time complexity = O(log2(n))
    def decrease_key(self, index, value):
        # check if new value if lesser than previous value or not
        if value >= self.heap_list[index]:
            print 'The new value is greater than element at', index,\
                ' kindly enter a lesser value than', self.heap_list[index], '\n'
            return None
        # set the value at position index
        self.heap_list[index] = value
        # in this case there is not chance that the parent node will
        # get disturbed, so just call the max_heapify for the node at index i
        self.max_heapify(index)

    # insert a key in MaxHeap, time complexity = O(log2(n))
    def insert_key(self, key):
        # increase the size of heap
        self.heap_size += 1
        # put the element
        self.heap_list[self.heap_size] = key

        # get index
        index = self.heap_size

        # by the insertion the parent might get disturbed, so swap parent and
        # child if you find that parent node is smaller than the child
        while index > 1 and self.heap_list[index/2] < self.heap_list[index]:
            # swap parent and child
            self.heap_list[index/2], self.heap_list[index] = \
                self.heap_list[index], self.heap_list[index/2]
            index /= 2
