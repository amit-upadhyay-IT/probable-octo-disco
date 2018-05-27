import bst


if __name__ == '__main__':
    BSTree = bst.BST()
    root = None
    inp = input('enter node data, comma separated\n')
    for i in inp:
        root = BSTree.insert(root, i)

    print 'the inorder traversal is\n'
    BSTree.inorder_rec(root)
    print

    val = input('enter node value which you want to delete\n')
    BSTree.remove(root, val)

    print
    print 'inorder after deleting ', val, '\n'
    BSTree.inorder_rec(root)

    print
    inp = input('enter the node whose inorder successor you want\n')
    inpNode = BSTree.search_using_data(root, inp)
    suc = BSTree.get_inorder_successor(root, inpNode)
    print
    print 'inorder successor of ', inp, 'is ', suc.data, '\n'


# working test case:
# 50, 40, 70, 30, 45, 65, 90, 10, 35, 42, 48, 60, 68, 80, 55, 69
