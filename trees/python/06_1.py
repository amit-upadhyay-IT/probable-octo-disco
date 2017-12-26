import bst


def compareLists(l1, l2):
    res = None
    # we need to run the loop for minimum length list
    mini = len(l1) if len(l1) < len(l2) else len(l2)
    for i in range(mini):
        if l1[i] == l2[i]:
            res = l1[i]
        else:
            break
    return res


def getLCA(root, val1, val2):
    temp = root

    l1 = list()
    l2 = list()

    if temp is None:
        return temp
    while (temp):
        l1.append(temp)

        if val1 < temp.data:
            temp = temp.left
        else:
            temp = temp.right

    temp = root
    while temp:
        l2.append(temp)

        if val2 < temp.data:
            temp = temp.left
        else:
            temp = temp.right

    print [val.data for val in l1]
    print [val.data for val in l2]
    return compareLists(l1, l2)


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
# space complexity = O(height), for storing elements in array
