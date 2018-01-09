import bst


def post_order_traversal(root):
    if root is None:
        return root

    stack = list()
    current = root
    while current is not None or len(stack) > 0:
        if current is not None:
            stack.append(current)
            current = current.left
        else:  # current is none
            # see if parent(top in stack) has right child or not
            temp = stack[len(stack)-1].right
            if temp is None:
                # i.e. left and right are processed, so print parent
                temp = stack.pop()
                print temp.data,
                # see if the poped node is the right child of parent or not
                # if right child then we know that its time to print parent
                while len(stack) > 0 and temp == stack[len(stack)-1].right:
                    temp = stack.pop()
                    print temp.data,

            else:
                current = temp


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
    print 'post_order_traversal\n'
    post_order_traversal(root)
    print
    print 'recursive_postorder\n'
    recursive_postorder(root)

# t.c = O(n)
# we can also find the height of the tree by checking maximum height of stack
