import bst


# here I am using list as stack
def iterative_preorder(root):
    if not root:
        return root
    stack = list()
    stack.append(root)
    while len(stack) != 0:
        node = stack.pop()
        print node.data,
        # first we should insert right, coz stack is lifo
        if node.right is not None:
            stack.append(node.right)
        if node.left is not None:
            stack.append(node.left)
    # else executes when while ends
    else:
        print


def recursive_preorder(root):
    if root:
        print root.data,
        recursive_preorder(root.left)
        recursive_preorder(root.right)


if __name__ == '__main__':
    BSTree = bst.BST()
    root = None
    inp = input('enter tree elements separated by ,')
    for i in inp:
        root = BSTree.insert(root, i)

    print 'iterative_preorder\n'
    iterative_preorder(root)
    print 'recursive_preorder\n'
    recursive_preorder(root)
