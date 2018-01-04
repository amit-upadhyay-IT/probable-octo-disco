'''
we have to modify the merge sort in the way that the main mergeSort function
should return the inversion count. Reason I want it this function to return
the inversion count is that in the end the total inversion count will be
inversion count in left subarray + inversion count in right subarray +
inversion count in merging process.

NOTE that the case when inversion occurs is arr[i] > arr[j] and i < j
'''


# since lists are mutable is reference passed by copy
def mergeLists(arr, temp, left, mid, right):
    invCount = 0
    i, j, k = left, mid, left  # starting the k with left coz I'll use it to
    # init auxilary array
    while i <= mid - 1 and j <= right:
        if arr[i] <= arr[j]:
            temp[k] = arr[i]
            i += 1
            k += 1
        else:  # list1[i] > list2[j] and i < j
            temp[k] = arr[j]
            invCount += mid - i
            j += 1
            k += 1

    while i <= mid-1:
        temp[k] = arr[i]
        i += 1
        k += 1

    while j <= right:
        temp[k] = arr[j]
        j += 1
        k += 1

    for ind in range(left, right+1):
        arr[ind] = temp[ind]

    return invCount


def mergeSort(arr, temp, first, last):

    invCount = 0

    if first < last:

        mid = (first + last)/2

        invCount += mergeSort(arr, temp, first, mid)
        invCount += mergeSort(arr, temp, mid+1, last)
        invCount += mergeLists(arr, temp, first, mid+1, last)

    return invCount


if __name__ == '__main__':
    inp = input('enter elements separated by , \n')
    inp = list(inp)
    temp = [0]*len(inp)  # creating aux list for merging purpose
    invCount = mergeSort(inp, temp, 0, len(inp)-1)
    print invCount

# time = O(nlogn)
# space = O(n)
