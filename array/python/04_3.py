def getMaxDiff(li):
    prev_min = li[0]
    max_diff = 0
    for i in li:
        curr_dif = i - prev_min

        if i < prev_min:
            prev_min = i

        if curr_dif > max_diff:
            max_diff = curr_dif

    return max_diff


print getMaxDiff([4, 3, 10, 2, 9, 1, 6])

# time is linear with no extra space
