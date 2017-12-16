def insertMinN(n, m, i, j):
    # create a masking bit where all bits are 1 except
    # bits from j to i(both inclusive)

    allOnes = ~0  # sequence of all 1's

    # left shift upto j times so that all bits upto j can be filled with 0
    num1 = allOnes << (j+1)
    # logical right shift allOnes upto 31-i
    # num2 = allOnes >>> (31 - i)
    # we could also have done i times left shift to 1, then subtracted 1
    num2 = (1 << i) - 1

    # producing the number which has all ones but zero from j to i
    num = num1 | num2

    # modifying n
    n_cleared = n & num

    # getting m to its right position, i.e. from j to i
    m_shifted = m << i

    return n_cleared | m_shifted


# print insertMinN(int('10000000000', 2), int('10011', 2), 2, 6)

print insertMinN(1024, 19, 2, 6)
