def bSearch(li, key, fI, lI):
    if fI > lI:
        return -1
    mid = (fI + lI) / 2
    if li[mid] == key:
        return mid  # element returned
    elif li[mid] > key:
        return bSearch(li, key, fI, mid-1)
    else:
        return bSearch(li, key, mid+1, lI)


li = [10, 65, 103, 111, 150, 263, 336]


def getPair(li, x):
    for i in range(0, len(li)-1, 1):
        remVal = x - li[i]
        retVal = bSearch(li, remVal, i+1, len(li)-1)
        if retVal != -1:
            print '(', li[retVal], ',', li[i], ')'


getPair(li, 214)
