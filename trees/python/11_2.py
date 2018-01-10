import bst


class Box:
    def __init__(self, node=None, level=None):
        self.node = node
        self.level = level


def modifiedLevelOrder(root, key):

    temp = root

    if not temp:
        return temp

    q = list()
    q.append(Box(temp, 1))

    while len(q) > 0:
        var = q.pop(0)
        # val is object of Box, so get the node and level
        node = var.node
        level = var.level

        if level == key:
            print node.data,

        # we don't need to go beyond the given level
        if level > key:
            break

        if node.left:
            q.append(Box(node.left, level+1))
        if node.right:
            q.append(Box(node.right, level+1))

    print


if __name__ == '__main__':
    root = None
    BSTree = bst.BST()
    inp = input('enter the elements of tree separated by ,\n')
    for i in inp:
        root = BSTree.insert(root, i)

    key = input('enter distance from the root node\n')

    modifiedLevelOrder(root, key)

# time complexity = O(n)
# space complexity = O(n), if worst case queue size may grow upto n/2 (i.e. 2^h)
