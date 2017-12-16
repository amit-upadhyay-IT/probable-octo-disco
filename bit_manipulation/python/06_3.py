import math


def check(n):
    val = math.log(n, 2)

    if (1 << int(val)) == n:
        return True
    return False


if check(512):
    print 'yes'
else:
    print 'no'


# time = O(log n)
