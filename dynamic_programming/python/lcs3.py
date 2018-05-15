# lcs: dp approach


def lcs(seq1, seq2):
    len1 = len(seq1)
    len2 = len(seq2)
    # create a matrix of len1+1 * len2+1
    mat = [[None for row in xrange(len2+1)]for col in xrange(len1+1)]
    # the cells in the mat represents the subproblems
    # iterate over cells in matrix and compute the sub problems
    for i in xrange(len1+1):
        for j in xrange(len2+1):
            if i == 0 or j == 0:
                mat[i][j] = 0
            # check if seq1 and seq2 chars matches or not
            elif seq1[i-1] == seq2[j-1]:
                mat[i][j] = 1 + mat[i-1][j-1]
            else:
                mat[i][j] = max(mat[i-1][j], mat[i][j-1])
    # the final problem is calcualated and stored at cell len1+1, len2+1
    # so return it
    return mat[len1][len2]


if __name__ == '__main__':
    seq1 = raw_input('Enter sequence 1: ')
    seq2 = raw_input('Enter sequence 2: ')
    print lcs(seq1, seq2)

# time = O(mn), space = O(mn)
