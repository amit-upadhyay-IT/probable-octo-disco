class TreeNode:

    right, left = [None, ]*2
    data = 0

    def __init__(self, data=None):
        self.data, self.right, self.left = data, None, None


def getHeight(treeNode):
    # if the tree is empty
    if treeNode is None:
        return 0

    # the leaf node has height 0
    if treeNode.left is None and treeNode.right is None:
        return 0

    return 1 + max(getHeight(treeNode.left), getHeight(treeNode.right))


def getNodesCount(treeNode):
    # if tree is empty
    if treeNode is None:
        return 0
    # if leaf then count is 1
    if treeNode.left is None and treeNode.right is None:
        return 1
    return 1 + getNodesCount(treeNode.left) + getNodesCount(treeNode.right)


if __name__ == '__main__':
    root = TreeNode(5)  # the root
    root.left = TreeNode(10)
    root.right = TreeNode(15)
    root.left.left = TreeNode(20)
    root.left.right = TreeNode(25)
    root.right.left = TreeNode(30)
    root.right.right = TreeNode(35)
    root.right.right.right = TreeNode(40)
    root.right.right.right.right = TreeNode(45)

    print 'height is ', getHeight(root)
    print 'nodes count is', getNodesCount(root)

# time complexity = O(n), you can solve the recurrence equation : T(n) = 2T(n/2)+c;
# as the complete problem is being divided into two parts and both of them needs to be solved

# space complexity = O(n), in worst case the recursion may go upto n level deep
