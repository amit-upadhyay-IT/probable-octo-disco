'''
print nodes at k distance from the root

the question means we have to print all the nodes at level k

we can use any traversal technique and maintain the level count and print and
return from there

or we can also use level order tarversal to acheive this task
'''
import bst


def printNodesAtK(root, dist, k):  # k-distance that we want to be from the root
    # dist keeps track of the current distance traveled fromt the root in prog

    if root is None:
        return

    if dist == k:
        print root.data
        return  # returning is important coz I don't wanna make more recursions
    printNodesAtK(root.left, dist+1, k)
    printNodesAtK(root.right, dist+1, k)


if __name__ == '__main__':
    root = None
    BSTree = bst.BST()
    inp = input('enter the elements of tree separated by ,\n')
    for i in inp:
        root = BSTree.insert(root, i)

    key = input('enter distance from the root\n')

    dist = 0
    printNodesAtK(root, dist, key)


# time = number of nodes visited, i.e. 2^k where k is distance given
# why? coz - 1+2+4+8+2^k-1 = 2^k, in worst case it is same as O(n)
