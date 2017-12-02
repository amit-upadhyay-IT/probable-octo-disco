def getequlib(li):
    sum = 0
    elementSum = 0
    for i in li:
        sum = sum + i
    for element in li:
        sum = sum - element
        if sum == elementSum:
            return li.index(element)
        elementSum += element
    return -1


val = getequlib([15, 3, 9, 2, 1, 18, 8])

if val != -1:
    print val, 'is the equilibrium index'
else:
    print 'no equilibrium index'
