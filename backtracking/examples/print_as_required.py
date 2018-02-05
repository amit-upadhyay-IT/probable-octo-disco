'''
write a code to generate all possible combinations like this:

    '0ab' -> '0ab', '0aB', '0Ab', '0AB'
'''


def indent(n):
    for i in range(n):
        print '    ',


def print_as_required(prefix, s, i, l):
    # indent(i)
    # print 'print_as_required(', prefix, ',', s, ',', i, ',', l, ')'
    if i == l:
        print prefix
    else:
        # we know that we need to make two branches one for lowercase
        # and other for uppercase, also we need to take care of the string
        # length, so for that I have used i as an argument in the function
        # which will get incremented in each call of the function, 'l' is
        # just used for the base case (i.e. when i becomes l).

        # I need to make sure that the chars which are digit has to be appended
        # to the prefix and these should not be considered for branching, so
        # I have used the while loop below
        while s[i].isdigit():
            prefix = prefix + s[i]
            i += 1
        if not s[i].isdigit():  # if found a alphabet then make two branches
            print_as_required(prefix + s[i].lower(), s, i+1, l)
            print_as_required(prefix + s[i].upper(), s, i+1, l)


if __name__ == '__main__':
    s = '0ab'
    print_as_required('', s, 0, len(s))
    s = '0a123b4525c'
    print_as_required('', s, 0, len(s))
