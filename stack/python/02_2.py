'''
stack with get_minimum() in constant time
'''


class Stack:
    def __init__(self, stack1=None, stack2=None, mini=0):
        self.stack1 = stack1
        self.stack2 = stack2

    def is_empty(self):
        return self.stack1 == []

    def push(self, item):
        self.stack1.append(item)  # the item needs to be inserted in stack1
        if len(self.stack2) == 0:
            self.stack2.append(item)
        # check if top of stack2 (i.e. minimum yet) is greater or equal to item
        elif self.stack2[-1] >= item:
            self.stack2.append(item)

    def pop(self):
        ret = None
        # check if top of both the stacks match or not
        if self.stack1[-1] == self.stack2[-1]:
            ret = self.stack1.pop()
            self.stack2.pop()
        else:
            ret = self.stack1.pop()
        return ret

    def peek(self):
        return self.items[len(self.items)-1]

    def size(self):
        return len(self.items)

    def get_minimum(self):
        return self.stack2[-1]


if __name__ == '__main__':
    stack = Stack(list(), list())
    stack.push(11)
    stack.push(8)
    stack.push(30)
    stack.push(8)
    stack.push(22)
    stack.push(6)

    print stack.get_minimum()  # 6
    stack.pop()
    print stack.get_minimum()  # 8
    stack.pop()
    print stack.get_minimum()  # 8
    stack.pop()
    print stack.get_minimum()  # 8
    stack.pop()
    print stack.get_minimum()  # 8
    stack.pop()
    print stack.get_minimum()  # 11


# time for push, pop and get_minimum = O(1)
# space = O(n), space for stack2
# NOTE the space can further be optimized by usign one temp variable too
