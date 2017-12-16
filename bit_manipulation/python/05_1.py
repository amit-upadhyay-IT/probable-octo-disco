def cntSetBit(n):
    cnt = 0
    while (n != 0):
        if n % 2:
            cnt += 1
        n /= 2
    return cnt


print cntSetBit(124)
