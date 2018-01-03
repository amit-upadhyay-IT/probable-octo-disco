'''
- Initialize output array to all -1s.

- Create an empty stack of indexes of items we have visited in the input array
  but don't yet know the answer for in the output array.

- Iterate over each element in the input array:

    Is it smaller than the item indexed by the top of the stack?
        Yes. It is the first such element to be so. Fill in the corresponding
        element in our output array, remove the item from the stack, and try
        again until the stack is empty or the answer is no.

        No. Continue to 3.2.
    Add this index to the stack. Continue iteration from 3.
'''


def find_next_smaller_elements(xs):
    ys = [-1 for x in xs]
    stack = []
    for i, x in enumerate(xs):
        while len(stack) > 0 and x < xs[stack[-1]]:
            ys[stack.pop()] = x
        stack.append(i)
    return ys


if __name__ == '__main__':
    inp = input('enter elements separated by ,\n')
    inp = list(inp)
    print find_next_smaller_elements(inp)

'''
How it works

This works because whenever we add an item to the stack, we know its value is greater or equal to every element in the stack already. When we visit an element in the array, we know that if it's lower than any item in the stack, it must be lower than the last item in the stack, because the last item must be the largest. So we don't need to do any kind of search on the stack, we can just consider the last item.

Note: You can skip the initialization step so long as you add a final step to empty the stack and use each remaining index to set the corresponding output array element to -1. It's just easier in Python to initialize it to -1s when creating it.
'''
