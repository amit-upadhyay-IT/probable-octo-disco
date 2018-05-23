cnt = 0


def possible_ways_helper(lis, desired_sum, sum_so_far, ways):
    if desired_sum == sum_so_far:
        ways[0] += 1
        # print lis
    else:
        for i in xrange(1, 7):
            if sum_so_far < desired_sum:
                lis.append(i)
                possible_ways_helper(lis, desired_sum, sum_so_far + i, ways)
                lis.pop()  # removing from last


def possible_ways(n):
    ways = [0]
    possible_ways_helper([], n, 0, ways)
    return ways[0]


if __name__ == '__main__':
    print possible_ways(8)
