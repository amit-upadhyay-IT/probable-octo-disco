def check(n):
    cnt = 0
    while n:
        if n & 1:
            cnt += 1
        n >>= 1
    return cnt == 1


if check(643):
    print 'yes'
else:
    print 'no'

# time complexity = O(logn)
