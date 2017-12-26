import bst


def getLCA(root, val1, val2):
    while root is not None:
        if val1 < root.data and val2 < root.data:
            root = root.left
        elif val1 > root.data and val2 > root.data:
            root = root.right
        else:
            break
    return root


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


# time complexity = O(height), in worst case the height may go upto n
# space complexity = O(height), for recursion stack
