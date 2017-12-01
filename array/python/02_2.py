def bSearch(li, key, first_ocr):
    left, right = 0, len(li)-1
    result = -1

    while (left <= right):
        mid = left + (right - left)/2
        if li[mid] == key:  # found, check what pos user want
            if first_ocr:
                right = mid-1
            else:  # needs last occurrence
                left = mid+1
            result = mid
        elif li[mid] < key:
            left = mid+1
        else:
            right = mid-1

    return result


li = [5, 13, 13, 13, 13, 13, 17, 19, 19]

candidate = li[len(li)/2]  # this is possible ele in sorted list

firstPos = bSearch(li, candidate, True)
lastPos = bSearch(li, candidate, False)

if (firstPos == -1 or lastPos == -1):
    print 'no majority candidate found'

if lastPos - firstPos >= len(li)/2:
    print 'majority element found at ', li[len(li)/2]
else:
    print 'no majority element found'

# time is 2* logn with no extra space
