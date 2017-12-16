def cntSetBit(n):
    cnt = 0
    while n != 0:
        if n & 1:
            cnt += 1
        n = n >> 1
    return cnt


print cntSetBit(124)
