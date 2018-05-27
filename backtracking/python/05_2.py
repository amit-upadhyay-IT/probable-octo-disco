# rat maze: prints all possible paths
def indent(n):
    for i in xrange(n):
        print '   ',


def solve_maze_helper(mat, n, prefix, row, col, ind):
    # indent(ind)
    # print 'indent('+str(n)+','+str(prefix)+','+str(row)+','+str(col)+')'
    # base case: when row or col reaches to the desinations left or top
    if (row == n-2 and col == n-1) or (row == n-1 and col == n-2):
        print 'Answer: ', prefix
    else:
        # check if rat can go to right side
        if (row < n and col+1 < n) and mat[row][col+1] == 1:
            # explore the branch
            prefix.append([row, col+1])  # choose
            solve_maze_helper(mat, n, prefix, row, col+1, ind+1)  # explore
            prefix.pop()  # un-choose

        if (row+1 < n and col < n) and mat[row+1][col] == 1:
            prefix.append([row+1, col])  # choose
            solve_maze_helper(mat, n, prefix, row+1, col, ind+1)  # explore
            prefix.pop()  # un-choose


def solve_maze(mat):
    solve_maze_helper(mat, len(mat), list(), 0, 0, 0)


def solve_maze_one_sol_helper(mat, n, prefix, row, col, ind):
    # indent(ind)
    # print 'indent('+str(n)+','+str(prefix)+','+str(row)+','+str(col)+')'
    # base case: when row or col reaches to the desinations left or top
    if (row == n-2 and col == n-1) or (row == n-1 and col == n-2):
        prefix.insert(0, [0, 0])
        prefix.append([n-1, n-1])
        print 'Answer: ', prefix
        prefix.pop(0)
        return True
    else:
        # check if rat can go to right side
        if (row < n and col+1 < n) and mat[row][col+1] == 1:
            # explore the branch
            prefix.append([row, col+1])  # choose
            finished = solve_maze_one_sol_helper(mat, n, prefix, row, col+1, ind+1)  # explore
            if finished is True:
                return True
            prefix.pop()  # un-choose

        if (row+1 < n and col < n) and mat[row+1][col] == 1:
            prefix.append([row+1, col])  # choose
            finished = solve_maze_one_sol_helper(mat, n, prefix, row+1, col, ind+1)  # explore
            if finished is True:
                return True
            prefix.pop()  # un-choose
    return False


def solve_maze_one_sol(mat):
    solve_maze_one_sol_helper(mat, len(mat), list(), 0, 0, 0)


if __name__ == '__main__':
    n = int(raw_input('Enter n:\n'))
    mat = [[int(raw_input('Enter element value at (' + str(j) + ',' + str(i) + '): ')) for i in xrange(n)] for j in xrange(n)]
    print 'maze is :\n'
    print mat
    print '\n'
    solve_maze(mat)
    print '-----JUST ONE SOLUTION------'
    solve_maze_one_sol(mat)

# NOTE: ask for more optimizations if possible

'''
TEST CASE:
    1 1 0 1
    0 1 1 0
    1 1 1 1
    0 1 1 1
'''
