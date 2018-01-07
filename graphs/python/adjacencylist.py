'''
implementation of adjacency list
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


if __name__ == '__main__':
    graph = Graph(dict())
    graph.add_edge('a', 'b', 1)
    graph.add_edge('a', 'd', 1)
    graph.add_edge('b', 'a', 3)
    graph.add_edge('b', 'c', 1)
    graph.add_edge('c', 'b', 1)
    graph.add_edge('c', 'd', 5)
    graph.add_edge('d', 'c', 1)
    graph.add_edge('d', 'a', 6)

    graph.print_graph()
