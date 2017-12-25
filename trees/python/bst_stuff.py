class Node:
    data = 0
    left, right = None, None

    def __init__(self, data=None):
        self.data, self.left, self.right = data, None, None


class BST:
    root = None

    def __init__(self, root=None):
        self.root = root

    def getNewNode(self, data):
        bstNode = Node(data)
        return bstNode

    def inorder_rec(self, root):
        if root is None:
            return
        self.inorder_rec(root.left)
        print root.data
        self.inorder_rec(root.right)

    def insert(self, root, data):

        # if the current node is empty, then we need to insert right there
        if root is None:
            root = self.getNewNode(data)

        # if the data is less then root, then insert in left subtree
        elif (data < root.data):
            root.left = self.insert(root.left, data)

        # if data is greater of equal then inserting at right
        else:
            root.right = self.insert(root.right, data)

        # returning the root
        return root


if __name__ == '__main__':
    BSTree = BST()
    root = None
    inp = input('enter node data, enter -1 to stop entering\n')
    while inp != -1:
        root = BSTree.insert(root, inp)
        inp = input('enter node data, enter -1 to stop entering\n')

    BSTree.inorder_rec(root)
