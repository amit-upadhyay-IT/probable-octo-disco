'''
recursive program for lis
'''


def lis_helper(arr, last):
    # base case, i.e. when the last index goes down to 1
    # array with one element will always have lis as 1
    if last == 0:
        return 1
    else:
        r = 1
        # form n-1 branches
        for i in xrange(last):
            if arr[i] < arr[last]:
                res = lis_helper(arr, last-1) + 1
                if res > r:
                    r = res
        return r


def lis(arr):
    res = 0
    maxi = 0
    for i in xrange(len(arr)):
        res = lis_helper(arr, i)
        if res > maxi:
            maxi = res
    return maxi


if __name__ == '__main__':
    arr = [2, 3, 1, 5, 12, 10, 11]
    print lis(arr)
