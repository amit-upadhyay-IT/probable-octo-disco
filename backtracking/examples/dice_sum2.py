# n is number of dice, lis is solution vector
def dice_roll2(n, lis, desired_sum, sum_so_far):
    if n == 0:
        print lis
    else:
        for i in xrange(1, 7):
            if sum_so_far + i + 1*(n - 1) <= desired_sum and\
                    sum_so_far + i + 6*(n - 1) >= desired_sum:
                # choose
                lis.append(i)
                dice_roll2(n-1, lis, desired_sum, sum_so_far + i)
                lis.pop()  # removing from last


cnt = 0


def dice_roll3(lis, desired_sum, sum_so_far):
    if desired_sum == sum_so_far:
        global cnt
        cnt += 1
        # print lis
    else:
        for i in xrange(1, 7):
            if sum_so_far < desired_sum:
                lis.append(i)
                dice_roll3(lis, desired_sum, sum_so_far + i)
                lis.pop()  # removing from last


if __name__ == '__main__':
    dice_roll3([], 8, 0)
    print cnt