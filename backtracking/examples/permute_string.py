def permute_helper(s, prefix):
    if len(s) == 0:
        print prefix
    else:
        for i in xrange(len(s)):
            permute_helper(s[:i]+s[i+1:], prefix+s[i])


def permute(s):
    print '\nPermutations are:'
    permute_helper(s, '')


if __name__ == '__main__':
    s = raw_input('enter string: \n')
    permute(s)
