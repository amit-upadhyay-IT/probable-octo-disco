def cntLastSet(n):
    cnt = 0
    while n:
        cnt += 1
        n >>= 1
    return cnt


def getHigh(n):
    cnt = cntLastSet(n)
    return 1 << int(cnt)


print getHigh(25)


# time = O(logn)
