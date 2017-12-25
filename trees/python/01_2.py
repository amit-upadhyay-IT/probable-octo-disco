import bst


def getSize(root):
    # size is number of nodes
    if not root:
        return 0
    # if leaf
    if not root.left and not root.right:
        return 1
    else:
        return 1 + getSize(root.left) + getSize(root.right)


if __name__ == '__main__':
    root = None
    BSTree = bst.BST()
    inp = input('enter the elements of bst separated by ,\n')
    for i in inp:
        root = BSTree.insert(root, i)

    BSTree.inorder_rec(root)

    print '\n\n'
    print 'size of tree is', getSize(root)
