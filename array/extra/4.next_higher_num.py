def getNextHigher(arr):
    flag = False
    pos = 0
    x = 0
    # start from right
    for i in range(len(arr)-1, 0-1, -1):
        if arr[i-1] < arr[i]:
            x = arr[i-1]
            pos = i-1
            flag = True
            break

    print 'pos = ', pos, 'x = ', x

    if not flag:
        return False

    # search for num just greater than x in right of x
    justGreater = arr[pos]
    posJustGreater = pos
    for i in range(len(arr)-1, pos, -1):
        if arr[i] > justGreater:
            justGreater = arr[i]
            posJustGreater = i
            break

    if arr[pos] == justGreater and pos == posJustGreater:
        return arr

    else:
        # swap the x and arr[posJustGreater]
        arr[pos], arr[posJustGreater] = arr[posJustGreater], arr[pos]
        # sort the elements to right of pos
        arr[pos+1:] = sorted(arr[pos+1:])
        return arr


if __name__ == '__main__':
    inp = input('enter elements separated by ,\n')
    inp = list(inp)
    ans = getNextHigher(inp)

    if ans is False:
        print 'No higher number is possible with this input\n'
    else:
        print ans


# worst case time complexity = O(nlogn), as I am sorting here
# a more optimized way can be reversing the digits and insreting x to its
# right place. Then the worst case time reduce to O(n)
