def getSubArray(arr, x):
    dic = dict()
    # consturct dictonary of sum, do mapping of sum to index
    su = 0
    for ind, val in enumerate(arr):
        su += val
        dic[su] = ind

    # iterate over dictonary and see of dict[i]-x is present in dict or not
    for data in dic:
        val = data - x
        if val in dic:
            firstIndex = dic.get(val)  # getting the index of firstIndex
            lastIndex = dic.get(data)  # getting the index of lastIndex

    for i in range(firstIndex+1, lastIndex+1):
        print arr[i],


if __name__ == '__main__':
    inp = input('enter elements separated by ,\n')
    inp = list(inp)
    x = input('enter value of x\n')
    getSubArray(inp, x)

# time complexity = O(n)
# space complexity = O(n)
