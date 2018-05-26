def nbits_helper(n, prefix):
    if n == 0:
        print prefix
    else:
        nbits_helper(n-1, prefix+str(0))
        nbits_helper(n-1, prefix+str(1))


def nbits_string(n):
    nbits_helper(n, '')


if __name__ == '__main__':
    n = int(raw_input('Enter n:\n'))
    nbits_string(n)
