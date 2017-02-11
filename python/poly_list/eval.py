#!/usr/bin/python
l = [-13.39, 17.5, 3.0, 1.0]

x = input("Enter x : ")

def evalTheVal(x):
    k, s = 0, 0
    for i in l:
        s = s + i*(x**k)
        k += 1
    return s

print evalTheVal(x)
