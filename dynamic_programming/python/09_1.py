def getMinimumEditDistance(word1, word2):

    # creating a 2d matrix
    mat = [[0 for i in range(len(word1)+1)] for j in range(len(word2)+1)]

    for i in range(len(word1)+1):
        for j in range(len(word2)+1):
            # filling out the first row
            if i == 0:
                mat[i][j] = j
            # filling out the first column
            elif j == 0:
                mat[i][j] = i

            # if found that element at row and column are same, then copy diag.
            elif word1[i-1] == word2[j-1]:
                mat[i][j] = mat[i-1][j-1]

            else:
                mat[i][j] = 1 + min(mat[i][j-1], mat[i-1][j], mat[i-1][j-1])

    return mat[len(word1)][len(word2)]


if __name__ == '__main__':
    word1 = raw_input('enter word 1\n')
    word2 = raw_input('enter word 2\n')
    print getMinimumEditDistance(word1, word2)

# time = O(m*n)
# space = O(m*n)
