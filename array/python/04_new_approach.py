li = [4, 3, 10, 2, 9, 1, 6]


def makeMinCntArray(li):
    mini = [None]*len(li)
    mini[0] = li[0]
    minimum = li[0]
    for i in range(1, len(li)-1, 1):
        if li[i] < mini[i-1]:
            minimum = li[i]
        mini[i] = minimum
    return mini


def getDiff(li):
    maxDif = 0
    d = makeMinCntArray(li)
    # iterating from last index
    for i in range(len(li)-1, 1, -1):
        dif = li[i] - d[i-1]
        if dif > maxDif:
            maxDif = dif

    return maxDif


theMaxDif = getDiff(li)

print theMaxDif

# time and extra space using are both linear
