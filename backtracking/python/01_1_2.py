cnt = 0


def print_permutations(s, start, end):
    global cnt
    # base case, i.e. both start and end matches
    if start == end:
        cnt += 1
        print s
    else:
        # call the same function for the different set of chars in s
        for i in range(start, end+1):
            s[i], s[start] = s[start], s[i]
            print_permutations(s, start+1, end)
            s[i], s[start] = s[start], s[i]


if __name__ == '__main__':
    s = 'abcd'
    s = list(s)
    print_permutations(s, 0, len(s)-1)
    print
    print cnt
