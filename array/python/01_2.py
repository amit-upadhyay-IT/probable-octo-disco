def bSearch(li, key, fI, lI):
    if fI >= lI:
        return -1
    mid = (fI + lI) / 2
    if li[mid] == key:
        return mid  # element returned
    elif li[mid] > key:
        bSearch(li, key, fI, mid-1)
    else:
        bSearch(li, key, mid+1, lI)


li = [10, 65, 103, 111, 150, 263, 336]

retVal = bSearch(li, 111, 0, len(li)-1)


if retVal != -1:
    print li[retVal], 'found in', li
