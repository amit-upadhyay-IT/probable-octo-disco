#!/usr/bin/python
m = 0; n = 0
def inputElements(actuallist):
    global m, n
    m = input("Enter the number of rows : ")
    n = input("Enter the number of columns : ")
    k = 1 # used just to display count to user
    for i in range(m):
        innerlist = []
        for j in range(n):
            innerlist.append(int(input("input element "+ str(k) + " : ")))
            k += 1
        actuallist.append(innerlist)
    #return actuallist
def prinitElements(actuallist):
    global m, n
    for i in range(m):
        for j in range(n):
            print (actuallist[i][j]),
        print
actuallist = []
inputElements(actuallist)
prinitElements(actuallist)
