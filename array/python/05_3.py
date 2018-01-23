# number occurring odd  times

li = [1, 2, 3, 5, 4, 6, 8, 1, 2, 3, 5, 6, 8]


def getOddOccurred(li):
    res = 0
    for i in li:
        res = res ^ i

    return res


print getOddOccurred(li)
