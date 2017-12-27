import bst


# the solution in my view can be made by focusing on the fact that a single
# leaf node can be considered as a DLL, then using it as basic building block
# for constructing the lest part of the problem
def constructDLL(root):
    # I want to first get the DLL from LST
    if root.left:
        lstDLL = constructDLL(root.left)
        # now we wanna reach to the tail of the DLL, so we go to extreme right
        # in other words we can also say that we're finding inorder predecessor
        # (but only if we consider the tree as BST)
        while lstDLL.right:
            lstDLL = lstDLL.right
        # also we need to store the head as the right pointer of the lstDLL, so
        lstDLL.right = root  # root is the head, so we make it point to root
        root.left = lstDLL  # since, this is DLL, so we need both pointer to
        # point at each other

    if root.right:
        rstDLL = constructDLL(root.right)
        # in this case we need to go the extreme left
        while rstDLL.left:
            rstDLL = rstDLL.left
        # this time we don;t have to store the root (i.e. head ptr), rather we
        # need to store the tail into the left pointer which is storing head
        rstDLL.left = root  # root is the tail in this case
        root.right = rstDLL

    return root


def printDLL(head):
    temp = head
    while temp:
        print temp.data,
        temp = temp.right


if __name__ == '__main__':
    root = None
    BSTree = bst.BST()
    inp = input('enter the elements of tree separated by ,\n')
    for i in inp:
        root = BSTree.insert(root, i)

    root = constructDLL(root)

    while root.left is not None:
        root = root.left

    printDLL(root)
