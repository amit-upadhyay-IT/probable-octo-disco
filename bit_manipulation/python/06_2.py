def check(n):
    return n and not(n & (n-1))


if check(64):
    print 'yes'
else:
    print 'no'


# time complexity = O(logn)
