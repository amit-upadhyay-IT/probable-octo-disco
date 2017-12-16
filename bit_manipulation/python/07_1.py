from math import floor, log


def getHigh(n):
    return 1 << int(floor(log(n, 2)+1))


print getHigh(25)


# time = O(logn)
