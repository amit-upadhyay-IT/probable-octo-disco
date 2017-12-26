import bst
import Queue


def levelOrderTraversal(root):

    print '\nlevel order traversal\n'

    temp = root

    if not temp:
        return temp
    else:
        q = Queue.Queue(maxsize=0)
        q.put(temp)

        while not q.empty():
            var = q.get()
            print var.data,

            if var.left:
                q.put(var.left)
            if var.right:
                q.put(var.right)

    print


if __name__ == '__main__':
    root = None
    BSTree = bst.BST()
    inp = input('enter the elements of tree separated by ,\n')
    for i in inp:
        root = BSTree.insert(root, i)

    levelOrderTraversal(root)

# time complexity = O(n)
# space complexity = O(n), if worst case queue size may grow upto n/2 (i.e. 2^h)
