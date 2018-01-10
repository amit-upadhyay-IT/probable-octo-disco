'''
get the level of key in binary tree
'''
import bst


def getLevel(root, level, key):
    if root is None:
        return -1

    if root.data == key:
        return level
    templevel = getLevel(root.left, level+1, key)
    if templevel != -1:
        return templevel
    return getLevel(root.right, level+1, key)


if __name__ == '__main__':
    root = None
    BSTree = bst.BST()
    inp = input('enter the elements of tree separated by ,\n')
    for i in inp:
        root = BSTree.insert(root, i)

    key = input('enter key\n')

    level = 1
    lev = getLevel(root, level, key)
    if lev:
        print lev

# time = O(n)
