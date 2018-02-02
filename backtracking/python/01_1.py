def permute(s, first, last):
    if first == last:
        print s
    else:
        for i in range(first, last+1):
            # swap to get new permutation
            s = list(s)
            s[first], s[i] = s[i], s[first]
            s = ''.join(s)
            permute(s, first+1, last)
            # un-do the swapping
            s = list(s)
            s[first], s[i] = s[i], s[first]
            s = ''.join(s)


if __name__ == '__main__':
    a = 'abc'
    permute(a, 0, len(a)-1)
