import imp

heap = imp.load_source('heap.py', './../../heap/python/heap.py')


class HuffmanNode(object):
    # main properties in a node is the character and its frequency
    def __init__(self, char=None, freq=None):
        self.char = char
        self.freq = freq


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
    temp = ['empty'] + chars_list
    min_heap = heap.MinHeap(len(temp)-1, temp)
    min_heap.build_minheap('freq')
    min_heap.print_heap('char')


if __name__ == '__main__':
    string = 'a'*50+'b'*40+'c'*5+'d'*5
    chars_list = get_char_list(string)
    construct_huffman_tree(chars_list)
