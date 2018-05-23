import random


# count consequitive ones
def count_people_helper(li, ind):
    # base case: when we found that next number if zero
    if li[ind] == 0:
        return 0
    else:
        # val = count_it(li, ind+1)
        # val = val + 1  # backtracking
        # return val  # backtracking
        return 1 + count_people_helper(li, ind+1)


def count_people(li):
    return count_people_helper(li, 0)


if __name__ == '__main__':
    n = random.randint(3, 66)
    li = [0]*2*n
    li[0:n] = [1]*n  # 1 represents the people in the row, among 2n capacities
    if n == count_people(li):
        print 'success'
    else:
        print 'its not possible'
