import bst


def check_identical(root1, root2):
    # if both roots are null
    if not root1 and not root2:
        return True
    # if one of the root is null
    elif not root1:
        return False
    elif not root2:
        return False
    # now, none of the root is null, so check data, left & right tree
    else:
        if root1.data == root2.data:
            return check_identical(root1.left, root2.left) \
                and check_identical(root1.right, root2.right)
        else:
            return False


if __name__ == '__main__':
    root1 = None
    BSTree = bst.BST()
    inp = input('enter the elements for 1st bst separated by ,\n')
    for i in inp:
        root1 = BSTree.insert(root1, i)

    root2 = None
    inp = input('enter the elements for 2st bst separated by ,\n')
    for i in inp:
        root2 = BSTree.insert(root2, i)

    print
    if check_identical(root1, root2):
        print 'trees are identical'
    else:
        print 'trees aren\'t identical'
