class Node(object):
    def __init__(self, data=None, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right


def level_order(root):
    # check if root is null or not
    if root is None:
        return None
    # create a queue
    queue = list()
    queue.append(root)
    cnt = 1  # cnt will help in knowing the level in the tree
    while (len(queue) != 0):
        cnt += 1
        temp = queue.pop(0)  # taking out from the first index
        print '('+str(temp.data)+')',
        if cnt == 0 or (cnt and not (cnt & (cnt-1))):
            print  # printing the new line on each new level in tree
        # pushing the left child
        if temp.left is not None:  # adding the left child if present
            queue.append(temp.left)
        if temp.right is not None:  # adding the right child if present
            queue.append(temp.right)


if __name__ == '__main__':
    root = Node(2)
    root.left = Node(1)
    root.right = Node(3)
    root.left.left = Node(0)
    root.left.right = Node(7)
    root.right.left = Node(9)
    root.right.right = Node(1)

    level_order(root)
