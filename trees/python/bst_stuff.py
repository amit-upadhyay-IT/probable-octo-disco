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

        # if both the above condition doesn't match then definitely we have found element
        else:
            # here we can have three different cases, case 1: leaf node found
            if not root.left and not root.right:
                # here we don't have to explicitly remove the memory pointed by root, because python is smart enough to take care of that
                root = None

            # case 2: has one child
            elif root.left:
                root = root.left
            elif root.right:
                root = root.right

            # case 3: has both child
            else:
                inorderSuccessor = self.getMin(root)
                root.data = inorderSuccessor.data
                root.right = self.remove(root.right, inorderSuccessor.data)

        return root


if __name__ == '__main__':
    BSTree = BST()
    root = None
    inp = input('enter node data, comma separated\n')
    print inp
    for i in inp:
        root = BSTree.insert(root, i)

    print 'the inorder traversal is\n'
    BSTree.inorder_rec(root)

    val = input('enter node value which you want to delete\n')
    BSTree.remove(root, val)

    print 'inorder after deleting ', val, '\n'
    BSTree.inorder_rec(root)
