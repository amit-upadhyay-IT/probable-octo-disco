'''
recursive program for getting lcs, here I am not using for loop to form
n different branches
'''


def find_lcs(b):
    # base case
    if len(b) == 1:
        return 1
    # checking if last element is greater than the second last element, if yes
    # then adding one to the obtained lcs, else somply calling the find_lcs
    if len(b) > 1 and b[-1] > b[-2]:
        return find_lcs(b[:-1]) + 1
    else:
        return find_lcs(b[:-1])


if __name__ == '__main__':
    print find_lcs([2, 3, 1, 5, 12, 10, 11])
