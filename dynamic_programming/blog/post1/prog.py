def indent(n):
    for i in range(n):
        print '   ',


def F(n, dp, rec_cnt):
    indent(rec_cnt)
    print 'F('+str(n)+')'
    result = -1
    # base case
    if n == 0:
        dp.append(1)  # putting dp[0] = 1, as its the base case, 2^0=1
        return 1
    else:
        for i in xrange(n):
            # check if dp array has already that index value computed or not
            if i < len(dp):
                result += dp[i]
            else:
                result += F(i, dp, rec_cnt+1)
        dp.append(result+n)
        return result+n


if __name__ == '__main__':
    n = int(raw_input())
    import time
    start_time = time.time()
    print F(n, [], 0)
    print '\n', (time.time()-start_time)
