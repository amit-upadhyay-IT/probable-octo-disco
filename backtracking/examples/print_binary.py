'''
write a recursive function print_binary that accepts an integer number of
digits and prints all binary number that have exactly that many digits

suppose, n = 3

                      3
                   /     \
                  0       1
                 / \     / \
                0   1   0   1
               / \ / \ / \ / \
              0  1 0 1 0 1 0 1

So, if you see the tree above, the possiblities are:
    000
    001
    010
    011
    100
    101
    110
    111
'''


def print_binary(n, prefix):
    # base case, when n becomes 0 i.e. prefix will have length = actual n
    if n == 0:
        print prefix
    else:
        # form the two branches of the tree, i.e one for 0 and other for 1
        print_binary(n-1, prefix + '0')
        print_binary(n-1, prefix + '1')


if __name__ == '__main__':
    print_binary(3, '')
