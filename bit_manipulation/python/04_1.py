def toggleBit(num, k):
    return num ^ (1 << k)


inp = raw_input('enter the number and kth bit separated by commas:')

nums = inp.split(',')

print 'number after toggling kth bit is', toggleBit(int(nums[0]), int(nums[1]))

# time complexity = O(logn)
