# since lists are mutable is reference passed by copy
def mergeLists(res, list1, list2):
    i, j, k = 0, 0, 0
    while (i < len(list1) and j < len(list2)):
        if list1[i] < list2[j]:
            res[k] = list1[i]
            i += 1
        else:
            res[k] = list2[j]
            j += 1
        k += 1

    while i < len(list1):
        res[k] = list1[i]
        i += 1
        k += 1

    while j < len(list2):
        res[k] = list2[j]
        k += 1
        j += 1


def mergeSort(arr):

    if len(arr) < 2:
        return

    mid = len(arr)/2
    # create left array
    left = arr[:mid]  # note that we are using slicing so it wouldn't be same
    right = arr[mid:]

    mergeSort(left)
    mergeSort(right)
    mergeLists(arr, left, right)


if __name__ == '__main__':
    inp = input('enter elements separated by , \n')
    inp = list(inp)
    mergeSort(inp)
    print inp

# time = O(nlogn)
# space = O(n)
