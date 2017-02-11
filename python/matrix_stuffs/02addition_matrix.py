#!/usr/bin/python
row = input("Enter rows: ")
col = input("Enter columns: ")

mat1 = [input("Enter element of 1st matrix : ") for i in range(row) for j in range(col)]
mat2 = [input("Enter element of 2nd matrix : ") for i in range(row) for j in range(col)]

resultant_mat = [mat1[i] + mat2[i] for i in xrange(len(mat1))]
k = 0
for i in range(row):
    for j in range(col):
        print resultant_mat[k],
        k += 1
    print
