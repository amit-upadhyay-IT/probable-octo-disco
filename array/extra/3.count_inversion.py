'''
we have to modify the merge sort in the way that the main mergeSort function
should return the inversion count. Reason I want it this function to return
the inversion count is that in the end the total inversion count will be
inversion count in left subarray + inversion count in right subarray +
inversion count in merging process.

NOTE that the case when inversion occurs is arr[i] > arr[j] and i < j
'''


def mergeList(res, list1, list2):
    invCnt = 0
    i, j = 0, 0
    k = 0
    while i < len(list1) and j < len(list2):
        if list1[i] < list2[j]:
            res[k] = list1[i]
            i += 1
            k += 1
        else:  # list1[i] > list2[j] and i < j (not actually, but as far as the
            # elements are considered to be in original array), we can say that
            # the index of element in list1 would be less than that of list2
            invCnt += len(list1) - i
            res[k] = list2[j]
            j += 1
            k += 1

    while i < len(list1):
        res[k] = list1[i]
        i += 1
        k += 1

    while j < len(list2):
        res[k] = list2[j]
        j += 1
        k += 1

    return invCnt


def mergeSort(arr):
    invCount = 0
    if len(arr) < 2:
        return 0
    else:
        mid = len(arr)/2
        invCount += mergeSort(arr[:mid])
        invCount += mergeSort(arr[mid:])
        invCount += mergeList(arr, arr[:mid], arr[mid:])
    return invCount


if __name__ == '__main__':
    inp = input('enter elements separated by , \n')
    inp = list(inp)
    print mergeSort(inp)


# time = O(nlogn)
# space = O(n), as used for merge sort
