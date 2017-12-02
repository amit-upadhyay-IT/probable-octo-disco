# using partition method to solve this problem


def partitionList(li):
    pivot = li[len(li)-1]
    pIndex = 0
    for eIndex in range(0, len(li)-1):
        if pivot == 0 and li[eIndex] <= pivot:
            li[eIndex], li[pIndex] = li[pIndex], li[eIndex]
            pIndex += 1
        elif pivot == 1 and li[eIndex] < pivot:
            li[eIndex], li[pIndex] = li[pIndex], li[eIndex]
            pIndex += 1
    li[pIndex], li[len(li)-1] = li[len(li)-1], li[pIndex]
    return pIndex


li = list()
e = input('enter element value, to terminate enter -1\n')

while e != -1:
    li.append(e)
    e = input('enter element, to terminate enter -1\n')

partitionList(li)

print li

# time is linear without extra space
