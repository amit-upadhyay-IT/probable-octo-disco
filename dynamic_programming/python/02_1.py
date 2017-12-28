def getMSIS(arr):
    msis = [0]*len(arr)
    # it's obvious that the first element would be msis up that index
    msis[0] = arr[0]

    for i in range(1, len(arr)):
        for j in range(0, i):
            if arr[i] > arr[j] and msis[i] < msis[j] + arr[i]:
                msis[i] = msis[j] + arr[i]
    return max(msis)


if __name__ == '__main__':
    inp = input('enter values separated by ,\n')
    inp = list(inp)
    print getMSIS(inp)
