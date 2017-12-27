import bst


def getLCA(root, val1, val2):

    if root is None:
        return root

    # see if we found the val1 and val2
    if root.data == val1 or root.data == val2:
        return root

    # now search left and right
    lefLca = getLCA(root.left, val1, val2)
    rigLca = getLCA(root.right, val1, val2)

    # check value returned by lef and rig
    if lefLca is not None and rigLca is not None:
        return root
    return lefLca if lefLca else rigLca


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

# time complexity = O(n)
