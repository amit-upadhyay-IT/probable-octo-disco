def check(n):
    setBitCnt, cnt = 0, 0
    while n:
        if n & 1:
            setBitCnt += 1
        cnt += 1
        n = n >> 1
    if setBitCnt == 1:
        if cnt % 2 == 1:
            return True
    return False


if check(256):
    print 'yes'
else:
    print 'no'
