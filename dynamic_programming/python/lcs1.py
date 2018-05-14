'''
lcs: bruteforce approach, i.e. get all subsequences of sequence 1, then
see one by one from the subsequences that if that is present in subseqence 2
Time = O(n*2^m)
'''


def get_subseq(sequence, prefix, subsequence_list, ind):
    # base case
    if ind >= len(sequence):
        subsequence_list.append(prefix)
    else:
        # open two branches
        get_subseq(sequence, prefix+sequence[ind], subsequence_list, ind+1)
        get_subseq(sequence, prefix, subsequence_list, ind+1)


def subsequence_check(str1, str2):
    i, j = 0, 0
    # i is index pointer for str1 and j is for str2
    # until j is less than i perform the comparision
    while j < len(str2) and i < len(str1):
        if str1[i] == str2[j]:
            j += 1
        i += 1
    return j == len(str2)


def get_max_length_ss(subsequence_list, sequence):
    # ans = []
    maxlen = 0
    # for each element in subsequence_list check for its presence in sequence
    for val in subsequence_list:
        ret = subsequence_check(sequence, val)
        # print val, sequence, ret
        if ret is True:
            if len(val) >= maxlen:
                maxlen = len(val)
                # ans.append(val)
    return maxlen


if __name__ == '__main__':
    sequence1 = raw_input('Enter sequence 1:')
    sequence2 = raw_input('Enter sequence 2:')
    subsequence_list1 = []
    get_subseq(sequence1, '', subsequence_list1, 0)
    print get_max_length_ss(subsequence_list1, sequence2)

# space used is O(2^n) for storing the subsequences but is can be removed also
