import bst


# here I am using list as stack

'''
the idea here is about printing the left most node first, i.e. we can store the
root.left node in the stack until we are finding the root.left in not None.Then
the last node which got inserted needs to be printed, so we just need a pop for
that. Next we can print the parent of the poped element(as that would be on top
). Then we should insert the right ones
'''


def iterative_inorder(root):
    if not root:
        return root
    stack = list()
    temp = root
    while True:
        if temp is not None:
            stack.append(temp)
            temp = temp.left
        else:
            if len(stack) > 0:
                temp = stack.pop()
                print temp.data,
                temp = temp.right
            else:
                break


def recursive_inorder(root):
    if root:
        recursive_inorder(root.left)
        print root.data,
        recursive_inorder(root.right)


if __name__ == '__main__':
    BSTree = bst.BST()
    root = None
    inp = input('enter tree elements separated by ,\n')
    for i in inp:
        root = BSTree.insert(root, i)

    print
    print 'iterative_inorder\n'
    iterative_inorder(root)
    print
    print 'recursive_inorder\n'
    recursive_inorder(root)

# t.c = O(n)
