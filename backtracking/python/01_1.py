from __future__ import print_function


def indent(n):
    for i in range(n):
        print ('    ', end='')


def permute(s, first, last):
    indent(first)
    print ('permute('+str(s)+','+str(first)+','+str(last)+')')
    if first == last:
        print (s)
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
    a = raw_input('enter a string:\n')
    permute(a, 0, len(a)-1)
