def lis(arr):
    # initialize the LIS array which will store the length of lis upto index i
    LIS = [1]*len(arr)
    # iterate over the array
    for i in xrange(1, len(arr)):
        ind = i  # for getting the nth position
        j = i  # for iterating over while loop
        while j >= 0:
            # check if last element can be added or not
            if arr[ind] > arr[j]:
                # print 'j:', j
                print 'arr[', ind, ']:', arr[ind], '- arr[', j, ']:', arr[j],
                LIS[ind] = max(LIS[ind], 1 + LIS[j])
                print 'LIS[', ind, ']:', LIS[ind]
            # else:
            #     LIS[ind] = 1
            j -= 1
    return LIS


if __name__ == '__main__':
    print lis([2, 3, 1, 5, 12, 10, 11])
