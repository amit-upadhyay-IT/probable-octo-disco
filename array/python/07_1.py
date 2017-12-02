# get pair where sum is close to zero
import sys


def getPairs(li):
    op1, op2 = -1, -1
    minSum = sys.maxint
    for i in range(0, len(li)-1):
        for j in range(i+1, len(li)-1):
            s = li[i] + li[j]
            s = abs(s)
            if s < minSum:
                minSum = s
                op1, op2 = li[i], li[j]
    print op1, op2


getPairs([5, 7, -3, 11, -19, 14, 26])

# time is quadratic with no extra space
