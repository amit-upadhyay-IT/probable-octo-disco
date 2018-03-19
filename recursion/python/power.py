# calculates x^y
# time = O(n), space = O(n)


def power2(x, y):
    if y == 0:
        return 1
    else:
        ret = power2(x, y-1)
        ret = ret * x  # backtracking
        return ret  # backtracking
        # return x * power(x, y-1)


# time = O(n)
def power(x, y):
    if y == 0:
        return 1
    elif y & 1:  # i.e. odd
        return x * power(x, y-1)
    else:  # even power
        return power(x, y/2) * power(x, y/2)


# time = O(log2(n))
def power_optimized(x, y):
    if y == 0:
        return 1
    p = power_optimized(x, y/2)
    if y & 1:  # i.e. odd
        return x * p * p
    else:
        return p * p


if __name__ == '__main__':
    print power(2, 3)
    print power_optimized(6, 7)
