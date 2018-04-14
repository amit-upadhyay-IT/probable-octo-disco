# stockspan


def get_span_list(arr):
    # initializing stack and result array with the first element
    stack = [(arr[0], 0)]
    res = [0]
    # iterative over the list and performing apt operations
    for i in xrange(1, len(arr)):
        # comapre the current element with the element on top of stack
        while (arr[i] > stack[-1][0]):
            # check if stack is empty or not
            stack.pop()
            if len(stack) == 0:
                res.append(i)
                break
        else:
            res.append(i - stack[-1][1] - 1)
        # push the current element on top of stack
        stack.append((arr[i], i))
    return res


if __name__ == '__main__':
    arr = [100, 30, 10, 20, 25, 40, 26, 35, 45]
    print 'arr:', arr
    print 'sol:', get_span_list(arr)
    arr = [10, 2, 3, 15, 22, 9, 25]
    print 'arr:', arr
    print 'sol:', get_span_list(arr)


# time complexity = O(n), as each element is one time pushed and pop out from
# stack, and space is O(n) for using the stack
