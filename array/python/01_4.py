def getPairs(li, x):
    myDic = dict()
    for i in li:
        remVal = x - i
        if i in myDic:
            print remVal, ',', i
        myDic[remVal] = True


li = [110, 175, 317, 50, 1178, 819, 70]

getPairs(li, 427)

# time is linear
