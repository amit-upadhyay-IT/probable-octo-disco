import bst


# here I am using list as stack
# post order is performed in two parts, first part is building a stack in which
# elements are stored and second part is pop elements from stack and print them
def iterative_postorder(root):
    if not root:
        return root
    stack1 = list()
    stack2 = list()
    stack1.append(root)
    while len(stack1) != 0:
        root = stack1.pop()
        stack2.append(root)

        # first we need to insert left, coz the first inserted will be later
        # processed, thus they will appear above in the other stack and so
        # their printing will be done prior to the right ones
        if root.left is not None:
            stack1.append(root.left)
        if root.right is not None:
            stack1.append(root.right)

    # now we should print form the stack2
    while len(stack2) > 0:
        val = stack2.pop()
        print val.data,


def recursive_postorder(root):
    if root:
        recursive_postorder(root.left)
        recursive_postorder(root.right)
        print root.data,


if __name__ == '__main__':
    BSTree = bst.BST()
    root = None
    inp = input('enter tree elements separated by ,\n')
    for i in inp:
        root = BSTree.insert(root, i)

    print
    print 'iterative_postorder\n'
    iterative_postorder(root)
    print
    print 'recursive_postorder\n'
    recursive_postorder(root)

# t.c = O(n)
