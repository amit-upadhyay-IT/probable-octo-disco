#!/usr/bin/pytho
row = input("Enter number of rows: ")
cols = input("Enter number of columns: ")
a = [[input("Enter element : ") for i in range(row)] for j in range(cols)]
for i in range(row):
    print a[i]
