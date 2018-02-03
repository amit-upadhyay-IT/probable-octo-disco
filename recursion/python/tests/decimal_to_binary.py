def decimal_to_binary(n):
    if n == 1:
        print 1,
    else:
        if n & 1:
            decimal_to_binary(n/2)
            print 1,  # backtracking here as we print in reverse order
        else:
            decimal_to_binary(n/2)
            print 0,  # backtracking


if __name__ == '__main__':
    decimal_to_binary(43)
