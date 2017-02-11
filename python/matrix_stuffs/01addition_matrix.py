#!/usr/bin/python
row = input("Enter rows: ")
col = input("Enter columns: ")

mat1 = [[input("Enter element of 1st matrix : ") for i in range(row)] for j in range(col)]
mat2 = [[input("Enter element of 2nd matrix : ") for i in range(row)] for j in range(col)]

resultant_mat = []

for i in range(row):
    temp_mat = []
    for j in range(col):
        x = mat1[i][j] + mat2[i][j]
        temp_mat.append(x)
    resultant_mat.append(temp_mat)

for i in xrange(row):
    print resultant_mat[i]
