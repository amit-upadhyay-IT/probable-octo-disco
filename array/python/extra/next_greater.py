'''
find the next greater element in array
'''


def printNextGreater(arr):
    # init a stack
    stack = list()
    # insert the first element in the stack
    stack.append(arr[0])

    for i in range(1, len(arr)):

        if len(stack) > 0:

            nextEle = arr[i]
            topEle = stack[len(stack)-1]
            stack.pop()

            while topEle < nextEle:
                print topEle, '->', nextEle
                if len(stack) == 0:
                    break
                topEle = stack[len(stack)-1]
                stack.pop()
            # else:
            #     print nextEle
            #     stack.append(nextEle)

            if topEle > nextEle:
                stack.append(topEle)

        stack.append(arr[i])

    while (len(stack) > 0):
        print stack.pop(), '-> null'


if __name__ == '__main__':
    inp = input('enter elements separated by ,\n')
    inp = list(inp)
    printNextGreater(inp)

# time complexity = O(n)
# space complexity = O(n), for stack

# NOTE: I don't think this problem of finding the next greater element in array
# can be solved using BST in nlogn time. Problem like finding the next minimum
# element in array or find the smallest element to right can perhaps be solved
# using the BST in nlogn time
