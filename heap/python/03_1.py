def getKLargest(sl, k):
    length = len(sl)
    for i in range(0, k):
        maxi = 0
        for j in range(0, length):
            if sl[j] > sl[maxi]:
                maxi = j
        print sl[maxi]
        sl[maxi], sl[length-1] = sl[length-1], sl[maxi]
        length -= 1


if __name__ == '__main__':
    sl = [10, 20, 30, 50, 100, 15]
    k = input('enter the value of k\n')
    getKLargest(sl, k)


# time = O(n*k)
# space = O(1)
