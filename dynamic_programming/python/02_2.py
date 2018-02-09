def msis(arr):
    # initialize the MSIS array MSIS[0] is always arr[0], as msis of first
    # element is the element itself
    MSIS = [v for v in arr]
    # iterate over array
    for i in xrange(1, len(arr)):
        ind = i
        j = i
        # iterate back to 0 from i and check if the arr[ind] can be added to
        # MSIS
        while j >= 0:
            # element can only be added if its is greater than previous element
            if arr[ind] > arr[j]:
                MSIS[ind] = max(MSIS[ind], arr[ind] + MSIS[j])
            j -= 1
    return MSIS


if __name__ == '__main__':
    ret = msis([20, 3, 1, 15, 16, 2, 12, 13])
    print ret
    print max(ret)

# time = O(n^2)
# space = O(n), for the MSIS array
