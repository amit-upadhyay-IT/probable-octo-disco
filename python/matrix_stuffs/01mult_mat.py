#!/usr/bin/python
import random

row1 = input("Enter rows for matrix 1 : ")
col1 = input("Enter columns for matrix 1: ")

row2 = input("Enter rows for matrix 2 : ")
col2 = input("Enter columns for matrix 2 : ")

def checkIfMultiplicable():
    global row1, row2, col1, col2
    # the number of cols in A must be equal to number of rows in B
    return col1 == row2

def inputElements():
    a = [[random.randint(1, 20) for i in range(row1)] for j in range(col1)]
    b = [[random.randint(1, 20) for i in range(row2)] for j in range(col2)]

    print "Enter elements of matrix 1: \n"
    for i in range(row1):
        for j in range(col1):
            a[i][j] = input("Enter element : ")

    print "Enter elements of matrix 2 : \n"
    for i in range(row2):
        for j in range(col2):
            b[i][j] = input("Enter element : ")
    return [a, b]

def multiplyMatrices(a, b):
    c = [[random.randint(1, 20) for i in range(row1)] for j in range(col2)]

    for i in range(row1):
        for j in range(col2):
            c[i][j] = 0
            for k in range(row1):
                c[i][j] += a[i][k] * b[k][j]
    return c

def printMat(matrix, row, col):
    for i in range(row):
        for j in range(col):
            print matrix[i][j],
        print

val = checkIfMultiplicable()
if not val:
    print "can't multiply"
    quit()
inputed_list = inputElements()
mat1 = inputed_list[0]
mat2 = inputed_list[1]

resultant_mat = multiplyMatrices(mat1, mat2)
printMat(resultant_mat, row1, col2)
