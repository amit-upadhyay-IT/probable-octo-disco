def binary_search_helper(arr, key, first, last):
    # get middle
    mid = first + (last-first)/2
    if first <= last:
        if key == arr[mid]:
            return mid
        elif key < arr[mid]:
            # present in first half
            return binary_search_helper(arr, key, first, mid-1)
        else:
            # present in second half
            return binary_search_helper(arr, key, mid+1, last)


def binary_search(arr, key):
    return binary_search_helper(arr, key, 0, len(arr)-1)


if __name__ == '__main__':
    ret = binary_search([1, 3, 5, 7, 9, 11, 13, 15, 18, 21, 45, 66, 999], 66)
    if ret is not None:
        print 'found at index: ' + str(ret)
    else:
        print 'element not found'
