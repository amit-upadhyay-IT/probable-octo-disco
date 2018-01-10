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
        print root.data,
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

    def getMin(self, root):
        if not root:
            return root  # None will be returned
        temp = root
        while temp.left:
            temp = temp.left
        return temp

    def remove(self, root, data):
        # searching is the first task

        # if empty tree
        if root is None:
            return root

        # if data is less
        if data < root.data:
            root.left = self.remove(root.left, data)
        # is data is greater
        elif data > root.data:
            root.right = self.remove(root.right, data)

        # if both the above condition doesn't match then
        # definitely we have found element
        else:
            # here we can have three different cases, case 1: leaf node found
            if not root.left and not root.right:
                # here we don't have to explicitly remove the memory pointed
                # by root, because python is smart enough to take care of that
                root = None

            # case 2: has one child
            elif root.right is None:
                root = root.left
            elif root.left is None:
                root = root.right

            # case 3: has both child
            else:
                inorderSuccessor = self.getMin(root.right)
                root.data = inorderSuccessor.data
                root.right = self.remove(root.right, inorderSuccessor.data)

        return root

    def get_inorder_successor(self, root, node):
        # step 1, if node is having right child i.e. successor will be min
        # in right tree
        if node.right is not None:
            return self.getMin(node.right)

        # the node doesn't have any right child, so we come from the root
        # and see where the last left turn takes in order to reach to
        # the 'node'
        successor = None

        while (root is not None):

            if node.data < root.data:
                successor = root  # successor is still at function scope
                root = root.left
            elif node.data > root.data:
                root = root.right
            else:
                break
        return successor

    def search_using_data(self, root, data):
        if not root:
            return root
        if root.data < data:
            return self.search_using_data(root.right, data)
        elif data < root.data:
            return self.search_using_data(root.left, data)
        else:
            return root
