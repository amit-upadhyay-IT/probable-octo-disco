# calculates x^y
def power2(x, y):
    if y == 0:
        return 1
    else:
        ret = power(x, y-1)
        ret = ret * x  # backtracking
        return ret  # backtracking
        # return x * power(x, y-1)


def power(x, y):
    if y == 0:
        return 1
    elif y & 1:  # i.e. odd
        return x * power(x, y-1)
    else:  # even power
        return power(x, y/2) * power(x, y/2)


if __name__ == '__main__':
    print power(2, 3)
