def mergeList(arr, pos, res, start, mid, end):
    temp = [0]*1000
    for i in range(start, end+1):
        temp[i] = pos[i]

    cur = start
    leftcur = start
    rightcur = mid + 1

    while leftcur <= mid and rightcur <= end:

        if arr[temp[leftcur]] <= arr[temp[rightcur]]:
            pos[cur] = temp[leftcur]
            res[pos[cur]] += rightcur - mid - 1
            leftcur += 1
            cur += 1
        else:
            pos[cur] = temp[rightcur]
            cur += 1
            rightcur += 1

    while leftcur <= mid:
        pos[cur] = temp[leftcur]
        res[pos[cur]] += end - mid
        cur += 1
        leftcur += 1

    while rightcur <= end:
        pos[cur] = temp[rightcur]
        cur += 1
        rightcur += 1


def mergeSort(arr, pos, res, start, end):
    if start < end:
        mid = (start + end)/2
        mergeSort(arr, pos, res, start, mid)
        mergeSort(arr, pos, res, mid+1, end)
        mergeList(arr, pos, res, start, mid, end)


def printResult(arr, res):
    print
    for i in range(0, len(arr)):
        print arr[i], '->', res[i]


if __name__ == '__main__':
    inp = input('enter elements separated by ,\n')
    inp = list(inp)
    res = [0]*len(inp)
    pos = [ind for ind, v in enumerate(inp)]
    mergeSort(inp, pos, res, 0, len(inp)-1)
    printResult(inp, res)
