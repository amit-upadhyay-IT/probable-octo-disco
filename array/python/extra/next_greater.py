'''
find the next greater element in array
'''


def printNextGreater(arr):
    # init a stack
    stack = list()
    # insert the first element in the stack
    stack.append(arr[0])

    # run a loop for processing next elements
    for i in range(1, len(arr)):
        # check if stack is empty or not, if not empty then process
        if len(stack) > 0:
            # check if the upcoming element is greater or not
            while arr[i] > stack[0]:
                ele = stack.pop()
                print ele, '->', arr[i]
                if len(stack) <= 0:
                    break
            else:  # arr[i] < stack top
                stack.append(arr[i])

        else:  # stack is empty n
            stack.append(arr[i])

    # elements available in stack doesn't have any greater element
    while len(stack) > 0:
        ele = stack.pop()
        print ele, '->', 'null'


if __name__ == '__main__':
    inp = input('enter elements separated by ,\n')
    inp = list(inp)
    printNextGreater(inp)
