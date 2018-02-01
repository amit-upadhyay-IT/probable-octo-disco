# It is the representation of each vertex in the graph
class Node:
    # a node in graph is likely to have vertex, weight. Also, node_address ptr
    # is not required as I am gonna use in-built list
    def __init__(self, vertex=None, weight=None, next_node=None):
        self.vertex = vertex
        self.weight = weight


# a parent class for the different types of Graphs, this class is created
# to reuse the code snippets like print_graph, bfs and dfs, etc
class Gr(object):
    # In adjacency list representative I would need a mapper to map the node
    # value with the list representing the adjacency list (i.e. adjacent nodes)
    # so I use a dictionary to create data to list mapping
    def __init__(self, node_dic=None):
        self.node_dic = node_dic

    # printing the adjacency list
    def print_graph(self):
        for key in self.node_dic:
            # get the list
            lis = self.node_dic[key]
            print key, '->', [str(i.vertex)+':'+str(i.weight) for i in lis]


# directed graph
class DiGraph(Gr):

    def __init__(self, node_dic=None):
        # calling the parent class constructor
        Gr.__init__(self, node_dic)
        # using a set to keep the count of vertices in graph
        self.vertices_set = set()

    # this method adds the edge b/w src node to dest node with specified weight
    def add_edge(self, src, dest, weight):
        # check if src is present in node_dic or not
        if src in self.node_dic:
            # since it's present so get the list from map
            lis = self.node_dic.get(src)
            # now add the destination in the list for node src
            lis.append(Node(dest, weight))
        else:
            # as the src wasn't present in dictionary, so add it
            self.node_dic[src] = [Node(dest, weight)]
        # why do I need to use extra memory for set to keep the count of
        # vertices in graph?
        # as in directed graph, we can have nodes with some indegree but zero
        # out-degree, so for that case we don't create an entry in node_dic
        # thus we miss out that vertex in the count, so I use a set here
        self.vertices_set.add(src)
        self.vertices_set.add(dest)

    def vertices_count(self):
        return len(self.vertices_set)

    # prints the elements in topological sorted manner
    # modified dft method
    def topological_sort(self):
        # init a stack
        stack = list()
        # make visited dict
        visited = dict()
        # init visited with vertices_set
        for v in self.vertices_set:
            visited[v] = False
        # iterate throught the vertices
        for v in self.node_dic:
            if visited[v] is False:
                self.modified_dfs_for_top_sort(v, visited, stack)

        # pop from stack and print (i.e. print from end)
        for ind in xrange(len(stack)-1, -1, -1):
            print stack[ind],

    def modified_dfs_for_top_sort(self, v, visited, stack):
        visited[v] = True
        if v in self.node_dic:
            a_list = [i.vertex for i in self.node_dic.get(v)]
            for w in a_list:
                if w in visited and visited[w] is False:
                    self.modified_dfs_for_top_sort(w, visited, stack)
        stack.append(v)


'''
    v2    v5
      \  /
       v1
      /  \
    v3    v4
      \  /
       v6
'''


if __name__ == '__main__':

    digraph = DiGraph(dict())
    # agrs: src, dest, weight
    digraph.add_edge('v2', 'v1', 1)
    digraph.add_edge('v5', 'v1', 1)
    digraph.add_edge('v1', 'v3', 1)
    digraph.add_edge('v1', 'v4', 1)
    digraph.add_edge('v3', 'v6', 1)
    digraph.add_edge('v4', 'v6', 1)
    digraph.add_edge('v4', 'v3', 1)

    digraph.print_graph()
    digraph.topological_sort()
