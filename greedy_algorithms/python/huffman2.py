import imp

heap = imp.load_source('heap.py', './../../heap/python/heap.py')


class HuffmanNode(object):
    # main properties in a node is the character and its frequency
    def __init__(self, char=None, freq=None, left=None, right=None):
        self.char = char
        self.freq = freq
        self.left = left
        self.right = right


# returns the list of HuffmanNode
def get_char_list(string):
    # count the frequency of each character
    mapp = dict()
    for s in string:
        if s in mapp:
            val = mapp.get(s)
            val += 1
            mapp[s] = val
        # first occurrence
        else:
            mapp[s] = 1

    # get the list
    chars_list = list()

    # iterate over the mapp and construct the listof HuffmanNode
    for key in mapp:
        chars_list.append(HuffmanNode(key, mapp[key]))

    # return the chars_list
    return chars_list


def construct_huffman_tree(chars_list):
    # construct the huffman tree for prefix code
    # make a min-heap

    chars_list.sort(key=lambda x: x.freq)
    print [i.char for i in chars_list]
    print [i.freq for i in chars_list]
    # appending an extra object in beginnig coz my lib works so
    temp = ['empty'] + chars_list
    # constructing the minheap using the temp list
    min_heap = heap.MinHeap(len(temp)-1, temp)
    min_heap.build_minheap('freq')
    # now, iterate over the minheap and construct the huffman tree
    # we need to iterate n-1 times coz in each step we are merging two nodes
    # and thus at end 1 node will be left and we need to stop merging there
    # for i in xrange(1, len(temp)-1):
    min_heap.print_heap('char')
    while min_heap.get_heap_size() > 1:
        # allocate a space for a new node
        z = HuffmanNode()
        # make left child of tree node by extracting the minimum from the heap
        z.left = min_heap.extract_min()
        min_heap.print_heap('freq')
        # make the right clid
        z.right = min_heap.extract_min()
        # print 'y.char:', y.char
        # add the above two node into the heap i.e. update the frequency
        z.freq = z.left.freq + z.right.freq
        # now insert the updated z into the heap
        min_heap.insert_key(z, 'freq')

    # now there will be just one object in minheap, so return it as it will be
    # the root in the huffman tree
    print 'heap:',
    min_heap.print_heap('freq')
    return min_heap.extract_min()


def inorder(root):
    if root is not None:
        inorder(root.left)
        print root.char,
        inorder(root.right)


def preorder(root):
    if root is not None:
        print root.char,
        preorder(root.left)
        preorder(root.right)


def postorder(root):
    if root is not None:
        postorder(root.left)
        postorder(root.right)
        print root.char,


# if you don't understand below code snippet then you need to study recursion
# and backtracking
def print_code(root, prefix):
    # base case
    if root.left is None and root.right is None and root.char.isalpha():
        print root.char + ' : ' + prefix
        return
    # forming two branches, assigning left child to 0 and right child to 1
    print_code(root.left, prefix+'0')
    print_code(root.right, prefix+'1')


if __name__ == '__main__':
    string = 'a'*45+'b'*13+'c'*12+'d'*16+'e'*9+'f'*5
    chars_list = get_char_list(string)
    root_node = construct_huffman_tree(chars_list)
    print 'amit:', root_node.freq
    inorder(root_node)
    print
    preorder(root_node)
    print
    postorder(root_node)
    print
    print_code(root_node, '')
