# lcs: recursion solution without memoization


def solve_recurrence(seq1, seq2, i, j):
    # base case: my check point is -1 because I am starting from length-1
    if i == -1 or j == -1:
        return 0
    elif seq1[i] == seq2[j]:
        return 1 + solve_recurrence(seq1, seq2, i-1, j-1)
    else:
        option1 = solve_recurrence(seq1, seq2, i-1, j)
        option2 = solve_recurrence(seq1, seq2, i, j-1)
        return max(option1, option2)


if __name__ == '__main__':
    seq1 = raw_input('Enter first sequence:')
    seq2 = raw_input('Enter second sequence:')
    print solve_recurrence(seq1, seq2, len(seq1)-1, len(seq2)-1)

# time = O(2^(m+n)), where m+n is the height of the recursion tree formed
# due to the function call stack in worst case.
# space = O(m+n), as in worst case this will be the depth of the tree
