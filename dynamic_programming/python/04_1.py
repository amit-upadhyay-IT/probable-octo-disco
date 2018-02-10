'''
find the largest square submatrix with all 1's
'''


def get_max_square_submatrix(mat):
    row = len(mat)
    col = len(mat[0])

    # make an auxilary array, (not actually required)
    aux = [[0 for i in range(row)] for j in range(col)]

    for i in range(len(mat)):
        for j in range(len(mat[0])):
            # initializing the first row and colums with apt values
            if i == 0 or j == 0:
                aux[i][j] = mat[i][j]
            # writing to aux when i,j is not 0
            else:
                if mat[i][j] == 0:
                    aux[i][j] = 0
                else:
                    aux[i][j] = min(aux[i-1][j-1], aux[i-1][j], aux[i][j-1]) + 1

    # find the maximum among the aux matrix
    return max(max(aux))


if __name__ == '__main__':
    mat = [
           [1, 1, 1, 1, 1],
           [0, 1, 1, 1, 1],
           [1, 1, 1, 1, 1],
           [0, 1, 1, 0, 1],
           [0, 0, 1, 1, 1]
          ]
    print get_max_square_submatrix(mat)

# time = O(n*2)
