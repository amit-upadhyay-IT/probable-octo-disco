# rat maze: prints all possible paths
def indent(n):
    for i in xrange(n):
        print '   ',


def solve_maze_helper(mat, n, prefix, row, col, ind):
    # indent(ind)
    # print 'indent('+str(n)+','+str(prefix)+','+str(row)+','+str(col)+')'
    # base case: when row or col reaches to n-1
    if row == n-1 or col == n-1:
        # print 'second case'
        if (row == n-2 and col == n-1) or (row == n-1 and col == n-2):
            # print '[0, 0]', prefix, '[' + str(n-1) + ', ' + str(n-1) + ']'
            print prefix
        return
    else:
        # check if rat can go to right side
        if mat[row][col+1] == 1:
            # explore the branch
            prefix.append([row, col+1])  # choose
            solve_maze_helper(mat, n, prefix, row, col+1, ind+1)  # explore
            prefix.pop()  # un-choose

        if mat[row+1][col] == 1:
            prefix.append([row+1, col])  # choose
            solve_maze_helper(mat, n, prefix, row+1, col, ind+1)  # explore
            prefix.pop()  # un-choose


def solve_maze(mat):
    solve_maze_helper(mat, len(mat), list(), 0, 0, 0)


if __name__ == '__main__':
    n = int(raw_input('Enter n:\n'))
    mat = [[int(raw_input('Enter element value at (' + str(j) + ',' + str(i) + '): ')) for i in xrange(n)] for j in xrange(n)]
    print 'maze is :\n'
    print mat
    print '\n'
    solve_maze(mat)

# NOTE: ask for more optimizations if possible
