def ternary_search_helper(arr, left, right, key):
    if right >= left:
        # getting first partitioning index
        mid1 = left + (right - left)/3
        # getting second partitioning index
        mid2 = right - (right - left)/3

        if arr[mid1] == key:
            return mid1
        elif arr[mid2] == key:
            return mid2
        elif key < arr[mid1]:
            return ternary_search_helper(arr, left, mid1-1, key)
        elif key > arr[mid2]:
            return ternary_search_helper(arr, mid2+1, right, key)
        else:
            return ternary_search_helper(arr, mid1+1, mid2-1, key)


def ternary_search(arr, key):
    return ternary_search_helper(arr, 0, len(arr)-1, key)


if __name__ == '__main__':
    ret = ternary_search([1, 3, 4, 5, 56, 78, 7894, 56753735, 34523535345], 656646)
    if ret:
        print 'element found at index: ', ret
    else:
        print 'element not found'


# time complexity = O(log3(n))
