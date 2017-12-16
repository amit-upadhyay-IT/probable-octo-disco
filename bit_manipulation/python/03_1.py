def setBit(num, k):
    return num & ~(1 << k)


inp = raw_input('enter the number and kth bit separated by commas:')

nums = inp.split(',')

print 'the number after clearing kth bit is', setBit(int(nums[0]), int(nums[1]))

# time complexity = O(logn)
