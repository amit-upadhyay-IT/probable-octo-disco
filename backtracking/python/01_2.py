from __future__ import print_function


def permute(prefix, suffix, permutation_set):
    # base case
    if len(suffix) == 0:
        permutation_set.add(prefix)
    else:
        # here, recursively call this function on all of the possible prefixes
        # with one of the character and suffix list appended to them
        for i in xrange(0, len(suffix)):
            permute(prefix+suffix[i], suffix[0:i]+suffix[i+1:len(suffix)],
                    permutation_set)


if __name__ == '__main__':
    s = raw_input('enter a string:\n')
    permutation_set = set()
    permute('', s, permutation_set)
    print (permutation_set)
