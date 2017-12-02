def getMaxWindow(li, k):
    for i in range(0, len(li)-2, 1):
        maxi = li[i]
        for j in range(i, i+k):
            if li[j] > maxi:
                maxi = li[j]
        print maxi


getMaxWindow([1, 2, 3, 1, 4, 5, 2, 3, 6], 3)


# time is O(n*k), n is list size, space is constant
