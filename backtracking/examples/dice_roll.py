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


if __name__ == '__main__':
    dice_roll(6, '')
