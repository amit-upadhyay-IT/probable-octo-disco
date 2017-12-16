def getBin(n):
    num = n
    tempList = list()
    while (num != 0):
        if len(tempList) > 32:
            return 'Error'
        num = num * 2
        tempList.append(int(num))
        num = num - int(num)
        # print int(num)

    tempList[::-1]
    return ''.join(str(i) for i in tempList)


print '.'+getBin(0.60)
