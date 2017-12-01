def getPairs(li, x):
    lPtr = 0
    rPtr = len(li)-1
    leftElement = -1
    while lPtr < rPtr:
        if li[lPtr] + li[rPtr] > x:
            rPtr = rPtr - 1
        elif li[lPtr] + li[rPtr] < x:
            lPtr = lPtr + 1
        else:
            print li[lPtr]
            leftElement = li[lPtr]  # returning the left element of pair
            lPtr += 1
            rPtr -= 1
    else:
        return leftElement


li = [110, 175, 317, 50, 1178, 819, 70]

li.sort()  # do the sorting in-place

print li

pair = 427

retVal = getPairs(li, pair)

if retVal != -1:
    print '(', retVal, ',', pair-retVal, ')'
else:
    print 'no pair found'
