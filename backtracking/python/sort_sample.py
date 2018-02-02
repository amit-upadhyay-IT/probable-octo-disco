import copy


def permutationStr(s, prefix, s_set):
    if len(s) == 0:
        s_set.add(prefix)
    else:
        for i in xrange(len(s)):
            permutationStr(s[0:i]+s[i+1:len(s)], prefix+s[i], s_set)


def permutationList(arr, start, s_set):
    if start == len(arr):
        s_set.add(copy.copy(arr))
    else:
        for i in xrange(start, len(arr)):
            arr[start], arr[i] = arr[i], arr[start]
            permutationList(arr, start+1, s_set)
            arr[start], arr[i] = arr[i], arr[start]


if __name__ == '__main__':
    arr = [1, 2, 3]
    s_set = set()
    permutationList(arr, 0, s_set)
    print s_set
