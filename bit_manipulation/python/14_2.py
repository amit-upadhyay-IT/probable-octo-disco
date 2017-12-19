def getNextHeigher(num):
    temp = num

    # count the trailing zero and trailing ones
    c0, c1 = 0, 0

    # to count the trailing zeros
    while (temp & 1 == 0 and temp != 0):
        c0 += 1
        temp >>= 1

    # count the trailing ones
    while (temp & 1 == 1):
        c1 += 1
        temp >>= 1

    # we know that the bit where we would swap 0 to 1 would be c0 + c1
    p = c0 + c1

    # swapping the bit
    num = num | (1 << p)

    # clear all the bits right to p
    num = num & ~((1 << p) - 1)

    # put c1-1 ones to the rightmost place
    num = num | (1 << (c1-1)) - 1

    return num


def getPrevSmaller(num):
    return ~getNextHeigher(~num)


if __name__ == '__main__':
    print getNextHeigher(13948)
    print getPrevSmaller(13948)


# time complexity = O(log n)
# space complexity = O(1)
