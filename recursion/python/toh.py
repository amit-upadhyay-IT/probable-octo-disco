'''
tower of hanio
'''


def toh(n, x, y, z):  # moving n disk from x to y using z
    if n >= 1:
        toh(n-1, x, z, y)
        print 'moving disk from', x, 'to', y, 'using', z, '\n'
        toh(n-1, z, y, x)


if __name__ == '__main__':
    n = 3
    toh(n, 'a', 'b', 'c')
