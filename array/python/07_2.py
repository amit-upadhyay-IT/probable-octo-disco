import sys


def getPair(li):
    minisum = sys.maxint
    e1, e2 = -1, -1
    leftPtr, rightPtr = 0, len(li)-1
    while (leftPtr < rightPtr):
        s = li[leftPtr] + li[rightPtr]
        if s < 0:
            if abs(s) < minisum:
                minisum = abs(s)
                e1, e2 = li[leftPtr], li[rightPtr]
            leftPtr += 1
        elif s > 0:
            if abs(s) < minisum:
                minisum = abs(s)
                e1, e2 = li[leftPtr], li[rightPtr]
            rightPtr -= 1
        else:  # found exactly zero
            print li[leftPtr], li[rightPtr]
            leftPtr += 1
            rightPtr += 1

    print e1, e2


li = [5, 7, -3, 11, -19, 14, 26]

li.sort()

getPair(li)


# time is n*log(n) with no extra space
