def check(n):
    return not(n & (n-1))


if check(64):
    print 'yes'
else:
    print 'no'


# time complexity = O(logn)
