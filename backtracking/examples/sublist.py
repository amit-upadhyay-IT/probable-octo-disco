def sublist_helper(lis, prefix, ind):
    if ind == len(lis):
        print prefix
    else:
        prefix.append(lis[ind])
        sublist_helper(lis, prefix, ind+1)
        prefix.pop()
        sublist_helper(lis, prefix, ind+1)


def sublist(lis):
    sublist_helper(lis, list(), 0)


if __name__ == '__main__':
    s = raw_input('Enter a space separated list:\n').split()
    print len(s)
    sublist(s)
