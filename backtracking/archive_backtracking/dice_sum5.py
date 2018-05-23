def possible_ways(n):
    # sol stores the number of possible ways to acheive sum equal to index
    sol = [0]*1000000
    sol[0], sol[1] = 1, 1
    for i in xrange(2, n+1):
        for j in xrange(1, 7):
            if i - j >= 0:
                sol[i] += sol[i-j]
    return sol[n]


if __name__ == '__main__':
    n = input('enter n:\n')
    print possible_ways(n)
