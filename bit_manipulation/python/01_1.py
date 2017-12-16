def isSet(num, k):
    return num & (1 << k)


inp = raw_input('enter the number and kth bit separated by commas:')

nums = inp.split(',')

if (isSet(int(nums[0]), int(nums[1]))):
    print('The Kth bit is set')
else:
    print('The Kth bit is clear')

# time complexity = O(logn)
