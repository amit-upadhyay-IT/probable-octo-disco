import bst

'''
if you observe, you will find out that we just need to swap left and right
child of each node in the tree and thus to implement this we can use recursion
easily.

So for every node we just need to swap the left sub tree and right sub tree.
Thus, we can the function recursively with left sub tree and right sub tree
and as we reach to the leaf node(or last but leaf node), we can swap their
child (i.e. two null pointer), then that recursion stack will get destroyed
then their parent node's children will get swapped
'''


'''
this method isn't returning the root, because the root has been passed as
reference (actually by value, where the value passed is reference itself)
Also, note that I am not rebinding the object here
'''


def getMirrorTree(root):
    if not root:
        return
    getMirrorTree(root.left)
    getMirrorTree(root.right)
    root.left, root.right = root.right, root.left


if __name__ == '__main__':
    root = None
    BSTree = bst.BST()
    inp = input('enter the elements of tree separated by ,\n')
    for i in inp:
        root = BSTree.insert(root, i)

    print 'inorder traversal of original tree\n'
    BSTree.inorder_rec(root)
    print

    getMirrorTree(root)

    print
    print 'inorder traversal of mirror tree\n'
    BSTree.inorder_rec(root)

# time complexity = O(n)
