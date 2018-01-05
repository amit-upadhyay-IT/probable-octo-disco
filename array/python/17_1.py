def printDup(arr):
    for i in range(0, len(arr)):
        val = abs(arr[i])
        if arr[val] < 0:  # i.e. it's negative
            print val,
        else:  # its +ve
            arr[val] = -1 * arr[val]


if __name__ == '__main__':
    inp = [9, 6, 5, 0, 8, 2, 7, 1, 8, 5, 8, 6]
    printDup(inp)

# time = O(n) space = O(1)
