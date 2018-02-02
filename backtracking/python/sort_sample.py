def permutationStr(s, prefix, s_set):
    if len(s) == 0:
        s_set.add(prefix)
    else:
        for i in xrange(len(s)):
            permutationStr(s[0:i]+s[i+1:len(s)], prefix+s[i], s_set)


def permutationList(arr, start, s_set):
    flag = True
    # check if arr is in increasing order or not
    for i in xrange(0, len(arr)-1):
        if arr[i] > arr[i+1]:
            flag = False
    # check if the start has become equals to length of arr or not
    if flag is True and start == len(arr):
        print arr
    else:
        for i in xrange(start, len(arr)):
            arr[start], arr[i] = arr[i], arr[start]
            permutationList(arr, start+1, s_set)
            arr[start], arr[i] = arr[i], arr[start]


if __name__ == '__main__':
    arr = [10, 1, 5, 3]
    s_set = set()
    permutationList(arr, 0, s_set)
