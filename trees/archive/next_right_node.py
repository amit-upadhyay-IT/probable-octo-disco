'''
find the next right node of given key
'''
import bst


class Box:
    def __init__(self, node=None, level=None):
        self.node = node
        self.level = level


def printNextRight(root, element):
    # I will do kindda level order traversal
    if root is None:
        return root

    q = list()
    q.append(Box(root, 1))  # indicates that root is at level 1

    while len(q) > 0:
        var = q.pop(0)
        node = var.node
        level = var.level
        if node.data == element:
            # deququeing another element from queue and checking if its level is
            # same as the previous one
            # also check if it's the last element in the queue or no
            if len(q) != 0:
                next_pop = q.pop(0)
                if next_pop.level == level:
                    print next_pop.node.data
                else:
                    print 'no next right to', element
            else:
                print 'No right element to it'
            # found the element so we should now break
            break
        if node.left:
            q.append(Box(node.left, level+1))
        if node.right:
            q.append(Box(node.right, level+1))


if __name__ == '__main__':
    root = None
    BSTree = bst.BST()
    inp = input('enter the elements of tree separated by ,\n')
    for i in inp:
        root = BSTree.insert(root, i)

    element = input('enter node value whose right you wanna print\n')

    printNextRight(root, element)

# time complexity = O(2^element level), in worst case it can be linear
# space = O(element level), for the queue
