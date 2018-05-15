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
    return mat


def print_lcs(mat, seq1, seq2, prefix, row, col, lcs_list):
    # start from the end corner element and backtrack from where that
    # cell has been computed, if at the path we find seq1[row] == seq2[col]
    # then print that sequence
    # base case: when either row or col is 0
    if row == 0 or col == 0:
        lcs_list.append(prefix[::-1])
    else:
        # check if seq1 and seq2 chars are equal or not
        if seq1[row-1] == seq2[col-1]:
            prefix = prefix + seq1[row-1]
            print_lcs(mat, seq1, seq2, prefix, row-1, col-1, lcs_list)
        else:
            # check if both mat[row-1][col] and mat[row][col-1] are same
            if mat[row-1][col] == mat[row][col-1]:
                # form two branches
                print_lcs(mat, seq1, seq2, prefix, row-1, col, lcs_list)
                print_lcs(mat, seq1, seq2, prefix, row, col-1, lcs_list)
            else:
                # go to the cell which has max value
                if mat[row-1][col] > mat[row][col-1]:
                    print_lcs(mat, seq1, seq2, prefix, row-1, col, lcs_list)
                else:
                    print_lcs(mat, seq1, seq2, prefix, row, col-1, lcs_list)


if __name__ == '__main__':
    seq1 = raw_input('Enter sequence 1: ')
    seq2 = raw_input('Enter sequence 2: ')
    mat = lcs(seq1, seq2)
    print 'Length of LCS:', mat[len(seq1)][len(seq2)]
    lcs_list = []
    print_lcs(mat, seq1, seq2, '', len(seq1), len(seq2), lcs_list)
    print 'The LCS are:', lcs_list
# time = O(mn), space = O(mn)
