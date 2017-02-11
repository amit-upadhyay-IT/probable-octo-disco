#!/usr/bin/python
m = 0; n = 0

def inputElements():
    actuallist = []
    global m, n
    m = input("Enter the number of rows : ")
    n = input("Enter the number of columns : ")
    k = 0
    for i in range(m):
        for j in range(n):
            actuallist.append(input("Enter element "+ str(k+1)+" : "))
            k += 1
    return actuallist


def prinitElements(actuallist):
    global m, n
    k = 0
    for i in range(m):
        for j in range(n):
            print actuallist[k],
            k += 1
        print

actuallist = inputElements()
prinitElements(actuallist)
