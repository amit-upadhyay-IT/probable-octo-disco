from __future__ import print_function


def indent(n):
    for i in range(n):
        print ('    ', end='')


# don't take care of the fact that if letters repeate in the input string
# then multiple permutation will repeat in the output
# To solve this casually you can use a set and see if set already contains
# that combination or not. If it is already present then don't print
# However, the optimized approach would be not exploring those cases when
# there is repeat in the permutation
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
