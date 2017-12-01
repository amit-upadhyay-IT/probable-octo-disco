'''
pair sums to x
'''


def getPairs(l, x):
    rem = 0
    for i in range(0, len(l)-1, 1):
        rem = x - l[i]
        for j in range(i, len(l)-1, 1):
            if rem == l[j]:
                print rem, ',', l[i]


li = [10, 5, 12, 14, 7, -4, 3]

getPairs(li, 17)
