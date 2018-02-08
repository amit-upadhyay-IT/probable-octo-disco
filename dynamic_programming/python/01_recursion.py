'''
recursive program for lis
'''


# a helper function where actual recursion takes place to find the
# lis of arr with a specified length, i.e. the function below will just
# find the possible maximum lis with the specified length of array
def lis_helper(arr, last):
    # base case, i.e. when the last index goes down to 1
    # array with one element will always have lis as 1
    if last == 0:
        return 1
    else:
        # using a var to get the maximum among the possible choises
        maxi = 1
        # forming n branches and getting the maximum among them
        for i in xrange(last):
            # we need to recusively call this function only if we find
            # arr[n] > arr[n-1], otherwise we know that lis for that case
            # will be 1 (and that's why maxi is initialized with 1)
            if arr[i] < arr[last]:
                # adding one because the new element can be included in lis
                res = lis_helper(arr, last-1) + 1
                if res > maxi:
                    maxi = res
        return maxi


# returns the length of lis
def lis(arr):
    maxi = 0
    # getting all the possible lis and chosing maximum among them
    for i in xrange(len(arr)):
        res = lis_helper(arr, i)
        if res > maxi:
            maxi = res
    return maxi


if __name__ == '__main__':
    arr = [2, 3, 1, 5, 12, 10, 11]
    print lis(arr)

# time = O(n!), use dp to optimize this problem, however I solved
# this used recursion for better understanding of recursions
