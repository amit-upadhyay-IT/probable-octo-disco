# number occurring odd  times

li = [1, 2, 3, 5, 4, 6, 8, 1, 2, 3, 5, 6, 7, 8]

def getOddOccurred(li):
    res = li[0]
    for i in range(0, len(li)):
        res ^= li[i]

    return li
