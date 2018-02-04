'''
write a recursive function print_decimal that accepts an integer number of
digits and prints all binary number that have exactly that many digits
'''


def indent(n):
    for i in xrange(n):
        print '    ',


def print_decimal(n, prefix):
    # indent(len(prefix))  # indentation purpose i.e. for better understanding
    # printing the call stack
    # print 'print_decimal(', n, ',', prefix, ')'
    # base case, when n becomes 0 i.e. prefix will have length = actual n
    if n == 0:
        print prefix
    else:
        # form the ten branches of the tree, i.e one for 0 and other for 1
        for i in range(10):
            print_decimal(n-1, prefix + str(i))


if __name__ == '__main__':
    print_decimal(5, '')
