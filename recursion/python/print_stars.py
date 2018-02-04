def print_stars(n):
    # base case, n is 1
    if n == 1:
        print '*',
        return
    print '*',
    print_stars(n-1)


def print_s(n):
    print '*',
    if n > 1:
        print_s(n-1)


if __name__ == '__main__':
    print_s(10)
    print
    print_stars(10)
