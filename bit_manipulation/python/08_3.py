def check(n):
    while (n % 4 == 0):
        n >>= 2
    if n == 1:
        return True
    return False


if check(1024):
    print 'yes'
else:
    print 'no'


# time = O(log4(n))
