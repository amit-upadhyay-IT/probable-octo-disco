# since lists are mutable is reference passed by copy
def mergeLists(arr, temp, left, mid, right):
    i, j, k = left, mid, left  # starting the k with left coz I'll use it to
    # init auxilary array
    while i <= mid - 1 and j <= right:
        if arr[i] < arr[j]:
            temp[k] = arr[i]
            i += 1
            k += 1
        else:
            temp[k] = arr[j]
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


def mergeSort(arr, temp, first, last):

    if first < last:

        mid = (first + last)/2
        # in this approach lets not create two lists of size mid

        mergeSort(arr, temp, first, mid)
        mergeSort(arr, temp, mid+1, last)
        mergeLists(arr, temp, first, mid+1, last)


if __name__ == '__main__':
    inp = input('enter elements separated by , \n')
    inp = list(inp)
    temp = [0]*len(inp)
    mergeSort(inp, temp, 0, len(inp)-1)
    print temp

# time = O(nlogn)
# space = O(n)
