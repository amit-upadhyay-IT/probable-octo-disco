import bst


def checkElementPresence(root, val1, val2):
    temp = root
    found1 = False
    while (temp):
        if val1 < temp.data:
            temp = temp.left
        elif val1 > temp.data:
            temp = temp.right
        else:
            found1 = True
            break
    temp = root
    found2 = False
    while (temp):
        if val2 < temp.data:
            temp = temp.left
        elif val2 > temp.data:
            temp = temp.right
        else:
            found2 = True
            break

    return found1 and found2


def getLCA(root, val1, val2):
    res = None
    while root is not None:
        if val1 < root.data and val2 < root.data:
            root = root.left
        elif val1 > root.data and val2 > root.data:
            root = root.right
        else:
            if checkElementPresence(root, val1, val2):
                res = root
            else:
                res = None
            break
    return res


def getLCA_rec(root, val1, val2):
    if root is not None:
        if val1 < root.data and val2 < root.data:
            return getLCA_rec(root.left, val1, val2)
        elif val1 > root.data and val2 > root.data:
            return getLCA_rec(root.right, val1, val2)
        else:
            return root


if __name__ == '__main__':
    root = None
    BSTree = bst.BST()
    inp = input('enter the elements of tree separated by ,\n')
    for i in inp:
        root = BSTree.insert(root, i)

    inp = raw_input('enter two value whose LCA you want? separated by ","\n')
    val1 = int(inp.split(',')[0])
    val2 = int(inp.split(',')[1])
    lca = getLCA(root, val1, val2)

    if lca:
        print 'the lca is ', lca.data, '\n'
    else:
        print 'no lca found\n'


# time complexity = O(height), in worst case the height may go upto n,
# the complexity for iterative lca is O(height) + O(height), because there
# I am taking care of the fact the elements entered (whose lca is to be found)
# might not be present in the binary tree, in that case desired output is
# different then output coming.
# the recursive lca function is assuming that the elements being queried are
# present in the tree

# space complexity = O(height), for recursion stack
