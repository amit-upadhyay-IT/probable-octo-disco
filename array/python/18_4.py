def printDoublets(arr):
    # calculate xor
    z = 0
    for val in arr:
        z = z ^ val
    # do xor with natural numbers
    for i in range(1, len(arr)-1):
        z = z ^ i

    setBitPos = z & ~(z-1)

    x = 0
    y = 0
    for val in arr:
        if val & setBitPos:
            x = x ^ val
        else:
            y = y ^ val

    for i in range(1, len(arr)-1):
        if i & setBitPos:
            x = x ^ i
        else:
            y = y ^ i

    print 'x = ', x, ' y = ', y


if __name__ == '__main__':
    inp = [1, 1, 3, 4, 2, 3]
    printDoublets(inp)


# time = O(n)
# space = O(1)
