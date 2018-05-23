# n is number of dice, lis is solution vector
def dice_sum_helper(n, lis, desired_sum, sum_so_far):
    if n == 0:
        print lis
    else:
        for i in xrange(1, 7):
            if sum_so_far + i + 1*(n - 1) <= desired_sum and\
                    sum_so_far + i + 6*(n - 1) >= desired_sum:
                # choose
                lis.append(i)
                dice_sum_helper(n-1, lis, desired_sum, sum_so_far + i)
                lis.pop()  # removing from last


def dice_sum(number_of_dice, required_sum):
    dice_sum_helper(number_of_dice, [], required_sum, 0)


if __name__ == '__main__':
    num = int(raw_input('Enter number of dices you wish to throw: '))
    desired_sum = int(raw_input('Enter the desired sum: '))
    dice_sum(num, desired_sum)
