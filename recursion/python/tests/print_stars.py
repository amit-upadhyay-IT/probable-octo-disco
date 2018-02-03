def print_stars(n):
    # base case, n is 1
    if n == 1:
        print '*',
        return
    print '*',
    print_stars(n-1)


if __name__ == '__main__':
    print_stars(10)
