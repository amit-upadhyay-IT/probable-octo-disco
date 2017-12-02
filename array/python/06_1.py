# counting sort approach for solving problem


def getCntList(li):
    cntList = [0] * 2
    for i in li:
        cntList[i] += 1
    return cntList


def printTransformedList(li):
    zeroCnt = li[0]
    oneCnt = li[1]
    for i in range(zeroCnt):
        print 0

    for i in range(oneCnt):
        print 1


printTransformedList(getCntList([1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0]))

# time complexity: O(n) space is also constant because we just need a list
# with two elemental size
