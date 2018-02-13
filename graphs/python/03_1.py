'''
from 2d binary array find the number of island
'''


# count the 1's in the island
def count_houses(mat, visited, i, j):
    # base case
    if i < 0 or i >= len(mat) or j < 0 or j >= len(mat[0]) or\
            visited[i][j] is True or mat[i][j] == 0:
        return 0
    # marking visited at i, j
    visited[i][j] = True
    # cnt is initialized to 1 coz 1 is found
    cnt = 1
    # now go in all possible directions (i.e. form 8 branches)
    # starting from the left upper corner of i,j and going down to right bottom
    # corner of i,j
    for r in xrange(i-1, i+2, 1):
        for c in xrange(j-1, j+2, 1):
            # don't call for i, j
            if (r, c) != (i, j):
                cnt += count_houses(mat, visited, r, c)
    return cnt


def island_count(mat):
    houses = list()
    clusters = 0
    row = len(mat)
    col = len(mat[0])
    # initialize the visited matrix
    visited = [[False for i in xrange(col)] for j in xrange(row)]
    # run over matrix, search for 1 and then do dfs when found 1
    for i in xrange(row):
        for j in xrange(col):
            # see if value at i, j is 1 in mat and val at i, j is False in
            # visited
            if mat[i][j] == 1 and visited[i][j] is False:
                clusters += 1
                h = count_houses(mat, visited, i, j)
                houses.append(h)
    print 'clusters:', clusters
    return houses


if __name__ == '__main__':
    mat = [
        [1, 1, 0, 0, 0],
        [0, 1, 0, 0, 1],
        [1, 0, 0, 1, 1],
        [0, 0, 0, 0, 0],
        [1, 0, 1, 0, 1]
    ]
    houses = island_count(mat)
    print houses
    print 'maximum houses:', max(houses)


# time = O(row*col)
# space = O(row*col)
