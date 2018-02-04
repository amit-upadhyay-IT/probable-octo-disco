def decimal_to_binary(n):
    # check for negative numbers
    if n < 0:
        print '-',
        # since, I am recusive, so call me
        decimal_to_binary(-n)
    elif n < 2:
        # coz, these number has the same binary representation as the decimal
        print n,
    else:
        decimal_to_binary(n/2)
        print n % 2,  # backtracking here as we print in reverse order


if __name__ == '__main__':
    decimal_to_binary(43)
    print
    decimal_to_binary(-43)
