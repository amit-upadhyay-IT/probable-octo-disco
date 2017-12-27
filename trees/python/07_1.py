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


def findPath(root, val, li):
    if root is None:
        return False

    li.append(root)

    if root.data == val:
        return True

    if root.left and findPath(root.left, val, li) or\
            root.right and findPath(root.right, val, li):
        return True

    li.pop()
    return False


def getLCA(root, val1, val2):
    list1, list2 = list(), list()
    if not findPath(root, val1, list1) or not findPath(root, val2, list2):
        return False

    return compareLists(list1, list2)


'''
def getLCA(root, val1, val2):
    # we shall do a preorder traversal and form two lists
    stack = list()
    list1, list2 = list(), list()
    if not root:
        return root
    temp = root
    stack.append(temp)
    while (len(stack) != 0):
        temp = stack.pop()
        list1.append(temp)
        if temp.data == val1:
            break

        if temp.right:
            stack.append(temp.right)
        if temp.left:
            stack.append(temp.left)

    temp = root
    stack2 = list()
    stack2.append(temp)
    while (len(stack2) != 0):
        temp = stack2.pop()
        list2.append(temp)
        if temp.data == val2:
            break
        if temp.right:
            stack2.append(temp.right)
        if temp.left:
            stack2.append(temp.left)

    print [val.data for val in list1]
    print [val.data for val in list2]
    return compareLists(list1, list2)
'''

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
