'''
diameter of tree

do a post order faishion traversal on its third visit set the diameter
maximum among the (previous diameter, leftheight+rightheight)
'''


import bst


# the class is created explicitly bcoz its object is going to be passed in arg
# to the function and this will be mutable to we can changed to our heart's
# delight and we will get the things updated in our main stack. NOTE if you
# pass a simple int as arg then it wouln't be udpated
class Diam:
    def __init__(self, diameter=None):
        self.diameter = diameter


def getDiamter(root, diam):
    if root is None:
        return 0
    leftheight = getDiamter(root.left, diam)
    rightheight = getDiamter(root.right, diam)
    diam.diameter = max(diam.diameter, leftheight+rightheight)
    print diam.diameter
    return 1+max(leftheight, rightheight)  # returning the height for the node


if __name__ == '__main__':
    root = None
    BSTree = bst.BST()
    inp = input('enter the elements of tree separated by ,\n')
    for i in inp:
        root = BSTree.insert(root, i)

    diam = Diam(0)
    getDiamter(root, diam)
    print 'diameter - ', diam.diameter

# time = O(n)
