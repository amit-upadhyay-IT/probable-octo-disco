# takes n^2
def getTriplest(li, x):
    for i in range(0, len(li)-1):
        sumreq = x - li[i]
        leftPtr = i+1
        rightPtr = len(li)-1

        while (leftPtr < rightPtr):
            s = li[leftPtr] + li[rightPtr]
            if s < sumreq:
                leftPtr += 1
            elif s > sumreq:
                rightPtr -= 1
            else:  # s exactly matches sumreq
                print li[i], li[leftPtr], li[rightPtr]  # printing triplets
                leftPtr += 1
                rightPtr -= 1


li = [5, 2, 9, 11, 3, 8, 17, 6]
li.sort()  # takes n*log(n)

getTriplest(li, 16)


# time is quadratic and space is constant
