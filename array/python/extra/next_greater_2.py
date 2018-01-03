def find_next_greater_elements(xs):
    ys = [-1 for x in xs]
    stack = []  # it is gonna contain index of elements we have visited in
    # input array but don't yet know the answer for it.
    for i, x in enumerate(xs):
        # I insert if I find that next element in array is greater than the
        # item indexed at the top of the stack. Also we need to remove the
        # item index from the stack because we are already done processing it
        while len(stack) > 0 and x > xs[stack[-1]]:
            ys[stack.pop()] = x

        # we would wanna add the item index in the stack because we don't know
        # the answer of the item yet(as we didn't found any greater element).
        stack.append(i)
    return ys


if __name__ == '__main__':
    inp = input('enter elements separated by ,\n')
    inp = list(inp)
    print find_next_greater_elements(inp)

# time = O(n)
# space = O(n)
