'''
disjoint set implementation using union by rank and path compression

Ask question for it perfect design on stackexchange review
'''


class Node:

    data, parent, rank = None, None, None

    def __init__(self, data=None, rank=None):
        self.data = data
        self.rank = rank

    def set_parent(self, parent):
        self.parent = parent


class DisjointSet:

    # the node_map does the mapping of data to the node reference
    def __init__(self, node_map=None):
        self.node_map = node_map

    # create a new node, fill data into it, make it point to itself, set rank-0
    def create_set(self, data):
        node = Node(data, 0)  # passing the data and the rank
        node.set_parent(node)
        self.node_map[data] = node  # data to node mapping in the dictionary

    # returns True if union is performed sucessfully otherwise returns False
    def union(self, data1, data2):
        node1 = self.node_map.get(data1)
        node2 = self.node_map.get(data2)

        parent1 = self.find_set_main(node1)
        parent2 = self.find_set_main(node2)

        # check if they are part of same set or not
        if parent1.data == parent2.data:
            return False  # indicate that there is no union possible

        # the node with higher rank should become the final parent
        if parent1.rank >= parent2.rank:
            # if rank of both the node are same then increment the final rank
            parent1.rank = 1 + parent1.rank if parent1.rank == parent2.rank \
                    else parent1.rank
            # set the parent of node2 as parent1
            parent2.parent = parent1
        else:
            parent1.parent = parent2
        return True

    # the function itself calls another function to find the representative
    def find_set(self, data):
        return self.find_set_main(self.node_map.get(data)).data

    # returns the representative node, does the path compression recursively
    def find_set_main(self, node):
        parent = node.parent
        if parent == node:  # checking if we reached the parent or not
            return parent
        node.parent = self.find_set_main(node.parent)
        return node.parent


if __name__ == '__main__':
    disjoint = DisjointSet(dict())
    disjoint.create_set(10)
    disjoint.create_set(20)
    disjoint.create_set(30)
    disjoint.create_set(40)
    disjoint.create_set(60)
    disjoint.create_set(70)
    disjoint.create_set(80)
    disjoint.create_set(90)
    disjoint.create_set(150)

    disjoint.union(10, 20)
    disjoint.union(20, 30)
    disjoint.union(30, 60)

    print disjoint.find_set(20)
    print disjoint.find_set(10)
    print disjoint.find_set(30)
    print disjoint.find_set(60)

    print disjoint.find_set(150)

    disjoint.union(150, 10)
    print disjoint.find_set(150)

# all three operations take constant time in amortized analysis
