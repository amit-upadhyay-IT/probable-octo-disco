def print_permutations(s, start):
    # base case, i.e. s length goes down to zero
    if len(s) == start:
        print s
    else:
        # call the same function for the different set of chars in s
        for i in range(len(s)):
            s[i], s[start] = s[start], s[i]
            print_permutations(s, start+1)
            s[i], s[start] = s[start], s[i]


if __name__ == '__main__':
    s = 'abcd'
    s = list(s)
    print_permutations(s, 0)
