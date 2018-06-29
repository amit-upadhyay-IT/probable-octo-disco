def indent(n):
    for i in xrange(n):
        print '   '


def print_board(mat):
    for i in xrange(len(mat)):
        print mat[i]
    print '\n'


# I am filling the board column wise
def issafe(mat, row, col):
    # check in current row
    for i in xrange(row):
        if mat[row][i] == 'Q':
            return False

    # check for diagonal: \
    i, j = row, col
    while i == 0 or j == 0:
        i -= 1
        j -= 1
    while i < len(mat) and j < len(mat):
        if mat[i][j] == 'Q':
            return False
        i += 1
        j += 1

    # check for diagonal: /
    i, j = row, col
    while i == 0 or j == 0:
        i -= 1
        j += 1
    while i < len(mat) and j >= 0:
        if mat[i][j] == 'Q':
            return False
        i += 1
        j -= 1

    return True


def queen_helper(mat, col):
    indent(col)
    print 'queen_helper('+str(col)+')'
    # base case:
    if col >= len(mat):
        print_board(mat)
    else:
        for row in xrange(n):
            if issafe(mat, row, col):
                # choose
                mat[row][col] = 'Q'
                # explore
                queen_helper(mat, col+1)
                # un-choose
                mat[row][col] = '-'


def nqueen(n):
    mat = [['-' for i in xrange(n)]for j in xrange(n)]
    queen_helper(mat, 0)


if __name__ == '__main__':
    n = int(raw_input('Enter size of board:\n'))
    nqueen(n)
