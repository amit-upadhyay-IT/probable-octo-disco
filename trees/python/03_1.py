import bst

'''
if you try to solve the problem on paper, you would find the repetition
in the process, i.e. we are building the left subtree and right subtree
using the inorder and postorder list but the elements in the lists are
shrinking (because the subtree elements are just part of the lists given)
So this can be solved easily using recursion

The main function here is construct_tree
'''


def getRootElement(inorder, postorder, start, end):
    # running first loop from end
    for pval in postorder[::-1]:
        for iind in range(start, end+1, 1):
            if pval == inorder[iind]:
                return pval

    return -1  # probably signifies that the inorder & postorder are incorrect


def getElementIndex(inorder, val, start, end):
    for i in range(start, end+1):
        if val == inorder[i]:
            return i  # returning the index

    return -1


def construct_tree(inorder, postorder, start, end):
    # we need to get the root posision
    root = getRootElement(inorder, postorder, start, end)
    rootIndex = getElementIndex(inorder, root, start, end)

    temp = None

    if root != -1:
        temp = bst.Node()  # its left and right are initialized to None
        temp.data = root

        if start >= end:
            return temp

        temp.left = construct_tree(inorder, postorder, start, rootIndex-1)
        temp.right = construct_tree(inorder, postorder, rootIndex+1, end)

    return temp


if __name__ == '__main__':
    root = None
    BSTree = bst.BST()
    inorder = input('enter inorder, separated by comma\n')
    postorder = input('enter postorder, separated by comma\n')

    if len(inorder) != len(postorder):
        print 'wrong input'
        import sys
        sys.exit()

    root = construct_tree(inorder, postorder, 0, len(inorder)-1)

    print 'inorder printing of the formed tree\n'
    BSTree.inorder_rec(root)

# time complexity = O(n^2)
# One test case example: inorder - 8, 4, 2, 5, 1, 6, 3, 7
# postorder - 8, 4, 5, 2, 6, 7, 3, 1
