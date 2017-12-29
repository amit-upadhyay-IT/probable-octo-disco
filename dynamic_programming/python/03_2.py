def getLongestConsecutiveSubSequence(arr):

    mapper = dict()
    # mapping the array in dict
    for val in arr:
        mapper[val] = True

    # again iterating over arr and finding the consecutive subsequence
    maxlen = 0

    for val in arr:
        if mapper[val] is True:
            mapper[val] = 'Processed'
            cntLeft = 0  # keeping track of beginning num in consecutive run
            temp = val
            temp -= 1
            # fist I need to search in left
            # make sure you take care for keyerror
            while temp in mapper and mapper[temp] is True:
                cntLeft += 1
                mapper[temp] = 'Processed'  # it's dynamically typed
                temp -= 1

            cntRight = 0
            temp = val
            temp += 1
            # searching in right
            while temp in mapper and mapper[temp] is True:
                cntRight += 1
                mapper[temp] = 'Processed'
                temp += 1

            if cntLeft + cntRight + 1 > maxlen:
                maxlen = cntLeft + cntRight + 1

    return maxlen


if __name__ == '__main__':
    inp = input('enter the array, separated by comma\n')
    inp = list(inp)  # converting from tupple to list, coz tupple is immutable
    print getLongestConsecutiveSubSequence(inp)

# time = O(n) + O(2n)
# space = O(n)
