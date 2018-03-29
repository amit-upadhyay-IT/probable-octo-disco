def upper_bound_iterative(arr, key):
    low, high = 0, len(arr) - 1
    res = -1
    while low <= high:
        mid = low + (high-low)/2
        if key < arr[mid]:
            res = mid
            high = mid - 1
        else:
            low = mid + 1
    return res


def upper_bound_recursive_helper(arr, key, low, high, res):
    # get mid
    mid = low + (high - low)/2
    if low <= high:
        if key < arr[mid]:
            # the key might be present in first half, but I want to find
            # the next greater element of key, so I store the mid as the
            # result, I will update the result when I see find any other
            # element which is greater than key but less than arr[mid]
            res[0] = mid
            # also, I need to update the high
            upper_bound_recursive_helper(arr, key, low, mid - 1, res)
        else:
            # key is in the second half thus, here I yet don't know which
            # element might be the just greater than key as arr[mid] is
            # smaller, so the greater element would definitely come after
            # mid index, so I don't udpate result but I need to update low
            upper_bound_recursive_helper(arr, key, mid + 1, high, res)


def upper_bound_recursive(arr, key):
    res = [-1]
    upper_bound_recursive_helper(arr, key, 0, len(arr)-1, res)
    return res[0]


if __name__ == '__main__':
    arr = [2, 3, 43, 76, 145, 345, 564]
    ind = upper_bound_iterative(arr, 444)
    if ind != -1:
        print arr[ind]
    else:
        print 'no element greater than passed key is present, returned value:', ind
    print '----------------'
    ind = upper_bound_recursive(arr, 13)
    if ind != -1:
        print arr[ind]
    else:
        print 'no element greater than passed key is present, returned value:', ind
