'''
implementation of adjacency list

NOTE: I think this is not a good design, because design is using self made
linked list, which is making the code quite complex in the traversals and search
'''
from __future__ import print_function


class Node:

    # the identity of a node is vertex, weight and next_node address
    def __init__(self, v, w, next_node=None):
        self.v = v
        self.w = w
        self.next_node = next_node


class LinkedList:

    # head is refering to the top node in the LinkedList, head is the identity
    def __init__(self, head=None):
        self.head = head

    # add_node is same as insertion at beginning
    def add_node(self, vertex, weight):
        new_node = Node(vertex, weight)
        new_node.next_node = self.head  # setting the head to newly formed node
        self.head = new_node

    def print_linkedlist(self):
        temp = self.head
        while temp is not None:
            print ('[', temp.v, '->', temp.w, ']', end='')
            temp = temp.next_node
        print('\n')


# a directed graph
class Graph:

    VISITED = dict()  # used for getting state of a vertex(it is used in search

    # nodeDic is a dictionary where we map the node value to adjacency list
    # the dictionary is the only identity of the graph
    def __init__(self, nodeDic=None):
        self.nodeDic = nodeDic

    def add_edge(self, src, dest, weight):
        # check if nodeDic alreday has src as key
        if src in self.nodeDic:
            # the source node already exists so append the dest node in list
            linked_list = self.nodeDic.get(src)
            linked_list.add_node(dest, weight)
        else:
            # there is no such source node in graph present so create new
            self.nodeDic[src] = LinkedList(Node(dest, weight))

    def print_graph(self):
        for key in self.nodeDic:
            # from __future__ import print_function
            val = self.nodeDic[key]
            print (key, ':', end='')
            val.print_linkedlist()

    def setVisitedArray(self):
        # note that this method shouldn't be called before initializing nodeDic
        self.VISITED = [False]*len(self.nodeDic)

    def bfs(self, v):  # v is vertex from where we should start search
        u = v  # copying the vertex address
        self.VISITED[u] = True
        queue = list()
        queue.append(u)
        print (u)

        while True:

            node_list = self.nodeDic.get(u).head
            while node_list:
                data = node_list.v  # getting the vertex
                if data not in self.VISITED or self.VISITED[data] is False:
                    queue.append(data)  # will insert at end
                    self.VISITED[data] = True
                    print(data)
                node_list = node_list.next_node

            if len(queue) == 0:
                break
            else:
                u = queue.pop(0)  # popping the first inserted node


if __name__ == '__main__':
    graph = Graph(dict())

    inp = input('enter source and destination with their weight\n, \
    enter -1, -1, -1 to stop entering\n')
    inp = list(inp)
    while inp[0] is not -1:
        graph.add_edge(inp[0], inp[1], inp[2])
        inp = input('enter source and destination with their weight\n, \
        enter -1, -1, -1 to stop entering\n')
        inp = list(inp)

    v = input('enter node from where you want to start search\n')

    # graph.setVisitedArray()
    graph.bfs(v)

    # graph.print_graph()
