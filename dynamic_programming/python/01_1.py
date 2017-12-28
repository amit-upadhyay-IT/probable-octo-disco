def getMax(arr):
    print arr
    from sys import maxint
    maxi = -maxint-1
    for val in arr:
        if val > maxi:
            maxi = val
    return maxi


def getLISlength(arr):

    # the first element in the arr will always have 1 as the LIS, and rest of
    # elements will atleast be 1, so initializing them with 1

    lis = [1, ]*len(arr)

    for i in range(1, len(arr)):
        for j in range(0, i):
            if arr[i] > arr[j] and lis[i] < lis[j] + 1:
                lis[i] = lis[j] + 1

    # returning the maximum among the LIS array
    return getMax(lis)


if __name__ == '__main__':
    arr = [2, 3, 1, 5, 12, 10, 11]
    print getLISlength(arr)

# time complexity = O(n^2)
