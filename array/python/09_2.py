def getEquilibriubIndex(li):
    leftList = getLeftSumList(li)
    rightList = getRightSumList(li)
    for i in range(len(leftList)-2):
        if leftList[i] == rightList[i+1]:
            print 'equilibrium at index', i


def getLeftSumList(li):
    leftSum = list()
    s = 0
    for element in li:
        s = s + element
        leftSum.append(s)
    return leftSum


def getRightSumList(li):
    rightSum = list()
    s = 0
    for i in li[::-1]:
        s = s + i
        rightSum.append(s)

    li[::-1]  # again reversing the list, so that it doesn't affect original
    return rightSum


getEquilibriubIndex([10, 5, 15, 3, 4, 21, 2])
