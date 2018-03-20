'''
write a recursive function dice_roll that accepts an integer representing a
number of 6-sided dice to roll, and output all the possible combinations of
values that could appear on the dice.
'''


def dice_roll(n, prefix):
    # base case, i.e. n goes down to 0
    if n == 0:
        print prefix.rstrip(',')  # for stripping out the righmost ,
    else:
        # call the same function 6 times with each possible value of prefix
        for i in range(1, 7):
            dice_roll(n-1, prefix + str(i) + ',')


def dice_roll2(n, lis):
    if n == 0:
        print lis
    else:
        for i in xrange(1, 7):
            # choose
            lis.append(i)
            dice_roll2(n-1, lis)
            lis.pop()  # removing from last


if __name__ == '__main__':
    dice_roll(2, '')
    print '-------------------'
    dice_roll2(2, [])
